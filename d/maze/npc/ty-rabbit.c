#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("大山兔", ({ "rabbit" }) );
        set("race", "野兽");
        set("age", 5);
        
		set("maze","taoyuan");
		set("target_name","大山兔");
		
        set("combat_exp",300000);
        set("long", "一只硕大的白尾巴的野兔，尾巴一翘一翘的，身侧有一层奇异的玉色光芒。\n");
        set_skill("dodge", 300);
        set_temp("apply/attack",150);
        setup();
}


mixed hit_ob(object me,object victim)
{
	int extra, dream;
	string message="";
	extra = 30;
	victim->receive_damage("kee",extra,me);
	message_vision(WHT"\n$N身侧的玉色光芒忽如蝶翼般片片飞向$n，$n"+WHT"只觉经脉中一阵灼痛。\n"NOR,me, victim);
	return;
}
