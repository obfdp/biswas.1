CC = gcc
CFLAGS = -g
TARGET = driver
OBJS = driver.o loglib.o

$(TARGET): $(OBJS)
	$(CC)-o $(TARGET) $(OBJS)

loglib.o : loglib.c
	$(CC) $(CFLAGS) -c loglib.c

driver.o : driver.c
	$(CC) $(CFLAGS) -c driver.c


clean: 
	rm driver.o
	rm loglib.o




