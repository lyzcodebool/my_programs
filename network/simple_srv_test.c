#include "common.h"

void signal_handle(int signo){
    pid_t pid;
    int stat;
    while((pid = waitpid(-1, &stat, WNOHANG)) > 0){
        printf("child %d terminated \n", pid);
    }

    return;
}
struct sockaddr_in srvaddr;

char recvbuff[BUFF_SIZE];
char sendbuff[BUFF_SIZE];

int socket_creat(int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
        ERR_RETURN("socket");

    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr)) < 0)
        ERR_RETURN("bind");
    
    if(listen(sockfd, 5) < 0)
        ERR_RETURN("listen");
    
    return sockfd;
}

void *write_task(void *arg)
{
    int conn = *(int *)arg;
    while(1){
        memset(&recvbuff, 0, sizeof(recvbuff));
        int read_n = read(conn, recvbuff, sizeof(recvbuff));
        if(read_n == 0){
            if(errno == EINTR){
                printf("client stop!\n");
                close(conn);
                break;
            }
        }else if(read_n < 0){
            ERR_EXIT("read");
        }else{
            write(STDOUT_FILENO, recvbuff, sizeof(recvbuff));
            write(conn, recvbuff, sizeof(recvbuff));
            break;
        }
    }

    return (void*)0;
}

int main(int argc, char *argv[])
{
    signal(SIGCHLD, signal_handle);
    if(argc < 2){
        printf("usage: %s<port>\n", argv[1]);
    }
    int conn;
    int listenfd = socket_creat(atoi(argv[1]));
    while(1){
        socklen_t sock_len = sizeof(struct sockaddr);
        if((conn = accept(listenfd, (struct sockaddr*)&srvaddr, &sock_len)) < 0)
            ERR_EXIT("accept"); 
        for(int i = 0; i < 10; ++i){
            pthread_t tid;
            int ret = pthread_create(&tid, NULL, write_task, (void*)&conn);
            if(ret == -1)
                ERR_EXIT("pthread_create");
            pthread_join(tid, NULL);
        }
    }
    /* while(1){ */
    /*     pthread_t tid; */
    /*     int ret = pthread_create(&tid, NULL, write_task, (void*)&conn); */
    /*     if(ret == -1) */
    /*         ERR_EXIT("pthread_create"); */
    /*     pthread_join(tid, NULL); */
    /*     break; */
    /* } */

    return 0;
}

