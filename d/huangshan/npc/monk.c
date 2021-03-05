// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("空光", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(10)+ 32);
        set("long", "这是少林寺出外化斋的和尚，奉方丈之命来化解武林人士和少林的纠纷。
（十两银子可化解二十点怨气，一两黄金可化解所有怨气）\n");
        create_family("少林寺", 23, "弟子");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
			"空光唱了个肥诺道：＂施主若是造孽过多，捐点香火钱吧！＂\n",
        }) );    
        set_skill("unarmed", 5+random(40));
		set_skill("dabei-strike",random(40)+5);
		map_skill("unarmed","dabei-strike");
		set_skill("move",40);
		set_skill("force",20);
	
		set("NO_KILL","空光说：施主怎么又想造孽了，善哉善哉。\n");
		setup();

		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/bowl");
}



int accept_object(object who, object ob)
{
		int num;
		num=who->query("vendetta/shaolin");
		if( ob->value() >= 10000
			||(ob->value() >= 1000 && num<=20)) {
                        command( "say 善哉善哉，放下屠刀，回头是岸...");
                        command( "say 贫僧会为施主每日焚香一柱，诵经三卷。\n");
                        who->set("vendetta/shaolin", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                    	command("say 施主罪孽深重，这点怕是。。。\n");
                        return 0;
                }
        return 0;
} 
