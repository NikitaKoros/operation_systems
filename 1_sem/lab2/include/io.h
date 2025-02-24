#ifndef IO_H
#define IO_H

#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 1024

ssize_t read_input(int, char *, size_t);
ssize_t read_from_stdin(char *, size_t);
ssize_t write_to_file(int, const char *);
void print_to_stdout(const char *);

#endif