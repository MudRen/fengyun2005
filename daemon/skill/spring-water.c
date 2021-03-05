//spring-water.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","春水罗衫");
	set("type","iron-cloth");
	set("effective_level",120);
	set("usage/iron-cloth",1);
	set("ic_effect",50);
	set("bounce_ratio",10);
	set("difficulty",300);
	set("skill_class","huashan");
	set("absorb_msg", ({
	        "$n秀眉微蹙，施展「两重心字罗衣」，周身衣衫飘舞，竟然似乎有点点微光浮动。\n",
	        "$n施展春水罗衫的「梦后楼台高锁」，暗劲绵密，缕缕寒气传入$N的体内。\n",
	        "$n微微侧身，一式「落花人独立」，在$N的攻势下，衣带飘飘，如风吹花舞。\n",
	        "$n施展出「微雨燕双飞」，双袖飞展，接下$N的一击。\n",
	}) );
}

int valid_learn(object me){
    	if( (string)me->query("gender") != "女性" ) {
        	return notify_fail("春水罗衫是只有女子才能练的武功。\n");
	}
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

int help(object me)
{
	write(@HELP   
L50	『冰纨天障』（bingwantianzhang）
提高有效铁布衫的功效，提高数量为春水罗衫等级的50%
若在战斗中使用会有两轮自我忙乱。

L120『映月流辉』（yingyueliuhui）
另需200级的寒梅心法，唯有配合寒梅心法才有效，不能在战斗中发起。
也不能与冰纨天障同时使用，持续3分钟。其作用是在周围产生3-5个幻
影，敌人的每次攻击有25%的几率击中幻影而不造成伤害（魔法攻击不
受此限制），每个幻影被击中后便消失，所以共有3-5次机会全部抵销
敌人的伤害。
HELP
    );
    return 1;
}
