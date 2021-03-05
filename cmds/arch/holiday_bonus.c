#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("当前Quest的额外奖励为："+ QUESTS_D->query_holiday()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("参见HELP格式说明。\n");
		
	seteuid(getuid());
	
	if (lvl>=0 && lvl<=900) {
	QUESTS_D->set_holiday(lvl);
		write(HIR"\n当前每个Quest的奖励为原来的"+ (lvl+100)+"%，有效期持续到系统重启或再次设置。\n"NOR);
		CHANNEL_D->do_sys_channel("info","天机使命（Quest）的经验/能力奖励现在设置为 "+(lvl+100)+"％，大家加油啊！");
		log_file("QBONUS_UPDATE_LOG", 
					sprintf("(%s)%s 改动QUEST奖励到%d。\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					lvl,
				));
		return 1;
	}
		
	return notify_fail("你只能设置0-900之间的数字。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	holiday_bonus <数字>[0m
[0;1;37m────────────────────────────────[0m   

此命令是给管理巫师动态改变游戏中Quest的奖励（0-900）

奖励 = 基本奖励*（100+bonus）/100

你所能修改的便是这个bonus数值，比如说bonus = 100相当于加倍奖励

每次重新启动后BONUS自动恢复为0

此命令影响Quest所得的经验值、以及Quest所得的ABILITY值，
此命令影响所有调用/adm/daemons/questd中give_reward函数的奖励
此命令对TASK没有影响

[0;1;37m────────────────────────────────[0m  
HELP
);
        return 1;
}
 
