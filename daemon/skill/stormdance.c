// stormdance.c
// annie 07.2003
// dancing_faery@hotmail.com


#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
        set("name","天岚凝舞");
        set("usage/dodge",1);
        set("usage/move",1);
        set("type","step");
        set("difficulty",300);
        set("practice_limit",50);
        set("effective_level",230);
        set("skill_class","moon");
        set("dodge_msg", ({
                "只见$n一个转身，忽然回眸一笑。$N一楞之下，哪里还有人在。\n",
                "可是$n婉尔一笑，不退反进，身形径向$N飘来。$N只觉一阵寒意袭卷，连忙后退。\n",
                "$n身法轻灵，翩然而起，一阵迷茫的水雾升腾翻卷之间，$n已失去踪影。\n",
                "$n脚步轻盈，风姿嫣然，身子便如在浮冰上飘游般掠过，不等$N劲风袭到，已悄然隐去。\n",
                "$n息气上升，意存玉枕，月在青天影在波，身子飘然而起。\n",
        }) );
}

mixed dodge_ob(object victim, object me,int attack_type)
{
        if (userp(me) && me->query("class")!="moon")            return 0;
        if (me->query_skill("stormdance",1)<100)        		return 0;
        if (me->query_skill_mapped("force") != "snowforce")     return 0;
        if (victim->query_busy())       return 0;
        if (attack_type != TYPE_PERFORM)        return 0;

		if (!userp(me))
		{
        	victim->perform_busy(1);
            if (me->query_busy() > 2 
            	&& victim->query("combat_exp") > me->query("combat_exp")/2 
            	&& me->query_skill("snowforce") >= 200 ) // 对方不是dummy
                        me->start_busy(2);      // 那么消解掉对手先施展的Busy技能。
		}
		else
		{
			if (random(100)> 40+ (me->query_skill("stormdance",1)-100)/10)	return 0;
	        victim->perform_busy(1);
		}

        return WHT"$n进退飘挪间冷风掠地，$N只觉凛然寒意侵魂蚀骨，动作顿时迟滞不灵。\n"NOR;
}       



string query_dodge_msg(object me)
{
        mapping msg;

        msg = skill_attr["dodge_msg"];

        if (me->query_temp("buffup/evade_amount") > 0)
                return CYN"$n灵台如镜，心境空明，仿佛早已预知$N此招来势，避到半尺之外。\n"NOR;

        if(sizeof(msg) > 0)
                return msg[random(sizeof(msg))];
        
        return 0;
}

int help(object me)
{
	write(@HELP   
天岚凝舞比其他闪避武功在忙乱状态下有更高的几率避开敌人的攻击，
等级100以上如果闪避成功，有一定几率中断对手的特技使用，
其几率为random(100) < 40+（技能等级-100）/10
	
L30『霜天雪舞』（dodge.shuangtianxuewu）
增加普通攻击时连续出招的几率，＋６０％
上册	：＋６６％
中册	：＋７１％
下册	：＋７５％

L150『寒雪流岚』（dodge.hanxueliulan）
将自身伤害反击对手，持续时间＝天岚凝舞等级／３
无：	15% 反击气血伤害
简介:	25% 反击气血伤害
概略:	25% 反击精气神伤害
真章:	35% 反击精气神伤害
精要:	45% 反击精气神伤害

HELP
    );
    return 1;
}
