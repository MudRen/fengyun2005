// cat.c
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string file;
        object ob;
       string *line;
           int i;


        seteuid(geteuid(me));
        if (!arg) return notify_fail("指令格式 : bug <档名>|<物件名> \n");

        sscanf(arg,"%s:%d",arg,i);

        file = resolve_path(me->query("cwd"), arg);
        if( file_size(file) < 0 ) {
                ob = present(arg, me);
                if( !ob ) ob = present(arg, environment(me));
                if( !ob ) return notify_fail("没有这个档案。\n");
                file = base_name(ob) + ".c";
        }




        if (read_file(file))
        {
                line = explode(read_file(file), "\n");
		write(HIG"File: "+arg+HIG" Line:"+i+"\n");
		write(NOR+WHT+line[i-1]+" \n"NOR);
        }
        else
                write("Failed.\n");

        return 1;
}


/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/

