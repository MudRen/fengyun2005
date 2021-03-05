// apstone, inc. c 1998
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李豹", ({ "lee", "lee bao" }) );
        set("long","
新疆的最大的盐行老板，人家都称他为＂李老大＂，李豹管的是这儿盐矿的
开采，不过，装盐可是个体力活，一味贪钱小心累死。\n");
		set("gender","男性");
		set("age", 39);
		set("no_arrest",1);
        set("combat_exp", 100000);
		set_skill("unarmed",100);
		set_skill("luohan-quan",100);
		map_skill("unarmed","shuaijiao");
        set("chat_chance", 1);
        set("chat_msg", ({
                "李豹道：缺银子花么？帮我装盐（work），一马车一两银子！\n",
                "李豹指着你：别偷懒，快干活！\n",
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}

int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
	
		if (query("worked")>20)
			return notify_fail("李豹说：今天告一段落，明天再继续招工。\n");
			
		if(me->is_busy()) 
			return notify_fail("你的动作还没有完成，不能工作。\n");
		message_vision("$N装满了一车盐，可人也累的要死。\n",me);
		tell_object(me,"你靠在盐车旁呼呼地喘着粗气。\n");
		
		if (random (me->query("kar"))>10 && !environment()->query("already")) {
			tell_object(me,"你注意到湖底某处的盐块有些松动，如果有趁手的工具也许可以掘点出来。\n");
			me->set_temp("marks/xj_noticed_salt",1);
		}
		add("worked",1);
		
		me->receive_damage("gin",120,me);
		me->receive_damage("sen",120, me);
		me->set_temp("last_damage_from","在新疆盐行干活劳累过度而死。\n");
		ob = new("/obj/money/silver");
		
		if (!ob->move(me))
			ob->move(environment(me));		
		message_vision("李豹干笑了两声，对$N说：这是你的工钱。\n", me);
		
		 if (QUESTS_D->verify_quest(me,"新疆装盐")) 
		 	QUESTS_D->special_reward(me,"新疆装盐");
		
		me->perform_busy(2);
		return 1;
}


void reset(){
	set("worked",0);
}