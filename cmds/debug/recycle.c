#include <ansi.h>
inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j=0;
	int k=0, num;
	string file;
	
 	ulist = objects();
	i = sizeof(ulist);
	write(HIR"\n正在清理物品列表．．．\n"NOR);
	while (i--) {
		if (!ulist[i])
			continue;
		if (environment(ulist[i]))
			continue;
		if (ulist[i]->query("short"))
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// 天知道是什么东西
			continue;
		if (ulist[i]->query("kee"))
			k++;
		else
			j++;
		if (!arg || arg != "-s")
		{
			write("摧毁了无环境的"+ulist[i]->query("name")+"("+ulist[i]->query("id")+")");
			write ("。\n");
		}
		destruct(ulist[i]);
	}
	write(HIG"．．．清理结束。\n"NOR);
	write(HIW"一共清除了"+(j+k)+"个无环境的物品，其中有"+k+"个是生物。\n\n"NOR);
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	recycle[-s] [0m
[0;1;37m────────────────────────────────[0m   

清理无环境的所有物品。
* 本指令未认真考量，使用前请注意可能引发错误。	 annie.08.2003

[0;1;37m────────────────────────────────[0m   
HELP
);
        return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

