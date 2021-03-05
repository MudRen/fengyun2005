// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
int do_pfm();

void create()
{
        string *name = ({"灭","空","孟","去","可","心","明","吝","迩","奇","足","位"});
        set_name("圆"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("class","shaolin");
        set("age",random(20)+ 32);
		create_family("少林寺", 22, "弟子");
        set("long", "这是少林寺的和尚\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set("shaolin_blade",1);
        set("npc_team","shaolin_blade");
        
        set("inquiry", ([
        	"施舍":		"二十两银子，少林观光一日游，哈哈！\n",
        	"香火":		"二十两银子，少林观光一日游，哈哈！\n",
        	"游山牌":	"二十两银子，少林观光一日游，哈哈！\n",
        ]));	
        
        set_skill("blade", 60+random(100));
        set_skill("dodge", 60+random(60));
        set_skill("puti-steps",60);
		set_skill("dabei-strike",60);
		set_skill("lianxin-blade",random(100)+50);
		set_skill("move",80);
		set_skill("force",200);
		set_skill("parry",80);
		map_skill("parry", "lianxin-blade");
		map_skill("unarmed","dabei-strike");
		map_skill("dodge","puti-steps");	
        map_skill("blade", "lianxin-blade");
        
      	set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：近来寺内香火不旺啊，施主是否能够"YEL"施舍"NOR"些？\n",
        }) );
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: do_pfm() :),
        }) );
        
        setup();
		carry_object(__DIR__"obj/monk22_cloth")->wear();
		carry_object(__DIR__"obj/jiblade")->wield();
}


int accept_object(object who, object ob)
{
            if( (int)ob->value() >= 2000 ) {
                say( name()+"掂了掂手中的"+ob->name()+"，微笑道：啊？？．．哈哈哈．．\n");
				say( name()+"顺手将"+ob->name()+"揣入了怀中。\n");
                tell_object(who,name()+"悄悄地说：正门不太方便，走边门吧。\n");
                who->set_temp("shaolin", 1);
                return 1;
            } else {
				command("shake");
                return 0;
            }
        return 0;
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
			ob->ccommand("perform yipianlianxin with "+ env[i]->query("id")+" 2");
			return 1;
		}
	}
	return 1;
}
