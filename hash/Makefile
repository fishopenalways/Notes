# 定义编译器和编译器选项
CC = gcc
CFLAGS = -Wall -g -fPIC

# 生成动态库名和目标位置
SHARED_LIB = libhash.so

# 定义源文件和目标文件
SRCS = hash.c
OBJS = $(SRCS:.c=.o)

# 默认目标，当只运行 `make` 时执行
all: $(SHARED_LIB)

# 链接生成动态库
$(SHARED_LIB): $(OBJS)
	$(CC) -shared -o $(SHARED_LIB) $(OBJS)

# 编译各个目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(SHARED_LIB)

# 声明伪目标
.PHONY: all clean