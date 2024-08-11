DEBUG = -ggdb
CC = gcc
CFLAGS = -o

edit: edit.c
	$(CC) $(DEBUG) $@.c -o $@
