// conpartner.c
// 辅助修改文件名字

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    string *files;
    int i;
    int size;
    set_eval_limit(1); 
    seteuid(getuid());
    
    return notify_fail("
此命令用于转换相对坐标，破坏性极大，
风云4.0已完成此项工作，如果需要使用此命令请阅读修改此文件后执行。\n");

    
    if(!arg || arg=="") return notify_fail("格式不对！\n");
    
    files= get_dir(arg);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-2)..size]==".c")
        {
            rm(arg+files[i]);
        }
    }
    files= get_dir(arg);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-4)..size]==".cto")
        {
            rename(arg+files[i],arg+files[i][0..size-3]);
        }
    }
    return 1;
}
