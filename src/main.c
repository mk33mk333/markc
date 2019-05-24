#include "common.h"
#include "commander.h"
#include "uploader.h"


static void file (command_t *self) {
    printf("设置file,%s\n",self->arg);
    char* array_str = malloc((strlen(self->arg)+1)*sizeof(char));
    strcpy(array_str,self->arg);
    // 如果文件名首尾是 ' 则要去掉
    markc_set_file_path(array_str);
}

int main(int argc,char** argv){
    command_t cmd; // commander主结构
    command_init(&cmd,argv[0],"0.0.1");
    command_option(&cmd, "-f", "--file <arg>", "文件路径", file);
    command_parse(&cmd, argc, argv);
    command_free(&cmd);
    return 0;
}