inherit NPC;
#include <ansi.h>

void create()
{
	set_name("小金刚",({ "boy" }) );
	set("nickname", HIG"虎头虎脑"NOR);
        set("gender", "男性" );
        set("age", 12);
        set("long", "他是酸梅汤的小表弟，梳着两条小辫，一笑右边脸硖上便露出个甜甜\n的小酒窝，正在草坪上四处蹦蹦跳跳抓着蝴蝶。\n\n");
	set("combat_exp", 5000);
	set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("force", 20);
        set("int", 15);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小金刚说道：这四周怎么总是有股酒味，在哪儿呢，怎么找不到呢？\n\n",
        }) );
     
        set("attitude", "friendly");
        
        setup();
        carry_object(__DIR__"obj/underwear")->wear();
        carry_object(__DIR__"obj/tigershoes")->wear();
}
