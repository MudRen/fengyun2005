// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("风清", ({ "fengqing" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺风字辈大师");
        set("long", "他是兴国禅寺中颇有威望的风字辈大师。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");

	set("age", random(40)+20);
        set("cor", 24);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "风清看了看自己的断腿，苦笑了一下。\n",
        }) );
        set("inquiry", ([
                "断腿" : "我的腿是在火沼中被一把喷火的刀砍断的。\n",
                "leg" : "我的腿是在火沼中被一把喷火的刀砍断的。\n",
				"火沼":	"火沼就是沉香镇南面的火沼泽，我们去了、败了，空闻大师功力最高，
竟然第一个就倒下。\n",
				"喷火的刀": "其实喷火的并不是刀，而是用刀的人－－火巨灵，我挡住了他的刀，却挡不住他的火。\n",
				"火":	"我苦苦思索，唯有用天湖寒冰之水淬过（ｄｉｐ）的武器才能破去火巨灵的火。
但是那孽龙却又不同，需要以毒攻毒，以火对火方行。\n",
				"以毒攻毒":	"我猜。。是用喷火的刀杀喷火的龙！\n",
				"以火对火":	"我猜。。是用喷火的刀杀喷火的龙！\n",
				"火巨灵":"火巨灵是生活在火沼泽中的异族人。\n",
				"天湖":	"天湖在关外天山脚下。\n",
				
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
