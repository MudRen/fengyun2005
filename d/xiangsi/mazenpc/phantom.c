// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("奇邪", ({ "gaseous phantom","phantom"}) );
	set("race", "野兽");
	set("target_name","雾影奇邪");
	set("class","huashan");
	set("group","icecave_maze");

	set("combat_exp", 3500000);
	set_skill("cloud-dance", 180);
	set_skill("anxiang-steps", 180);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("nine-moon-claw", 160);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("nine-moon-force", 150);
	set_skill("nine-moon-spirit", 150);
	set_skill("nine-moon-steps", 150);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("dodge", "cloud-dance");
	map_skill("move", "anxiang-steps");
	map_skill("unarmed", "nine-moon-claw");
	map_skill("force", "nine-moon-force");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","一只鬓侧双角，长尾曳地的独眼怪物。\n");
	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",86);
	set("drop/common",80);
	set("drop/rare",20);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/shuanghuaningjie_1.c",
__DIR__"obj/shuangtianxuewu_1.c",
//__DIR__"obj/wufangbianhuan_1.c",
__DIR__"obj/zhaoyuwanqing_1.c",
__DIR__"obj/binglunyinjing_1.c",
__DIR__"obj/qixingbanyue_1.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/snowball2.c",
__DIR__"obj/moveupdrug.c",
__DIR__"obj/fakemoveupdrug.c",
__DIR__"obj/shuanghuaningjie_2.c",
__DIR__"obj/shuangtianxuewu_2.c",
__DIR__"obj/tianheyixian_1.c",
//__DIR__"obj/wufangbianhuan_2.c",
__DIR__"obj/zhaoyuwanqing_2.c"
	}) );



}
smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (!enemy[i]->is_busy() && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp"))
				this_object()->smart_busy();

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (enemy[i]->is_busy())
				this_object()->smart_attack();

}

smart_busy() {
	set("class","huashan");
	map_skill("dodge", "cloud-dance");
	this_object()->perform_action("dodge.yexuechuji");
	return;
}
smart_attack() {
	set("class","shenshui");
	map_skill("dodge", "nine-moon-steps");
	this_object()->perform_action("unarmed.polu");
	return;
}