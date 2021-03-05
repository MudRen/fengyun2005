// ninjitsu.c

inherit SKILL;

void setup(){
	set("name","忍术");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","ninja");
	set("effective_level",180);
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
	if ((int)me->query("tianfeng/ninjitsu")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	return 1;
}*/


int help(object me)
{
	write(@HELP   
『追牙』（conjure zhuiya）
需100级忍术，耗费300点灵力，去除周围所有人的隐身，并使其忙乱三轮。
受影响者在10分钟内无法再使用隐身。
注意，该特技只能影响正常情况下你能够叫杀的对手。

『雨露』（conjure dart）
需150级忍术，发暗器长距离（可以在不同地点）攻击对手，对手不会因此
而对你叫杀。被攻击的敌人在以后的五分钟内警觉将大大提高，无法再使
用此术。该特技不能用于经验值小于自身10倍以下的对手。
伤害气血=（有效法术+自身经验等级）+ random（有效法术+自身经验等级）

『雾隐』（conjure wuyin）
需200级忍术，山穷水尽时使用的一招，进入类似于僵死状态，有50%几率
骗过对手逃生，如果失败。。。。僵死醒来后很大可能就是在阎王殿了。
HELP
    );
    return 1;
}
