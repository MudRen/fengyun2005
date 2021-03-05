// ; annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();

void create()
{
	object weapon;
    set_name("薛音素", ({ "master xue", "master", "xue" }) );
    set("nickname", YEL"月神"NOR);
	set("gender", "女性");
        set("age",19);
         set("long",
"月色水波间，仿佛有层淡淡的烟雾升起，烟雾间仿佛有一条淡淡的人影。
云开，月现，月光淡淡的照下来，恰巧照在她的脸上。苍白的股，苍白如
月。\n"
        );

	set("combat_exp", 90000000);
	set("NO_KILL",1);
    set("score", -10000);

    set("class", "moon");
    set("reward_npc", 1);
    set("difficulty", 10);

	set("no_fly",1);
	set("no_arrest",1);

    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000);

    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",70);
	
    set("apprentice_available", 1);

    create_family("皓月宫", 3, "宫主");
	set("title","皓月宫");

    set("rank_nogen",1);

    set_skill("literate", 150);
	set_skill("parry", 170);
	
	set_skill("perception", 300);
	set_skill("throwing", 300);
	set_skill("starrain", 200);

	set_skill("force", 180);
	set_skill("snowforce", 140);

	set_skill("blade", 150);
	set_skill("chillblade", 150);

	set_skill("dodge", 220);
	set_skill("move", 220);
	set_skill("stormdance", 200);

	map_skill("throwing","starrain");
    map_skill("parry", "chillblade");
    map_skill("blade", "chillblade");
    map_skill("move", "stormdance");
    map_skill("dodge", "stormdance");
    map_skill("force", "snowforce");

    setup();

	set("env/no_teach",1);			// duh, almost got me
	
	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",WHT"飞雪沉纱"NOR);
	weapon->set("long","一件似有还无的素白纱衣。");
	weapon->wear();
	weapon=carry_object("/questnpc/obj/yueshenblade");
	weapon->wield();

}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
