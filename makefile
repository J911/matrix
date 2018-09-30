CC = gcc
TARGET = test
SRCS = main.c matrix.c
OBJS = $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm *.o $(TARGET)