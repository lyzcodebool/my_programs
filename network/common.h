#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>


#define ERR_EXIT(m)\
    do{\
        perror("m");\
        exit(1);\
    }while(0)

#define ERR_RETURN(m)\
    do{\
        perror("m");\
        return 0;\
    }while(0)

#define BUFF_SIZE 1024

#endif
