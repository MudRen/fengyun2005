#include <ansi.h>
inherit NPC;


void create()
{
        set_name("晦明大师", ({ "hui ming", "huiming" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺晦字辈大师");
	set("long","
晦明大师自幼便在兴国禅寺出家，论起辈分还是主持兴国大师的师叔，只是
他不爱管寺里的事儿，整天以研读佛经为乐。\n");
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
