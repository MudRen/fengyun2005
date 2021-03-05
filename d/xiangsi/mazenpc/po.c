// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{
	set_name("一穷", ({ "bo",}) );
	set("class","moon");
	set("race", "野兽");
	set("target_name","一穷二白");
	set("group","icecave_maze");
	set("title",HIW"冰雪怪物"NOR);

	set("combat_exp", 1000000);
	set_skill("mapo", 110);
	set_skill("spells", 200);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("spells", "mapo");

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","一只长得奇奇怪怪的白色大熊。\n");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",85);
	set("drop/common",70);
	set("drop/rare",30);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/snowball.c",
__DIR__"obj/hastedrug.c",
__DIR__"obj/statdrug.c",
__DIR__"obj/seal.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/binglunyinjing_1.c",
__DIR__"obj/bingpojingbi_1.c",
__DIR__"obj/mingyue_1.c",
__DIR__"obj/qinghui_1.c",
	}) );

	setup();

}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	if (target->query_temp("is_unconcious"))
		return;
	SKILL_D("mapo")->cast_spell(me,"freeze",target);
	
}
