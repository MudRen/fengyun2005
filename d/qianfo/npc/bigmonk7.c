// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("天肥", ({ "dashi", "heshang" }));
        set("gender", "男性" );
        set("class", "bonze");
		set("title","兴国禅寺天字辈大师");
        set("age", random(40)+20);
        
        set("long", "他是兴国禅寺中颇有威望的天字辈大师\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("unarmed",100);
        set_skill("dabei-strike",100);
        set_skill("nodust-steps",80);
        set_skill("parry",100);
        set_skill("dodge",100);
        
        map_skill("dodge","nodust-steps");
        map_skill("unarmed","dabei-strike");
                
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}


int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
