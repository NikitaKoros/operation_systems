#ifndef IO
#define IO

#define BUFF_SIZE 100
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>

ssize_t read_input(int, std::string&);
ssize_t read_from_stdin(std::string&);
ssize_t write_to_file(int, const std::string&);
void print_to_stdout(const std::string&);
#endif