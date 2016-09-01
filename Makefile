CFLAGS=-Wall -g -O0

homework1:
	gcc $(CFLAGS) -o homework1 h1.c

clean:
	rm -rf homework1
