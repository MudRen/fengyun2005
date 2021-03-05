#include <ansi.h>
inherit NPC;

void create()
{
//	string *name = ({"一","二"});
        set_name("金二", ({"guard"}) );
        set("gender", "男性" );
        set("title", "金府家丁");
        set("long", "这是一位金府家丁，负责保卫金府安全和府内巡视的。\n");
 	set("attitude", "friendly");
	set("age", 25+random(5));
        set("gender", "男性" );
	set("cor", 20);
	set("cps", 25);
	set("force",100);
	set("max_force",100);
	set("force_factor",20);
        set("combat_exp", random(100000)+160000);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
           "金府家丁道：大帅对我等下人恩重如山，我们就是拼了命也要报答他。\n",
        }) );

        setup();

        carry_object(__DIR__"obj/cloth")->wear();       
}
