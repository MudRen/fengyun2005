// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("雾影", ({ "mistfolk"}) );
	set("race", "野兽");
	set("target_name","雾影奇邪");
	set("class","moon");
	set("group","icecave_maze");

	set("combat_exp", 3500000);
	set_skill("stormdance", 139);
	set_skill("snowforce", 213);
	set_skill("hanmei-force", 200);
	set_skill("tanzhi-shentong", 160);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "tanzhi-shentong");
	map_skill("force", "snowforce");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","一团飘来荡去，轻声低语的影子．．．\n");
	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",78);
	set("drop/common",90);
	set("drop/rare",10);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/bingpojingbi_1.c",
//__DIR__"obj/budongzhijie_1.c",
__DIR__"obj/hanxueliulan_1.c",
__DIR__"obj/mingyue_1.c",
__DIR__"obj/qinghui_1.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/qixingbanyue_1.c",
__DIR__"obj/bingpojingbi_2.c",
__DIR__"obj/hanxueliulan_2.c",
__DIR__"obj/mingyue_2.c",
__DIR__"obj/qinghui_2.c",
__DIR__"obj/snowball2.c",
__DIR__"obj/moveupdrug.c",
__DIR__"obj/fakemoveupdrug.c",
}) );





}

void smart_fight()
{
	object me,target;
	me = this_object();
	target = select_opponent();
	set("class","moon");
	map_skill("force","snowforce");
	ccommand("perform dodge.hanxueliulan");
	ccommand("exert bingpojingbi");
	set("class","huashan");
	map_skill("force","hanmei-force");
	ccommand("perform tanzhijinghun");
}