CC = gcc
CFLAGS = -g -Wall -std=gnu99
LDFLAGS = -lrt

all: oss worker

oss: oss.c
	$(CC) $(CFLAGS) -o oss oss.c $(LDFLAGS)

worker: worker.c
	$(CC) $(CFLAGS) -o worker worker.c $(LDFLAGS)

clean:
	rm -f oss worker *.o