#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define MAX_SIZE_BUFFER 1024

#define ERR_EXIT(m)\
do{\
    perror("m");\
    exit(1);\
}while(0)

#define PRINT_CMD 100
#define PRINT_PID 101

typedef struct msg{
    int sockfd_child;
    int sockfd_parent;
    int cmd;
    char *buffer;
}RW_msg;
//socket pair 的使用和消息队列的使用
//使用socket来分工处理读写操作
//父进程
//问题：
/*
 *1.两个套接字不能通过一个buffer传输数据
 *2.两个套接字只能一个用来读一个用来写，要是同时用一个套接口读或者写，那莫第二次使用的将阻塞
 *3.结构体字符串需要分配空间
 */
int ResolveCmd(RW_msg *sess, char *argv[])
{
    int cmd_num = atoi(argv[1]);
    sess->cmd = cmd_num;
    
    switch(sess->cmd)
    {
        case PRINT_CMD: 
            {
                printf("print_cmd\n");
            char *string = argv[1];
            int ret1 = write(sess->sockfd_parent, string, sizeof(string));
            if(ret1 < 0)
                ERR_EXIT(send);
            break;

            }
        case PRINT_PID:
            {
                printf("print_pid\n");
            int pid = getpid();
            int ret2 = write(sess->sockfd_parent, &pid, sizeof(pid));
            if(ret2 < 0)
                ERR_EXIT(send);
            break;
            }
        default: 
            printf("input string error\n");
            break;
    }
    return 0;
}

void DealCmd(RW_msg *sess)
{
    read(sess->sockfd_child, sess->buffer, sizeof(sess->buffer));
    printf("I am child process: %s", sess->buffer);
}
int main(int argc, char **argv)
{
    if(argc < 2){
        printf("[usage]: input cmd\n");
        exit(1);
    }
    RW_msg session;
    session.buffer = (char *)malloc(sizeof(char) * MAX_SIZE_BUFFER);
    int socketfds[2];
    if(socketpair(AF_UNIX, SOCK_STREAM, 0, socketfds) < 0){
        printf("1\n");
        ERR_EXIT(socketpair);
    }

    int pid;
    pid = fork();

    if(pid > 0){
        printf("parent:\n");
        close(socketfds[1]);
        session.sockfd_parent = socketfds[0];
        int ret = ResolveCmd(&session, argv);
        if(ret != 0)
            ERR_EXIT(ResolveCmd);
    }
    else if(pid == 0){
        printf("child:\n");
        close(socketfds[0]);
        session.sockfd_child = socketfds[1];
        DealCmd(&session);
    }
    else
        ERR_EXIT(fork);

    wait(0);
    return 0;
}
