#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
    
    int filedescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (filedescriptor < 0)
    {
        printf("The open operation failed..\n");
        return filedescriptor;
    }
    else
    {
        printf("The open operation was successful\n");
    }

    int writertn = write(filedescriptor, "Writing test data to the file\n", 30);

    if (writertn != 30)
    {
        printf("The write operation failed..\n");
        return -1;
    }
    else
    {
        printf("The write operation was successful\n");
    }

    // closing the file
    close(filedescriptor);

    return 0;
}