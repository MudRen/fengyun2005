// 整理一下 log files

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
    	string *files;
    	int i, num;
    	int size;
	    	
    	seteuid(ROOT_UID);	
    	files= get_dir(LOG_DIR);
    	for(i=0; i<sizeof(files); i++) 
    	{
    	        if (sscanf(files[i],arg+".%d",num)==1)
    			rename(LOG_DIR+files[i],LOG_DIR+"backup/"+files[i]);        
        }   	 	
        seteuid(geteuid());
    	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	backup_log[0m
[0;1;37m────────────────────────────────[0m   

把一些log文件放到backup目录里去。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
