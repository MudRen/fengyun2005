#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(CYN"碎玉葡萄"NOR, ({ "grape"}) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一些青碧如玉的碎玉葡萄。\n");
		set("unit", "把");
		set("desc_txt","恫吓对手");
		set("base_unit","粒");
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("material", "bone");
		set("level_required",60);
		set("volumn",1);
	}
	set_amount(1);
	::init_throwing(60);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	mapping buff;
	
	if (victim->query_temp("annie/grape"))	return 0;
	if (!victim->query("can_speak"))	return 0;	// 动物才不管你叫什么呢

	tmp1 = CYN"$N见到一击得手，高声喝道：＂可千万别乱动了！你所中暗器名碎玉葡萄，\n乃江湖兵器谱排名第三十一，暗器排名第一的独门暗器，你如任意行走，毒\n随血行，一旦攻心，无药可救！＂\n"NOR;
	victim->add_temp("annie/grape", 1);	
	if (random(me->query_int()*2) > random(victim->query_int()))
	{
		tmp1 += CYN"$n一听，心先凉了半截。但凡暗器，或是速度取胜，或以喂毒伤人，而越是
诡异厉害的，越是喜欢安一个动人美艳的名目，只听碎玉葡萄这名字，便可
想象那毒性之强，连号称可避毒之玉也可粉碎。
$n越想越怕，动作顿时迟滞下来。\n"NOR;
		buff = 
		([
			"caster": me,
			"who":  victim,
			"type":  "slow",
			"att":	"curse",
			"name":	"碎玉葡萄·恫吓",
			"buff1": "apply/slow",
			"buff1_c":50+random(50),
			"time":  30,
			"buff_msg": "",
		]);
		ANNIE_D->buffup(buff);
	}
	else
	{
		tmp1 += WHT"$n冷哼道：什么碎玉葡萄，端的是胡说八道！\n"NOR;
	}
	me->perform_busy(1);
	return tmp1;
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
