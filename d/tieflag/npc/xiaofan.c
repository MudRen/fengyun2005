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
		"这小贩左手提着个篮子，右手提着个酒壶。篮上系着铜铃，不住叮铛作响。\n");
		set("combat_exp", 5);
		set("attitude", "friendly");
		set("rank_info/respect", "小二哥");
		set("vendor_goods", ([
			"/obj/food_item/wineskin":	99,
			"/d/tieflag/npc/obj/beefmeat":	99,
			"/d/tieflag/npc/obj/dongskin":	99,
	          	"/obj/food_item/dumpling":	99,
			"/obj/food_item/chicken_leg":	99,
		]) ); 
        set("inquiry", ([
                "丽人" : (: tell_test :),
				"beauty" : (: tell_test :),
				"leaf" : (: tell_test :),
				"树叶" : (: tell_test :)
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小贩涎着脸说：刚才有位丽人给我一片"YEL"树叶"NOR"。。。。\n"
        }) ); 
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
		
		if (!me->query_temp("mark/阴宾")){
			command("consider");
			command("say 这事儿和你没关系吧。");
			return 1;
		}
			
		command( "say 方才有辆极为华丽的马车自林子走过。");
		command( "say 车上一位丽人说要我等在路上，");
		command( "say 若是有人来问我有没有瞧见路上一行如那般的人走过");
		command( "say 我就可卖片树叶给他，只可卖十两银子，一分不能多要。");
		command( "cry");
	return 1;
}

int greeting(object me)
{

		message_vision(HIR "\n小贩大声叫卖:牛肉，美酒。\n"NOR, this_object());
		return 1;
}

int accept_object(object me, object obj)
{
	object pai;
	if( (int) obj->value() >= (1000) && me->query_temp("mark/阴宾") )
	{
        command("smile");
		pai = new("/d/tieflag/npc/obj/shuye");
		if(pai)
		pai->move(me);
        message_vision("$N拿出树叶给$n。\n",this_object(),me);
        me->set_temp("mark/阴宾", 0);
		me->set("annie/阴宾",1);
		return 1;	
	}

else
        {
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，小的在这给您请安了。");
        return 1;
        }
}

void reset(){
		set("vendor_goods", ([
			"/obj/food_item/wineskin":	99,
			"/d/tieflag/npc/obj/beefmeat":	99,
			"/d/tieflag/npc/obj/dongskin":	99,
	          	"/obj/food_item/dumpling":	99,
			"/obj/food_item/chicken_leg":	99,
		]) ); 
		
}