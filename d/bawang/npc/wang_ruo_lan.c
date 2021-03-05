#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name( "王若兰", ({ "wang ruolan", "wang","ruolan" }) );
		set("long", "王若兰是王老镖头的独生女儿，也是当今霸王枪法的唯一传人。
一袭白衣，显出她浮凸有致的娇好身材。一对秋水搬的双眸，正幽怨的望着丁喜。\n");
		set("attitude", "friendly");
		set("title", HIM "如花似玉"NOR);
		set("age", 17);
        set("gender", "女性" );
		set("per", 60);
		set("class","fugui");
		set("combat_exp", 4000000);
        set("reward_npc", 1);
		set("difficulty", 5);
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear3",1); 
	
		setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
        carry_object(__DIR__"obj/gold_spear")->wield();
}

int accept_object(object me, object obj)
{
		object book;
		if( (string) obj->query("name") == HIR"霸王枪"NOR)
		{
	        message_vision("$N向$n道了个万福：\n",this_object(),me);
	        command("smile");
			command("say 多谢这位" + RANK_D->query_respect(me) + "替我找回了丢失的霸王枪。\n");
		
			if ( REWARD_D->riddle_check( me, "镖局内奸")==2) {
				command ("say 你替我们识破了归东景的阴谋，作为答谢，这本霸王枪谱，就送给您吧！");
				book = new(BOOKS"skill/xuezhan-spear_50");
				if(book) book->move(me);
				book = new(BOOKS"spear_75");
				if(book) book->move(me);
		        message_vision("$N从怀中掏出两本枪谱送给$n。\n",this_object(),me);
				REWARD_D->riddle_done( me, "镖局内奸", 50, 1);
			} 		
		return 1;	
	}
	else
	{
		command("lean");
		command("say 多谢这位" + RANK_D->query_respect(me) + "，什么我都不要，只要他在我身边就好。\n");
		return 0;
	}


        return 1;
}
