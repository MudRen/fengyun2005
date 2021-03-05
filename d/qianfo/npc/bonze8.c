// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
int give_qin();
void create()
{
        set_name("云海", ({ "yunhai" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);

        set("long", "他是兴国禅寺中颇有威望的云字辈大师。\n");
        set("combat_exp", 2300000);
        set("attitude", "friendly");
    
        set("chat_chance", 1);
        set("chat_msg", ({
                "云海说道：你想皈依佛门吗？\n",
        }) );
        set("inquiry", ([
		"皈依佛门" : (: give_qin :),
		"fomen" : (: give_qin :),
		]));
                    
        set_skill("dabei-strike",200);
        set_skill("notracesnow",200);
        set_skill("unarmed", 200);
    	set_skill("force", 200);
    	set_skill("dodge", 200);
	    set_skill("parry", 120);
	    set_skill("lotusforce", 150);
	    set_skill("notracesnow",120);
	    set_skill("dabei-strike",120);
	    set_skill("move",120);
	    
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	 
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );

        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}


int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}

int give_qin()
{
        object obj;
		if( !query("given"))
        {
			command("say 我帮不到你很多，但我不入地狱，谁入地狱！！这个你拿去吧！\n");
			obj = new(__DIR__"obj/shoe2");
			command("give shoes to "+this_player()->get_id());
			set("given",1);
	        }
		else
			command("say 我也帮不到你！\n");
        return 1;
}

void reset()
{
		delete("given");
}

