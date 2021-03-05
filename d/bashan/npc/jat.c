// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object weapon;
	set_name("小箭", ({ "jat" }) );
	set("class","shaolin");
	set("gender", "男性" );
	set("age", 29);
	set("per", 36);
	set("int", 40);
	set("str", 24);
	set("score",-10000);
	set("title","药医不死病");
	set("nickname",CYN"佛渡有缘人"NOR);
	set("attitude", "friendly");
	set("chat_chance", 0);
	set("chat_msg", ({
	"小箭说道：许多药道因为材料难寻，实在只是理论之说，真正结果如何，医者也殊无把握。\n",
	"小箭说道：传闻天地间有三种性极阴寒的药物，能使人功力大进。\n",
	"小箭说道：如果你不怕走火入魔，不妨去寻药来找我一试(try)。\n",
	"小箭说道：那三种药物便是"HIR BLK"雪麒麟心"NOR"、"WHT"千年凝露"NOR"、"HIW"万载冰晶"NOR"。\n",
	}) );

	set("no_curse",1);
	set("no_arrest",1);

	set("skill_public",1);

	set_skill("herb",400);
	set_skill("zen",400);
	set_skill("chanting",400);
	set_skill("dream-herb",400);
	map_skill("herb","dream-herb");

	set("NO_KILL","小箭说道：阿弥陀佛，善哉，善哉。\n");

	setup();

	weapon=carry_object("/obj/armor/ring");
	weapon->set_name("魔戒", ({ "magic ring","ring" }) );
	weapon->wear();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("青箭袍", ({ "cloth" }) );
	weapon->wear();

}

void init()
{
	add_action("do_try","try");
}

int do_try()
{
	object me;
	object d1,d2,d3;
	me = this_player();
	d1 = present("ice",me);
	d2 = present("dew drop",me);
	d3 = present("kirin heart",me);
	if (!d1 || !d2 || !d3)
		return notify_fail("你没有收集到＂寒心炼魂法＂必须的三种材料。\n");
	if (!d1->query("real") || !d2->query("real") || !d3->query("real"))
		return notify_fail("你没有收集到＂寒心炼魂法＂必须的三种材料。\n");
	destruct(d1);
	destruct(d2);
	destruct(d3);
	message_vision(HIB"\n$N服下雪麒麟心，脸色渐转青紫，就似在雪地里冻了整夜一般。\n"NOR,me,this_object());
	message_vision(HIW"\n$n飞快地将万载冰晶贴在$N额上，取出一枚银针穿过冰晶扎进$N眉心。\n\n"NOR,me,this_object());
	tell_object(me,HIW"你只觉奇寒攻心，真气自然涌出相抗。\n");
	me->unconcious();
	message_vision(CYN"\n$n扶起$N，喂$N喝下千年凝露，长吁出一口气，转身而去。\n\n"NOR,me,this_object());
	if (random(100) < 60)
	{
		me->add("max_force", 50); 
		me->add("Add_force/jat_herb",50);
	}
	else
	{
		me->add("max_force", -50); 
		me->add("Add_force/jat_herb",-50);
	}
	destruct(this_object());
	return 1;
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

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
