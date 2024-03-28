CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LIBS = -lm
SRCS = main.c APIG24.c 
OBJS = $(SRCS:.c=.o)

DEPS = EstructuraGrafo24.h APIG24.h 


TARGET = grafo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(TARGET) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)