// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{	
	object weapon;
	set_name("冰麒麟", ({ "icecream","kirin" }) );	// icecream :pp
	set("attitude", "friendly");

	set("long",WHT"牠在洞中四处游走，目中精光四射，迫人窒息。\n牠就是玄冰后洞的守卫者冰麒麟。\n\n"NOR);
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

	set("resistance/gin",80);
	set("resistance/kee",80);
	set("resistance/sen",80);
	// GKS * 5

	set("max_gin",32000);
	set("max_sen",32000);
	set("max_kee",48000);
	set("max_force",10000);
	set("force",20000);

	set("combat_exp", 10000000);
	set_skill("mapo", 200);
	set_skill("spells", 200);
	set_skill("stormdance", 200);
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


	set("drop/bg",15);
	set("drop/common",70);
	set("drop/rare",30);
	set("drop/amount",3);
	set("drop/common_drop",({
__DIR__"obj/cash.c",
__DIR__"obj/glacialcrevasses.c",
__DIR__"obj/lockupdrug.c",
__DIR__"obj/bingpojingbi_3.c",
__DIR__"obj/hanxueliulan_3.c",
__DIR__"obj/mingyue_3.c",
__DIR__"obj/shuanghuaningjie_3.c",
__DIR__"obj/shuangtianxuewu_3.c",
//__DIR__"obj/wufangbianhuan_3.c",
__DIR__"obj/zhaoyuwanqing_3.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/hanxueliulan_4.c",
__DIR__"obj/qinghui_3.c",
__DIR__"obj/kirinheart.c",
__DIR__"obj/arcticwind.c",
__DIR__"obj/boots.c",
	}) );



}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n冰麒麟身形流转，居然不见丝毫凝滞。\n"NOR, this_object());
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
		ccommand("exert shuanghuaningjie");
		set("timer/shuanghuaningjie",time()-570-random(25));
		if (random(3))
			break;
	case 1:
		if (time()>query("annie/ec")+5)
		{
			set("annie/ec",time());
			message_vision(HIW"\n冰麒麟喷出一口寒雾，$N正当其冲，冻得混身发颤，牙关格格作响！\n\n"NOR,enemy);
			switch (random(3))
			{
			case 0:
				enemy->set("kee",enemy->query("kee")*6/10);
				break;
			case 1:
				enemy->set("gin",enemy->query("gin")*6/10);
				break;
			case 2:
				enemy->set("sen",enemy->query("sen")*6/10);
				break;
			}
		}
		if (random(3))
			break;
	case 2:
		if (!present("healer 3",environment()) && time()>query("annie/sh")+30)
		{
			set("annie/sh",time());
			message_vision(HIW"\n冰麒麟仰天长啸，洞顶冰雪纷纷落下，雪堆里突然钻出一个三寸小人。\n\n"NOR,enemy);
			enemy = new(__DIR__"healer");
			enemy->move(environment());
			enemy->set("owner",this_object());
		}
		if (random(3))
			break;
	case 3:
		ccommand("cast freeze");
		if (random(3))
			break;
	}
}

