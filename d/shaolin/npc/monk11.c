// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
void create()
{
        set_name("小沙弥", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",12);
		create_family("少林寺", 23, "弟子");
        set("long", "这是少林寺的和尚。\n");
		set("vendetta_mark","shaolin");
		set("class","shaolin");
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"掸了掸屋里的尘土．\n",
        }) );
        
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        		        
		set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);
        map_skill("spells","kwan-yin-spells");  
        
        set_skill("dabei-strike",200);
        set_skill("notracesnow",200);
        set_skill("unarmed", 200);
    	set_skill("force", 200);
    	set_skill("dodge", 200);
		set_skill("parry", 200);
		set_skill("lotusforce", 150);
		set_skill("dabei-strike",120);
		set_skill("move",200);
		set_skill("essencemagic",150);
		set_skill("magic",200);
	
		map_skill("magic","essencemagic");
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	    map_skill("move","notracesnow");
	    
		setup();
		carry_object(__DIR__"obj/monk23_cloth")->wear();
}

