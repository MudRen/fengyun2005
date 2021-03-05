// Annie. 2005 
// Dancing_Faery@HOTMAIL.COM


#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string* files;
string *read_table(string file);
int analysis(string a);
int deep_analysis(string a);

int b=0,c=0;

int main(object me, string arg)
{
		int i,a;
        b=0;
        c=0;
        
        if (arg != "yesiknow")
        	return notify_fail("请阅读帮助，此命令有破坏性。\n");
        	
        seteuid(getuid());
        files=read_table("change.txt");
		write("\n");
		for (i=0; i<sizeof(files); i++)
			analysis(files[i]);
		write(HIY+(b+c)+HIC"个档案被发现，"HIY+b+HIC"个档案处理成功，"HIY+c+HIC"个档案处理失败。\n"NOR);

        write("Ok.\n");
        return 1;
}


string *read_table(string file)
{
        string *line, *field, *format;
        string *data;
        int i, rn, fn;
        data = ({});
		if (read_file(file))
		{
			line = explode(read_file(file), "\n");
			for( i=0; i<sizeof(line); i++)
			{
					if( line[i]=="" || line[i][0]=='#' ) continue;
					data+=({line[i]});
			}
		}
        return data;

}

int analysis(string a)
{
	string* dirs;
	string tmp;
	int i;
	string ext = ".c";

	reset_eval_cost();

	if (a[0] == '!')
	{
		ext="";
		a=a[1..];
	}

	if (a[0] == '@')
	{
		//
		return deep_analysis(a[1..]);
	}

	if( file_size(a+ext) < 0 )
	{
			write(HIG"没有"+a+"这个档案。\n"NOR);
			c++;
			return 0;
	}

	dirs = explode(a, "/");
	mkdir("bunny");
	tmp="bunny/";
	for (i=0;i<sizeof(dirs)-1;i++)
	{
		tmp += dirs[i];
		mkdir(tmp);
		tmp += "/";
	}

	if (cp(a+ext,"/bunny"+a+ext))
		write(HIW"档案"+a+"已成功处理。\n"NOR);
	b++;
	return 1;
	
}


int deep_analysis(string a)
{
	// get file list first;
	mixed *file;
	int i;

	reset_eval_cost();
	file = get_dir(a, -1);
	if( !sizeof(file) )
	{
		if (file_size(a) == -2)
			write(HIG"此档案夹为空。\n"NOR);
		else
			write(HIG"此档案夹不存在。\n"NOR);
		c++;
		return 0;
	}

	i = sizeof(file);
	while(i--) 
	{
		if (file[i][1]==-2) 
		{
			deep_analysis(a+file[i][0]+"/");
			continue;
		}
		analysis("!"+a+file[i][0]);
	}
	write(HIB+a+"档案夹处理完毕。\n"NOR);
	return 0;
}


int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	backdir yesiknow[0m
[0;1;37m────────────────────────────────[0m   

调试指令，为tttt的反向命令，如果你不是负责文件更新，请不要使用此命令。

[0;1;37m────────────────────────────────[0m   

HELP
   );
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
