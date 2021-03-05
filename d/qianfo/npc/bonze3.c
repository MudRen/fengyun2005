// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("风静", ({ "fengjing" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺风字辈大师");
        set("age", random(40)+20);

        set("long", "他是兴国禅寺中颇有威望的风字辈大师\n");
        set("attitude", "friendly");
        
        set("combat_exp", 36000);
               
        set("chat_chance", 1);
        set("chat_msg", ({
                "风静看了看你，笑道：找不到路了？\n",
        }) );
        set("inquiry", ([
                "路" : "你去弥勒殿看一看弥勒佛像吧。\n",
                "road" : "你去弥勒殿看一看弥勒佛像吧。\n",
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
