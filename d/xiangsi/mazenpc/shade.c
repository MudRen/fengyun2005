// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("雪域阴魂", ({ "dungeon shade","shade"}) );
	set("class","bonze");
	set("group","icecave_maze");
	set("target_name","雪域阴魂");
	
	set("combat_exp", 2000000);
	set_skill("essencemagic", 180);
	set_skill("magic", 200);
	set_skill("fengmo-staff", 135);
	set_skill("staff", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("staff", "fengmo-staff");
	map_skill("magic", "essencemagic");

	setup();

	weapon=carry_object("/obj/weapon/staff");
	weapon->set_name(WHT"覆满冰雪的木杖"NOR, ({"staff" }) );
	weapon->set("long","这是一根覆满冰雪的木杖。\n");
	weapon->set("value",0);
	weapon->wield();

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","一缕冻死在冰洞之人怨念凝成的阴魂。\n");
	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",90);
	set("drop/common",100);
	set("drop/rare",0);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/bingpojingbi_1.c",
__DIR__"obj/hanxueliulan_1.c",
__DIR__"obj/mingyue_1.c",
__DIR__"obj/qinghui_1.c",
__DIR__"obj/shuanghuaningjie_1.c",
__DIR__"obj/shuangtianxuewu_1.c",
//__DIR__"obj/wufangbianhuan_1.c",
__DIR__"obj/zhaoyuwanqing_1.c",
__DIR__"obj/binglunyinjing_1.c",
__DIR__"obj/herb.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/bingpojingbi_1.c",
//__DIR__"obj/budongzhijie_1.c",
__DIR__"obj/hanxueliulan_1.c",
__DIR__"obj/mingyue_1.c",
__DIR__"obj/qinghui_1.c",
__DIR__"obj/shuanghuaningjie_1.c",
__DIR__"obj/shuangtianxuewu_1.c",
//__DIR__"obj/wufangbianhuan_1.c",
__DIR__"obj/zhaoyuwanqing_1.c"
	}) );



}

void smart_fight()
{
	object me,target;
	me = this_object();
	target = select_opponent();
	if (!random(2))
	{
		set("class","lama");
		ccommand("perform fuhu");
	}
	else
	{
		set("class","bonze");
		ccommand("conjure void_sense");
		set("class","lama");
		ccommand("perform fuhu");
	}
}
