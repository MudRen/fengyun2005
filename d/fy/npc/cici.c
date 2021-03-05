// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
		set_name("笑笑", ({ "xiao xiao", "cici"}) );
        set("gender", "女性" );
        set("title",HIR"探花阁"NOR);
        set("age", 22);
        set("long", "笑笑爱笑，因此得名，人间多有不如意之事，一笑解千愁。
笑笑在这里为客人斟茶，上菜，人见人爱。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
		set("no_fly",1);
		set("NO_KILL",1);
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "笑笑说：客官若要打水，那儿有水壶。\n",
        }) );        
                
		set("vendor_goods", ([
			"/obj/food_item/shuihu" : 30,
			"/obj/food_item/shaobing" : 30,
		]) );
		setup();
		carry_object("/obj/armor/cloth")->wear();
	
}

void init()
{	
		add_action("do_vendor_list", "list");
}

void reset()
{
        set("vendor_goods", ([
		"/obj/food_item/shuihu" : 30,
		"/obj/food_item/shaobing" : 30,
        ]) );
}
