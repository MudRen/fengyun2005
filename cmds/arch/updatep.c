// updatep.c
// 辅助编译一个目录下的.c文件

#include <ansi.h>
inherit F_CLEAN_UP;

int error;

int update_function(object me, string file);

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	int i,total=0;
    	int size;
    	set_eval_limit(1); 
    	seteuid(getuid());
    	if(!arg || arg=="") return notify_fail("格式不对！\n");
    
    	error = 0;
    	
    	write(HIW"正在梭巡"+arg+"文档夹．．．\n"NOR);
    	
    	files= get_dir(arg);
    	reset_eval_cost();
    	for(i=0; i<sizeof(files); i++) 
    	{
    	    size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c"){
        		if (files[i]=="updatep.c") continue;
        		total++;
				update_function(me, arg+files[i]);
			}	
//  	           	me->ccommand(sprintf("update %s%s",arg,files[i]));
        }   
        
        write(HIW"．．．"+arg+"文档夹编译完成。
　　　共梭巡到"+total+"个档案，其中"+error+"个编译失败。\n"NOR);	 	
    	return 1;
}

int update_function(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要重新编译什麽档案？\n");

		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%*s.c") ) file += ".c"; 

        if( file_size(file)==-1 )
                return notify_fail("没有这个档案。\n");

        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) return notify_fail("无法清除旧程式码。\n");

    	write("重新编译 " + file + "：");
        err = catch( call_other(file, "???") );
        if (err)
		{
			error++;
                printf( "发生错误：\n%s\n", err );
			}
        else {
                write("成功！\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)
%s updated %s\n", ctime(time()), me->query("name"), file));
        
        	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        	if( inv[i] && userp(inv[i]) ) 
					inv[i]->move(obj, 1);
                }
        }
                
        return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	updatep 目录名	[0m
[0;1;37m────────────────────────────────[0m   

updatep /d/baiyun/	就是编译所有/d/baiyun/目录下的文件。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
