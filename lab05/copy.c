#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int copy(const char *source_file, const char *target_file);

int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s <source_filename> <target_filename>\n", argv[0]);
        return 1;
    }
    
    return copy(argv[1], argv[2]);
}

int copy(const char *source_file, const char *target_file){
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    ssize_t bytes_written;
    
    int fd_source = open(source_file, O_RDONLY);
    if(fd_source == -1){
        perror("Open Source");
        return 1;
    }
    
    int fd_target = open(target_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_target == -1){
        perror("Open Target");
        close(fd_source);
        return 1;
    }
    
    while((bytes_read = read(fd_source, buffer, sizeof(buffer))) > 0){
        bytes_written = write(fd_target, buffer, bytes_read);
        if(bytes_written == -1){
            perror("Write");
            close(fd_source);
            close(fd_target);
            return 1;
        }
        printf("%ld Bytes Written...\n", bytes_written);
    }
    
    if(close(fd_source) == -1){
        perror("Close Source");
        return 1;
    }
    
    if(close(fd_target) == -1){
        perror("Close Target");
        return 1;
    }
    
    return 0;
}
