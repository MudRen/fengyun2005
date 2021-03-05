#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	string wiz_status;
    	int i;
    	int size;
    	set_eval_limit(1); 
    	seteuid(getuid());

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" )
		return notify_fail("只有admin才能使用此命令。\n");
		
		
    	if(!arg || arg=="") return notify_fail("格式不对！\n");
    
    
    	files= get_dir(arg);
    	reset_eval_cost();
    	for(i=0; i<sizeof(files); i++) 
    	{
    	        size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c")
  	               	me->ccommand(sprintf("rm %s%s",arg,files[i]));
        }   	 	
    	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	updatep 目录名	[0m
[0;1;37m────────────────────────────────[0m   

		慎用		慎用
		
rmpartner /d/baiyun/	就是删除所有/d/baiyun/目录下的文件。


[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}