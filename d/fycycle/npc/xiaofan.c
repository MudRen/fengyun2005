//QCed and Modified by Tie
#include <ansi.h>
inherit NPC;  
inherit F_VENDOR;
int tell_test();

void create()
{
        set_name("小贩", ({ "xiaofan" }) );
        set("gender", "男性");
        set("age", 22);
	set("long",
		"这小贩左手提着个空篮子，篮上系着铜铃，不住叮铛作响。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"/obj/food_item/wineskin":10,
		"/obj/food_item/dumpling":10,
		"/obj/food_item/chicken_leg":10,
	]) ); 
        set("inquiry", ([
                "丽人" : (: tell_test :),
		"beauty" : (: tell_test :),
        ]) );
        set("chat_chance", 1);
        setup(); 
	carry_object("/obj/armor/cloth")->wear();
	
}

void init()
{
       ::init();
	if(interactive(this_player()) && !is_fighting()) {
		call_out("greeting", 1, this_player());
	}
	add_action("do_vendor_list", "list");
}      

int tell_test()
{
	object	me;

	me = this_player();
		
		command( "careful");
		command( "say 怎么总有人到处打听有没有美人？");

	return 1;
}

int greeting(object me)
{

		message_vision(HIR "\n小贩小声嘀咕，收摊了，这么多土匪，生意没法做了。\n"NOR, this_object());

	return 1;
}

int accept_object(object me, object obj)
{
//	object pai;
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，小的在这给您请安了。");
        return 1;
}