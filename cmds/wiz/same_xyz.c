#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, env;
	int x, y, z;
	string file, dir, xx, msg;
	string *files;
    int i,total=0;
    int size;
    		
	env = environment(me);
	x = env->query("coor/x");
	y = env->query("coor/y");
	z = env->query("coor/z");
	
	file = file_name(env);
	write ("file is " + file + "\n");
	
	sscanf(file,"/d/%s/%s",dir,xx);

   	files= get_dir("/d/"+dir+"/");
   	
   	seteuid(getuid());
   	for(i=0; i<sizeof(files); i++) 
   	{
   	    size=sizeof(files[i]);
       	if(files[i][(size-2)..size]==".c"){
			obj= find_object("/d/"+dir+"/"+files[i]);
			if (!obj) obj=load_object("/d/"+dir+"/"+files[i]);
			if (!obj) {
				continue;
			}
			if (obj->query("coor/x")==x && obj->query("coor/y")==y && obj->query("coor/z")==z){
				write("room " + i + " = "+ files[i]+" ");
				write(HIR"	gocha !\n"NOR);	
			}
		}	
     }   
        
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	same_xyz[0m
[0;1;37m────────────────────────────────[0m   

调试命令，在当前地区查询坐标重复的房间。

[0;1;37m────────────────────────────────[0m
HELP
    );
    return 1;
}
