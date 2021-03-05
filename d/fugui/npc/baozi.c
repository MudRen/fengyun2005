inherit NPC;
#include <ansi.h>

void create()
{
        int i,amun;

        set_name("飞豹子", ( { "fei baozi","baozi" }) );
	set("nickname", HIY"虎背熊腰"NOR);
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"他是酸梅汤的堂哥，长得人如其名，虎背熊腰，精神似乎格外抖擞。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "飞豹子翘起鼻子，使劲的嗅嗅：“这四周怎么总是有股酒味，在哪儿呢？”\n"
        }) );

	set("attitude", "peaceful");
	set("combat_exp", 50000);
        set_skill("unarmed", 50);
        set_skill("dodge", 100);
        set_skill("taiji", 50);
        map_skill("unarmed", "taiji");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}