#include <ansi.h>
inherit SMART_NPC;
int give_mission();
void create()
{
	set_name("沈浪", ({ "shen lang","shen" }) );
	set("gender", "男性" );
	set("title", "情侠" );
	set("nickname", HIC"仗剑江湖载酒行"NOR );
	set("long","
一个剑眉星目的英俊少年，嘴角微微向上，不笑时也带着三分笑意，神情
虽然懒散，但那种对什么事都满不在乎的味道，却说不出的令人喜欢。 \n"
		);
	set("attitude", "peaceful");
	set("reward_npc", 1);
	set("difficulty", 10);
	set("age", 23);
	set("combat_exp", 8500000);

	set("inquiry",([
		"朱七七" : (: give_mission :),
	]) );

	set("chat_chance", 2);
	set("chat_msg", ({
		"沈浪叹了口气，喃喃自语：七七，你在哪里？ \n",
	}));
	
   		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
	
	auto_npc_setup("tang",190,150,0,"/obj/weapon/","fighter_w","tempestsword",4);            
	setup();
    carry_object(__DIR__"obj/sword1")->wield();
	carry_object("/obj/armor/cloth")->wear();
}

int give_mission()
{
	object me,jade;
	object ob;
	me=this_player();
	
	if (ob=present("bai feifei", environment(this_object())))
	{
		message_vision("$N扭过脸看着$n，叹了口气，默然无语。\n",this_object(),ob);
	}
	else if( userp(me) && me->query_temp("marks/chai_notify_bai"))
	{
		if(!me->query_temp("marks/chai_get_jade"))
		{
			command("consider");
			message_vision("$N突然转过头，目光如炬看着$n，突然微微一笑：你不是方心骑......\n",this_object(),me);
			message_vision("$N掏出一块玉璧，笑道：英雄，请把这玉璧交给七七，她自然知道我一切无恙。\n",this_object());
			jade = new(__DIR__"obj/jade");
			jade->move(me);
			me->set_temp("marks/chai_get_jade",1);
		}
		else
		{
			message_vision("$N笑道：这位英雄，可曾见到七七，她一切可好？\n",this_object());
		}
	}
	else
	{
		message_vision("$N脸上露出一丝甜甜的微笑：七七，她是个很怪的女孩子......\n",this_object());
	}
	return 1;
}

int accept_object(object me, object obj)
{	
       	object npc;
       	object book;
       	object *inv;
		int i;
		int j;
		j = 0;
		npc = this_object();
		if( userp(me))
		{
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				if(inv[i]->query("item_owner")=="方心骑" && (int)inv[i]->query("equipped"))
				{
					j = 1;
				}
			}
		}
       	if (me->query_temp("marks/knight_kill_wang") 
       		&& obj->query("name") == "樟木镶金箱" 
       		&& j == 1)
       	{
			message_vision(HIY"$N神色凝重看着箱子中的白飞飞，长长叹了口气．．．．\n"NOR,npc);
			message_vision(HIY"$N掏出一本绢册，肃然道：这是我父＂九州王＂沈天君毕生心血，你可以参详一下！\n"NOR,npc);
        	book = new(BOOKS"skill/xuanyuan-axe_50");
        	if (book) book->move(me);
        	REWARD_D->riddle_done( me, "楼兰孽缘" ,50, 2);
        	call_out("leave",2,me);
        	return 1;
        }
        else
        	return notify_fail("沈浪摇头微笑，默然不语。\n");	
}

void leave(object me)
{
	object ob;
	if (living(this_object()) && environment(me) == environment())
	{
		message_vision(HIY"$N霍然长身而起，背起白飞飞，苦笑了声道：不能再装了，我这就去解救七七
和王怜花，他日有幸，必能重逢！\n"NOR,this_object(),me);
		message_vision(HIY"长啸声中，$N纵身离去！\n"NOR,this_object());
		destruct(this_object());
	}
	remove_call_out("leave");
}
