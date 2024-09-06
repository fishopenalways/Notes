# 定义编译器和编译器选项
CC = gcc
CFLAGS = -Wall -g

# 定义目标可执行文件
TARGET = my_program

# 动态库名和路径
SHARED_LIB = libhash.so

# 定义源文件和目标文件
SRCS = num.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./hash

# 默认目标，当只运行 `make` 时执行
all: $(TARGET)

# 链接生成目标可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIBDIR) -lhash

# 编译各个目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./hash

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 声明伪目标
.PHONY: all clean