#ifndef __DEBUG_LOG_H_
#define __DEBUG_LOG_H_

#include <stdio.h>
#include <time.h>

#define DEBUG 1

#define LOGDEBUGVERSION "V0.0.1"
//#define MSG(args...)    fprintf(stderr, args)

//#define MSG(args...)    printf(args)

#define DEBUG_MSG(args...)   { do { if(DEBUG){printf(args);}	}while(0);}
#define DEBUG_MSG_LINE(args,...)   { do { if(DEBUG){fprintf(stdout, "[DEBUG][%s:%d] " args "",__FUNCTION__ , __LINE__, ##__VA_ARGS__);}	}while(0);}
#define ERROR_MSG(args...)   { do { if(DEBUG){fprintf(stderr,args);}	}while(0);}
//日志记录 打印出来时间信息

// time_t timep;
// struct tm *p;

#define print_log(fmt, args...) { time_t timep;struct tm *p;\
    do \
    { \
        if (DEBUG == 1 ) \
        { \
            time(&timep); \
            p=localtime(&timep); \
            fprintf(stdout, "[%4d-%02d-%02d %02d:%02d:%02d] FILE: %s, LINE: %d, FUNC: %s.     ", \
            (1900+p->tm_year), \
            (1+p->tm_mon), \
            p->tm_mday,  \
            p->tm_hour, \
            p->tm_min,  \
            p->tm_sec, \
            __FILE__, \
            __LINE__,  \
            __FUNCTION__); \
           fprintf(stdout, fmt"\n", ##args); \
        } \
    } \
    while(0); \
}


    


//打印正常日志信息
#define LOG_INFO(format, ...)                                                                           \
{                                                                                                       \
    time_t t = time(0);                                                                                 \
    struct tm ttt = *localtime(&t);                                                                     \
    fprintf(stdout, "[INFO] [%4d-%02d-%02d %02d:%02d:%02d] [%s:%d] " format "",                     \
            ttt.tm_year + 1900, ttt.tm_mon + 1, ttt.tm_mday, ttt.tm_hour,        \
            ttt.tm_min, ttt.tm_sec, __FUNCTION__ , __LINE__, ##__VA_ARGS__);                            \
}

//打印错误日志信息
#define LOG_ERR(format, ...)                                                                            \
{                                                                                                       \
    time_t t = time(0);                                                                                 \
    struct tm ttt = *localtime(&t);                                                                     \
    fprintf(stderr, "[ERROR] [%4d-%02d-%02d %02d:%02d:%02d] [%s:%d] " format "",                    \
            ttt.tm_year + 1900, ttt.tm_mon + 1, ttt.tm_mday, ttt.tm_hour,        \
            ttt.tm_min, ttt.tm_sec, __FUNCTION__ , __LINE__, ##__VA_ARGS__);                            \
}
//打印带颜色日志信息
#define LOG_ERR_RED(format, ...)                                                                            \
{                                                                                                       \
    time_t t = time(0);                                                                                 \
    struct tm ttt = *localtime(&t);                                                                     \
    fprintf(stderr, "\033[40;31m[ERROR] [%4d-%02d-%02d %02d:%02d:%02d] [%s:%d] " format "\033[0m\n",     \
            ttt.tm_year + 1900, ttt.tm_mon + 1, ttt.tm_mday, ttt.tm_hour,        \
            ttt.tm_min, ttt.tm_sec, __FUNCTION__ , __LINE__, ##__VA_ARGS__);                            \
}

//打印编译日期
#define LOG_COMPILE()  { do { if(DEBUG){printf("Compile Time: %s,%s\n",__DATE__,__TIME__);}	}while(0);}

void print_logo();
#endif