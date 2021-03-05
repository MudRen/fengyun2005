#include <ansi.h>
inherit NPC;


void create()
{
        set_name("晦聪大师", ({ "hui cong", "huicong" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺晦字辈大师");
	set("long","
晦聪大师自幼便在兴国禅寺出家，七十余年中潜心武学，从未出过寺门一步，
博览武学典籍，所知极为广博。。\n");
        set("age", 89);
        set("combat_exp", 10000000);
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("chat_msg", ({

        }) );
        set("inquiry", ([

	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
