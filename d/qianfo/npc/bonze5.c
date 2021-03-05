// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SMART_NPC;
int give_qin();
void create()
{
        set_name("云流", ({ "yunliu" }) );
        set("gender", "男性" );
        set("class", "bonze");
		set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);

        set("long", "他是兴国禅寺中颇有威望的云字辈大师。\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
               
        set_skill("dabei-strike",100);
        set_skill("notracesnow",100);
        set_skill("unarmed", 100);
    	set_skill("force", 100);
    	set_skill("dodge", 100);
	    set_skill("parry", 100);
	    set_skill("cloudstaff", 170);
	    set_skill("lotusforce", 150);
	    set_skill("notracesnow",120);
	    set_skill("dabei-strike",120);
	    set_skill("move",120);
	
	    map_skill("staff", "cloudstaff");
	    map_skill("parry", "cloudstaff");
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
	 
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "云流瞪了你一眼，对你全身上下狂摸一气道：
你是千年难遇的练武奇材！！
我听说东南方的大莽林中一座山庄里有一"YEL"异人"NOR"，你可去拜他为师！！\n",
        }) );
        set("inquiry", ([
             "异人" : "我听说要想见异人，先需会"YEL"弹琴"NOR"．．\n",
             "yiren" : "我听说要想见异人，先需会"YEL"弹琴"NOR"．．\n",
			 "弹琴" :  (: give_qin :),
			 "tanqin" : (: give_qin :),
			 "qin" : (: give_qin :),
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

int give_qin()
{
        object obj,ob;
		if(query("given")<2)
        {
			command("say 这把古琴你拿去练吧！！\n");
			obj = new(__DIR__"obj/qin");
			if (!obj->move(this_player()))
				destruct(obj);
			add("given",1);
			set("give_to", this_player());
        }
		else
		{
			if (objectp(ob=query("give_to")))
				command("say 我的古琴已送给"+ob->query("name")+"了！\n");
			else
				command("say 你来晚了，我的琴已经送人了。\n");
		}
		return 1;
}


void reset()
{
		delete("given");
}

