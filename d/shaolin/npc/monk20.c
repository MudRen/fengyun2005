// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("中年和尚", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 20, "弟子");
        set("gender", "男性" );
        set("age",random(20)+ 32);
	set("nickname",HIW"佛剑"NOR);
        set("long", "这是少林寺的剑僧。\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        
        set_skill("sword", 200);
	set_skill("suiyuan-sword",160);
	set_skill("move",200);
	set_skill("force",200);
	set_skill("dodge",150);
	set_skill("puti-steps",150);
	set_skill("parry",160);
	set_skill("unarmed",200);
	set_skill("dabei-strike",200);
	map_skill("sword","suiyuan-sword");
	map_skill("dodge","puti-steps");
	map_skill("parry", "suiyuan-sword");
	map_skill("move","puti-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		name()+"笑道：在少林寺撒野？\n",
                (: perform_action, "sword.yiqiesuiyuan" :),
        }) );
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"舞动长棍，全身毫无破绽，扬起一溜尘土。\n",
                name()+"一不小心，差点从梅花桩上掉下来！\n",
                name()+"拿起一块青砖猛然向自己的前额回去。。。青砖应声而裂！\n",
		name()+"将手中八十斤的大刀耍得象一朵花儿似的。\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk20_cloth")->wear();
	carry_object(__DIR__"obj/monk_sword")->wield();
	
}

