Usock
libubox-2017-02-24-96305a3c
usock.c

函数原型：

`int usock(int type, const char *host, const char *service)`

lib对外提供的函数入口<br>
type使用：查看usock.h宏定义<br>
USOCK_TCP USOCK_UDP<br>
USOCK_SERVER USOCK_NOCLOEXEC USOCK_NONBLOCK USOCK_NUMERIC USOCK_IPV6ONLY USOCK_IPV4ONLY USOCK_UNIX

`static int usock_unix(int type, const char *host)`<br>
sockaddr_un结构体赋值<br>
host的检查，不能超过sockaddr_un结构体中sun_path成员定义的长度<br>
`bool server = !!(type & USOCK_SERVER)`两个感叹号保证server为1或者0<br>
`int socktype = ((type & 0xff) == USOCK_TCP) ? SOCK_STREAM: SOCK_DGRAM;`只看低8位即可确定是TCP还是UDP<br>

`static int usock_connect(int type, struct sockaddr *sa, int sa_len, int family, int socktype, bool server)`<br>
创建socket<br>
通过fcntl函数设置fd标记`static void usock_set_flags(int sock, unsigned int type)`<br>
如果type没有选择USOCK_NOCLOEXEC，则通过F_SETFD将fd设置标记FD_CLOEXEC（当有exec系列函数执行时，该fd会被关掉而不是被继承，防止fd泄露）<br>
如果type选择了USOCK_NONBLOCK，则通过F_SETFL将文件状态设置为O_NONBLOCK（非阻塞IO）<br>
如果选择了USOCK_SERVER，setsockopt函数设置套接字,bind函数绑定
如果没有选择USOCK_SERVER，connect指定地址。<br>
建立成功或者连接成功，返回socket，否则返回-1<br>

如果type标记了USOCK_UNIX<br>
usock --> usock_unix --> usock_connect --> usock_set_flags<br>

如果type没有标记USOCK_UNIX<br>
usock --> [inline]usock_inet --> usock_inet_timeout<br>

struct addrinfo（netdb.h中的结构体）
ai_family的赋值是?:的嵌套使用，避免繁琐的if-else结构<br>