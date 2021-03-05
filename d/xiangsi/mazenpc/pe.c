// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";

void create()
{
	set_name("二白", ({ "be",}) );
	set("class","moon");
	set("race", "野兽");
	set("target_name","一穷二白");
	set("group","icecave_maze");
	set("title",HIW"冰雪怪物"NOR);

	set("combat_exp", 1200000);
	
	set_skill("shuaijiao", 110);
	set_skill("unarmed", 200);
	set_skill("parry",200);

	map_skill("unarmed", "shuaijiao");

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","一只长得奇奇怪怪的白色大熊。\n");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",70);
	set("drop/common",90);
	set("drop/rare",10);
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
