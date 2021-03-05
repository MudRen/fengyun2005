// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("冰魔神", ({ "glacial efreet","efreet"}) );
	set("race", "野兽");
	set("class","huashan");
	set("group","icecave_maze");

	set("fy41/xingguo_remedy",2);

	set("real_ph",1);
	set("reward_npc", 1);
	set("difficulty", 10);

	set("toughness", 150);
	set("max_gin",12000);
	set("max_sen",12000);
	set("max_kee",18000);

	set("combat_exp", 5400000);

	set_skill("stormdance", 165);
	set_skill("snowforce", 253);
	set_skill("essencemagic", 253);
	set_skill("lotusforce", 292);
	set_skill("magic", 200);
	set_skill("cloud-dance", 217);
	set_skill("anxiang-steps", 217);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("nine-moon-claw", 190);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("nine-moon-force", 150);
	set_skill("nine-moon-spirit", 150);
	set_skill("nine-moon-steps", 150);
	set_skill("hanmei-force",200);
		
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("magic", "essencemagic");
	map_skill("dodge", "cloud-dance");
	map_skill("move", "anxiang-steps");
	map_skill("unarmed", "nine-moon-claw");
	map_skill("force", "nine-moon-force");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();

	set("attitude", "friendly");

	set("long",WHT"牠两丈来高，浑身晶莹剔透仿佛雪雕，此刻正站立在雪洞中央\n四顾，不时喷吐出一口白色的寒雾。\n\n牠就是玄冰前洞的守卫者冰魔神。\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",60);
	set("drop/common",90);
	set("drop/rare",10);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/bingpojingbi_2.c",
__DIR__"obj/hanxueliulan_2.c",
__DIR__"obj/mingyue_2.c",
__DIR__"obj/qinghui_2.c",
__DIR__"obj/shuanghuaningjie_2.c",
__DIR__"obj/shuangtianxuewu_2.c",
__DIR__"obj/tianheyixian_1.c",
//__DIR__"obj/wufangbianhuan_2.c",
__DIR__"obj/zhaoyuwanqing_2.c",
__DIR__"obj/snowball2.c",
__DIR__"obj/moveupdrug.c",
__DIR__"obj/fakemoveupdrug.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
__DIR__"obj/qixingbanyue_2.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
__DIR__"obj/glacialcrevasses.c",
__DIR__"obj/lockupdrug.c",
__DIR__"obj/flusk.c",
	}) );



}
smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();

	set("class","moon");
	map_skill("force","snowforce");
	map_skill("dodge", "stormdance");
	ccommand("perform dodge.hanxueliulan");
	ccommand("exert bingpojingbi");
	
	set("class","huashan");
	map_skill("force","hanmei-force");
	ccommand("exert remedy");

	smart_attack();
		
	set("class","moon");
	map_skill("force","snowforce");
	map_skill("dodge","stormdance");

}


smart_curse() {
	set("class","bonze");
	ccommand("conjure void_sense");
	return;
}

smart_busy() {
	set("class","huashan");
	map_skill("dodge", "cloud-dance");
	perform_action("dodge.yexuechuji");
	return;
}

smart_attack() {
	set("class","shenshui");
	map_skill("force", "nine-moon-force");
	map_skill("dodge", "nine-moon-steps");
	perform_action("unarmed.polu");
	return;
}
