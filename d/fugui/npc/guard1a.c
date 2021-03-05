#include <ansi.h>
inherit NPC;
object cart;

void create()
{
//	string *name = ({"风","雨","山","江"});
        set_name("金雨", ({"guard"}) );
        set("gender", "男性" );
        set("title", "金府侍卫");
        set("long", "这是一位金府侍卫，负责保卫金府安全和府内巡视的。\n");
 	set("attitude", "friendly");
	set("age", 25+random(5));
        set("gender", "男性" );
	set("cor", 20);
	set("cps", 25);
        set("combat_exp", random(30000)+75000);
        set_skill("unarmed", 60+random(30));
        set_skill("parry", 60+random(30));
        set_skill("dodge", 60+random(30));
        set_skill("move", 60+random(30));
        set("chat_chance", 1);
        set("chat_msg", ({
           "金府侍卫喊道：“闲杂人等让开！”\n",
        }) );
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
		"金府侍卫大喊道：“不好了，有人进府行窃了。”\n",
    	}) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();       
}
