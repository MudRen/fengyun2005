// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("空寒", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(10)+ 32);
        set("long", "这是少林寺出外化斋的和尚。\n");
	set("vendetta_mark","shaolin");
        create_family("少林寺", 23, "弟子");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
		"空寒唱了个肥诺道：＂施主捐点香火钱吧！＂\n",
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :)
        }) );
        set_skill("unarmed", 5+random(40));
	set_skill("dabei-strike",random(40)+5);
	map_skill("unarmed","dabei-strike");
	set_skill("move",40);
	set_skill("force",20);
	set("force",100);
        set("max_force",100);
	set("force_factor",2);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/bowl");
}

int accept_object(object me, object obj)
{
command("sigh");
command("say 日子难过呀！\n");
command("say 寺内的藏经楼总是丢书，方丈现在动不动就责罚弟子面壁十年！\n");
command("thank " + me->query("id"));
return 1;

}
