inherit NPC;
#include <ansi.h>

void create()
{
	set_name("小玲珑",({ "girl" }) );
	set("nickname", HIR"娇小可爱"NOR);
        set("gender", "女性" );
        set("age", 12);
        set("long", 
"她是酸梅汤的小表妹，梳着两条小辫，一笑左边脸硖上便露出个甜甜\n的小酒窝，正在草坪上四处蹦蹦跳跳抓着蝴蝶。\n");        
	set("combat_exp", 5000);
        set("int", 15);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小玲珑说道：这四周怎么总是有股酒味，在哪儿呢，怎么找不到呢？\n",
        }) );

        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("force", 10);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/shoes")->wear();
}
