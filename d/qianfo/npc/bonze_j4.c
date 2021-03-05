#include <ansi.h>
inherit NPC;


void create()
{
        set_name("净源", ({ "jing yuan", "jingyuan" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺净字辈小僧");
	set("long","这小僧头皮青青，想来剃度还没几天，负责打点寺里的里外杂务。\n");
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
