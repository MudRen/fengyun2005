// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","太虚幻步");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",130);
	set("difficulty",200);
	set("skill_class","ninja");
	set("dodge_msg", ({
	        "$n身影一晃，霎那间挪至$N的背后。\n",
	        "$n微微向左一摆身，整个人飘出丈外。\n",
	        "$n双手微微舞动，整个人象一片树叶般随着气流飘荡。\n",
	        "$n双腿微踢，象一只轻捷的燕子飞了开。\n",
	        "$n腰身一拱，整个人弹出丈外。\n"
	}) );
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if ((int)me->query("tianfeng/ghosty-steps")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	return 1;
}
*/

int help(object me)
{
	write(@HELP   
『太虚百幻』
需150级太虚幻步，将所有的灵力化作内力，此特技不需要enable太虚幻步
便能够使用。使用时只需 perform taixubaihuan，自我忙乱一轮。
转换内力数量为：当前灵力＊（太虚幻步等级）／３００
HELP
    );
    return 1;
}
