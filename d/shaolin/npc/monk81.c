// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int do_pfm();

void create()
{
	set_name("地普", ({ "di pu", "dipu" }) );
        set("long", "这是少林寺内院的守卫僧人。\n");
        
        set("gender", "男性" );
        set("age",random(20)+ 32);
        set("cor",random(20)+20);
        set("class","shaolin");
	
	create_family("少林寺", 19, "弟子");
        
	set("vendetta_mark","shaolin");
        
        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("npc_team","shaolin_blade");
        
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("puti-steps",150);
	set_skill("dabei-strike",160);
	set_skill("lianxin-blade",150);
	set_skill("move",180);
	set_skill("force",200);
	set_skill("parry", 150);
	
	map_skill("unarmed","dabei-strike");
	map_skill("dodge","puti-steps");	
        map_skill("blade", "lianxin-blade");
        map_skill("parry", "lianxin-blade");
	map_skill("move", "puti-steps");
	
	set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: do_pfm() :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/monk21_cloth")->wear();
	carry_object(__DIR__"obj/jiblade")->wield();
}

int do_pfm(){
	object *env, ob;
	
	int i;
	ob = this_object();
	env = all_inventory(environment(this_object()));
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]!= this_object() && env[i]->query("npc_team") == "shaolin_blade")
		{
			ob->ccommand("perform yipianlianxin with "+ env[i]->query("id"));
			return 1;
		}
	}
	return 1;
}
