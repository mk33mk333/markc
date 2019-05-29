// 解析并上传文件
#include "uploader.h"
#include "common.h"
#include <fcntl.h>
#include <sys/stat.h> 
#include <sys/io.h>
char* filepath;
FILE* fp;
int fd;
struct stat st;


static void read_file(){
    fp = fopen(filepath,"rb");
    // 现在的问题，需要在读取文件之前就知道文件的长度
    #ifdef	__USE_POSIX
        printf("***********");
    #endif
    fd = fileno(fp);
    // printf("==%d\n",fd);    
}


void markc_set_file_path(char* filepath){
    printf("xxxxxxxxx\n");
}

void markc_upload_file(){
    read_file();

}
