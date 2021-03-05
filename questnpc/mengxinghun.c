#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("孟星魂", ({ "men xinghun","men" }) );
	set("gender", "男性" );
        set("nickname",HIG"流星蝴蝶剑"NOR);
        set("title","快活林   多情杀手");
        set("quality","good");
	set("age", 22);
	set("int", 29);
	set("per", 30);
	set("str", 32);
	set("dur", 30);
	set("cor", 50);
	set("long",
"他穿着一件鲜红色的斗蓬，但脸色却苍白得可怕。\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
		set("max_force",2000);
		set("force",2000);

        set("combat_exp", 2000000);
        set("score", 1200);
        set_skill("unarmed", 80);
        set_skill("sword", 110);
        set_skill("force", 70);
        set_skill("parry", 110);
        set_skill("literate", 80);
	set_skill("dodge", 140);

        set_skill("feixian-sword", 180);
	set_skill("yiqiforce", 60);
        set_skill("feixian-steps",180);
	
//	map_skill("unarmed", "meihua-shou");
        map_skill("sword","feixian-sword");
        map_skill("force", "yiqiforce");
        map_skill("parry", "feixian-sword");
		map_skill("dodge","feixian-steps");
		set("chat_chance",10);
		set("chat_msg",	({
		"孟星魂抬头望着天空，喃喃道：有些人的生命，是不是和流星一样短暂。\n",
"孟星魂笑了笑道：有人说，流星出现的时候，若能及时许个愿，你的愿望一定能达到。\n",
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
/*
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


do_fight()
{	
	command("perform dodge.luoyeqiufeng");
	command("perform caideikuangwu");
}

	
	*/
