// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("雪麒麟", ({ "snowy kirin","kirin" }) );
	set("long",WHT"牠已修成人形，手里握着一根冰柱，正趴在地上打盹。\n牠就是玄冰后洞的守卫者雪麒麟。\n\n"NOR);
	set("no_arrest",1);
	set("no_fly",1);
	set("race", "野兽");
	set("class","huashan");
	set("group","icecave_maze");

	set("attitude", "friendly");
	set("real_ph",1);
	set("no_busy",6);
	set("reward_npc", 1);
	set("difficulty", 10);

	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);
	// GKS * 5

	set("max_gin",16000);
	set("max_sen",16000);
	set("max_kee",24000);
	set("max_force",10000);
	set("force",20000);

	set("combat_exp", 7200000);
	set_skill("stormdance", 182);
	set_skill("snowforce", 280);
	set_skill("chillblade", 280);
	set_skill("hanmei-force", 320);
	set_skill("liangyi-force", 320);
	set_skill("shuaijiao", 210);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("blade", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("unarmed", "shuaijiao");
	map_skill("force", "hanmei-force");
	map_skill("blade", "chillblade");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	setup();

	weapon=carry_object("obj/weapon/blade/glacier");
	weapon->wield();

	set("drop/bg",40);
	set("drop/common",60);
	set("drop/rare",40);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/bingpojingbi_2.c",
__DIR__"obj/hanxueliulan_2.c",
__DIR__"obj/mingyue_2.c",
__DIR__"obj/qinghui_2.c",
__DIR__"obj/shuanghuaningjie_2.c",
__DIR__"obj/shuangtianxuewu_2.c",
__DIR__"obj/tianheyixian_1.c",
__DIR__"obj/qixingbanyue_2.c",
//__DIR__"obj/wufangbianhuan_2.c",
__DIR__"obj/zhaoyuwanqing_2.c",
__DIR__"obj/snowball2.c",__DIR__"obj/moveupdrug.c",__DIR__"obj/fakemoveupdrug.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
__DIR__"obj/glacialcrevasses.c",__DIR__"obj/lockupdrug.c",__DIR__"obj/nail.c",
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
	ccommand("perform dodge.shuangtianxuewu");
	ccommand("exert bingpojingbi");

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (enemy[i]->is_busy())
				this_object()->smart_attack();	// 只要有人busy,就chill。

	set("class","moon");
	map_skill("force","snowforce");
	map_skill("dodge","stormdance");

}

smart_attack() {
	set("class","huashan");
	map_skill("force", "liangyi-force");
	ccommand("exert liangyijue");
	return;
}
