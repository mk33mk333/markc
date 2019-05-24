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
void markc_set_file_path(char* filepath){
    printf("xxxxxxxxx\n");
}

void read_file(){
    fp = fopen(filepath,"rb");
    
    

}

