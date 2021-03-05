// annie 07.2003
// dancing_faery@hotmail.com
// 冰镜刀法 
// 流光皎洁·增加冰轮盈镜伤害

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		int i,t,skill,level,damage;
		mapping buff;
		string msg;
		object weapon;

		level = me->query("annie/chillblade_liuguang");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;
		
        skill = me->query_skill("chillblade",1);

		if (skill < 150)
        	return notify_fail("『流光皎洁』需要至少150级的冰镜七诀。\n");

		if( !ANNIE_D->check_buff(me,"enchantweapon")) 
			return notify_fail("没有『冰轮盈镜』，『流光皎洁』发挥不出任何作用。\n");

		if( ANNIE_D->check_buff(me,"shine")) 
			return notify_fail("你现在正在施展类似的能力。\n");

		if (skill>=190 && me->query_skill("stormdance",1)>=130)
		msg=HIC"\n$N"HIC"长袖临风，刀色淡淡，如远山黛绿，一时间你竟似看见了一轮淡青色的圆月自$N"HIC"
背后的天空缓缓升起，妖娆如鬼魅，将$N"HIC"所负的"+me->query_temp("weapon")->name()+HIC"映得遍体青莹。\n\n"NOR;
		else
msg=HIC"\n$N"HIC"双目微合，十指于胸前相并，一时间你竟似看见了一轮淡青色的圆月自$N"HIC"
背后的天空缓缓升起，妖娆如鬼魅，将$N"HIC"所负的"+me->query_temp("weapon")->name()+HIC"映得遍体青莹。\n\n"NOR;

		buff =
		([
			"caster":me,
			"who":me,
			"type":"shine",
			"att":"bless",
			"name":"冰镜七诀·流光皎洁",
			"time": 1800,
			"buff_msg":msg,
		]);

		ANNIE_D->buffup(buff);

		me->perform_busy(1);

        return 1;
}



