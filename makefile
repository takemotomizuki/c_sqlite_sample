CC := gcc
CFLAGS := -g -Wall -Wextra -lsqlite3 -L/usr/lib64/ -I/usr/include/

sample: src/sample.c
	gcc -Wall -o sample.o src/sample.c -lsqlite3 -L/usr/lib64/ -I/usr/include/

clean:
	$(RM) sample.o