#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	object room;
	object *ob_list;
	string msg="";
	string subip;
	int i;
	if(! room = find_object(AREA_WIZ"courthouse"))
		room = load_object(AREA_WIZ"courthouse");
	if (!arg) 
	{
	ob_list = users();
	for(i=0;i<sizeof(ob_list);i++)
	if(environment(ob_list[i]) && !wizardp(ob_list[i]))
	{
		tell_object(ob_list[i],HIR "\n\n你被管理人员怀疑为机器人！
如果你不能从法院及时离开的话，就会按风云天条处罚！\n\n" NOR);
		ob_list[i]->move(room);
	}		
		return 1;
	}
	if(!ob=find_player(arg))
	{
	return notify_fail("找不到玩家"+arg+"！\n");
	}
	else
	{
                tell_object(ob,HIR "\n\n你被管理人员怀疑为机器人！
如果你不能从法院及时离开的话，就会按风云天条处罚！\n\n" NOR);
                ob->move(room);
	}
	return 1;
}
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	whoisrobot <id/arg/none>[0m
[0;1;37m────────────────────────────────[0m   

让你抽查所有／个别在线玩家是否是机器人。

[0;1;37m────────────────────────────────[0m 
HELP
   );
   return 1;
}
