// 
inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("红鼻子老头", ({ "rednose man", "man" }) );
    	set("gender", "男性" );
	set("nickname", "挑担卖酒的");
    	set("age", 50);
    	set("long","
他衣衫穿得虽褴褛，但脸上却带着种乐天知命的神气，别人虽认
为他日子过得并不怎样，他自己却觉得很满意。 \n");
	set("per", 4);
	set("combat_exp", 2000);
    	set("attitude", "friendly");
   	set("chat_chance", 1);
   	set("chat_msg", ({
   		"红鼻子老头扯开喉咙叫道：“好清好甜的‘竹叶青’一碗下肚有精神，两碗下
肚精神足，三碗下—肚，神仙也不如。\n",
		"红鼻子老头高声叫道：“好清好甜的‘竹叶青’，客官们喝两碗吧！错过了这
里，附近几百里地里也喝不到这样的好酒了。\n", 
 	}));

    	set("vendor_goods", ([
    		"/obj/food_item/winebowl" : 120,
    		"/obj/food_item/horsebean" : 120,
    		"/obj/food_item/peanut" : 120,
    	]) );
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

void reset(){

    	set("vendor_goods", ([
    		"/obj/food_item/winebowl" : 120,
    		"/obj/food_item/horsebean" : 120,
    		"/obj/food_item/peanut" : 120,
    	]) );	
	
}