#include <stdio.h>
#include <unistd.h> // contails all syscall wrapper functions we need
#include <fcntl.h>  // contains file control functions
#include <sys/stat.h>   // needed to include this header file for S_IRWXU macro.

int main(void)
{
    int file_descriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (file_descriptor < 0)
    {
        printf("Error: The open operation failed.\n");
        return file_descriptor;
    }
    else
    {
        printf("The open operation succeeded!\n");
    }
    return 0;
}
