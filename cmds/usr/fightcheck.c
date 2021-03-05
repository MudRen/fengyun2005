// smash.c 2-22-95
 
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string arg2, para, list;
	
	if (!arg)	return notify_fail("fightcheck <-参数> NPC名\n");
	para = "all";
	
	if (sscanf(arg,"-%s %s",para,arg2)==2){
		arg = arg2;
	}
			
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("你身边没有这个NPC。\n");
	
	tell_object(me,WHT"NPC "+arg+" 状况分析：\n"NOR);
	
	write("======================================================\n");
	switch (para) {
		case "hate":		
					list = sprintf("憎恨列表：%O\n",ob->query_hate_list());
					list += sprintf("实际憎恨列表：%O\n", ob->query_hate_list2());
					list += sprintf(YEL"当前在战斗中的憎恨最多对象：%O\n"NOR,ob->query_max_hate());
					break;
		case "damage":	
					list = sprintf("伤害列表：%O\n", ob->query_damage_list());
					list += sprintf("综合队伍伤害列表：%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"当前领先队伍：%O\n"NOR,ob->query_max_damage_dealer());
					break;
		case "all":		
					list = sprintf("憎恨列表：%O\n", ob->query_hate_list());
					list += sprintf("实际憎恨列表：%O\n", ob->query_hate_list2());
					list += sprintf(YEL"当前在战斗中的憎恨最多对象：%O\n"NOR,ob->query_max_hate());
					list += sprintf("伤害列表：%O\n", ob->query_damage_list());
					list += sprintf("综合队伍伤害列表：%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"当前领先队伍：%O\n"NOR,ob->query_max_damage_dealer());
	}

	write(list);
	write("======================================================\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 :  fightcheck <-参数> NPC
[0;1;37m────────────────────────────────[0m   
   
调试监测指令，检查NPC的一系列受伤、憎恨情况

参数：-hate	检查憎恨；-damage 检查伤害
[0;1;37m────────────────────────────────[0m   
HELP
   );
   return 1;
}
