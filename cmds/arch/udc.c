// udc.c annie 07.2003
// dancing_faery@hotmail.com
// 编译一个CLASS下的一切文件
// 用"-o"来编译/DAEMON/SKILL与/DAEMON/CONDITION中的一切文件
// 一方面我们不需要silencer那样探究到每个directory的最底限；另一方面又要比updatep方便。

#include <ansi.h>
inherit F_CLEAN_UP;

int error;

int update_function(object me, string file);

int main(object me,string arg)
{
	string *files;
	mixed *file;
	int i,j,w=0,col,total=0;
	int size;
	set_eval_limit(1); 
	seteuid(getuid());
	if(!arg || arg=="") return notify_fail("格式不对！\n");

	error = 0;

	if (arg == "-o")
		arg = "/daemon/";
	else
		arg = "/daemon/class/"+arg+"/";
    
	file = get_dir(arg, -1);
   	reset_eval_cost();
	if( !sizeof(file) )
	{if (file_size(arg) == -2) return notify_fail("文档夹是空的。\n");
		else
		return notify_fail("没有这个文档夹。\n");
	}

	write(HIW"正在梭巡"+arg+"文档夹．．．\n"NOR);

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) 
		{
			files = get_dir(arg+file[i][0]+"/");
		   	reset_eval_cost();
			// 嗯，这个应该是对应的skill文档，一起编译吧
			update_function(me,"/daemon/skill/"+file[i][0]);
			// is a directory , 仅追溯一层。
			for(j=0; j<sizeof(files); j++) 
			{
				size=sizeof(files[j]);
				if(files[j][(size-2)..size]==".c")
				{
					update_function(me,arg+file[i][0]+"/"+files[j]);
					total++;
				}
			}   	 	
			file[i][0] += "/";
		}
	}
	write(HIW"．．．"+arg+"文档夹编译完成。\n　　　共梭巡到"+total+"个档案，其中"+error+"个编译失败。\n"NOR);

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
[0;1;37m─────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	udc [CLASS名] [-o]	[0m
[0;1;37m─────────────────────────────────[0m   

udc demon	编译所有/daemon/class/demon/下的文件与对应skills。
udc -o		编译所有/daemon/skill，/daemon/condition下的文件。

[0;1;37m─────────────────────────────────[0m 
HELP
    );
    return 1;
}
