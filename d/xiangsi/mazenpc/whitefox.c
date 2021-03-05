// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("白狐", ({ "white fox","fox"}) );
	set("attitude", "friendly");

	set("long",WHT"牠懒懒的躺在地上睡觉，却自有一股威势天成。\n牠就是玄冰前洞的守卫者白狐。\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);

	set("race", "野兽");
	set("class","moon");
	set("group","icecave_maze");

	set("real_boss",1);
	set("boss",1);
	set("big_boss",1);
	set("reward_npc", 1);
	set("difficulty", 10);

	set("resistance/gin",70);
	set("resistance/kee",70);
	set("resistance/sen",70);
	// GKS * 5

	set("max_gin",20000);
	set("max_sen",20000);
	set("max_kee",32000);
	set("max_force",10000);
	set("force",20000);

	set_temp("buff_type/blocked",1);

	set("combat_exp", 8000000);
	set_skill("mapo", 200);
	set_skill("spells", 200);
	set_skill("stormdance", 182);
	set_skill("divineforce", 182);
	set_skill("snowforce", 280);
	set_skill("shuaijiao", 210);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "shuaijiao");
	map_skill("force", "snowforce");
	map_skill("spells", "mapo");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();
	set("drop/bg",20);
	set("drop/common",85);
	set("drop/rare",15);
	set("drop/amount",2);
	set("drop/common_drop",({
__DIR__"obj/cash.c",
__DIR__"obj/glacialcrevasses.c",__DIR__"obj/lockupdrug.c",
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
__DIR__"obj/qixingbanyue_2.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/qinghui_3.c",
__DIR__"obj/arcticwind.c",
	}) );



}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n白狐身形流转，居然不见丝毫凝滞。\n"NOR, this_object());
	return;
}

void smart_fight()
{
	int i;
	object enemy;
	enemy = select_opponent();

	switch (random(4))
	{
	case 0:
	case 1:
	case 2:
		map_skill("force","divineforce");
		if (ccommand("perform force.check_gspm"))
			ccommand("perform force.guishenpomie");
		map_skill("force","snowforce");
			break;
	case 3:
		if (time()>query("annie/ec")+5)
		{
			set("annie/ec",time());
			message_vision(HIW"\n白狐尾巴一甩，重重的拍在$N胸膛之上。\n\n"NOR,enemy);
			enemy->set("kee",enemy->query("kee")*8/10);
			break;
		}
	}
}

