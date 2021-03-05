#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("毛贼头目", ({ "thief leader", "leader" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 20);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这个毛贼面有菜色，好像饿了三天，衣服破破烂烂，连手中的刀都是锈的。
LONG
);
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("chat_chance", 3);
        set("chat_msg", ({
			(: checking :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "毛贼头目显然是刚刚入行，刀刀偏离目标数尺。\n",
              "毛贼头目高喊：抢银子啊，抢了银子，老婆孩子就有饭吃了。\n",
        }) );

        set("force",500);
        set("force_factor",10);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        setup();
        carry_object(__DIR__"obj/caidao")->wield();
        carry_object(__DIR__"obj/pocloth")->wear();
}

void init()
{
        ::init();
	add_action("do_accept", "accept");
	add_action("do_forgive", "forgive");
}

void win_enemy(object loser)
{
	object cart;
	object robber;
	cart = present("silver cart",environment());
	robber = this_object();
	
	command("laugh");
	command("say 这位" + RANK_D->query_respect(loser)+ "，这种身手还出来护镖，笑掉老子的大牙了！\n");
        if ( present("silver cart",environment(this_object())) )
        {
        	message_vision("$N推着镖车呼啸而去。\n", robber);
        	destruct(cart);
        }
        destruct(robber);
        return;
}

void lose_enemy( object winner )
{
	object robber;
	robber = this_object();
	winner->set_temp("marks/winner",1);

	command("cry");
	command("say 小人上有八十老母，下有三岁子女，一家老少全靠我撑着啊！\n");
	command("say 这位" + RANK_D->query_respect(winner)+ "，你大仁大义，就饶了(forgive yes/no)小的一条狗命吧！\n");
}

int do_forgive(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if (me->query_temp("marks/forgiveok") || me->query_temp("marks/forgiveno"))
		return 0;
	if(arg == "yes" && me->query_temp("marks/winner")) 
	{
		me->set_temp("marks/forgiveok", 1);
		message_vision(HIY"$N扑通一声跪到地上：英雄啊！您真是神勇无敌，仁义无匹啊．．．\n"NOR,ob);
		message_vision(HIY"$N痛苦流涕：小人一定洗心革面，重新做人！\n"NOR,ob);
		call_out("goingon",2,ob);
		return 1;
	}
	if(arg == "no")
	{
		message_vision("$N大叫：我跟你拼了！．．．\n",ob);
		me->set_temp("marks/forgiveno",1);
		this_object()->kill_ob(me);
		return 1;
	}
	else
		return 0;
}

void goingon(object ob)
{
	message_vision(HIY"$N叹息道：只是小人身无长技，除了做贼，实在不知可以做什么.....\n"NOR,ob);
	message_vision(HIY"$N又道：就算做买卖，也要有本钱，可是小人.....\n"NOR,ob);
	message_vision(HIY"$N偷偷向镖车瞅了瞅，露出羡慕的目光.....\n"NOR,ob);
}


int accept_object(object me, object ob)
{
	object robber;
	robber = this_object();
	
	if(ob->query("name") == "金大帅府镖银" && ob->query_amount() == 4000 && me->query_temp("marks/得到镖银") && me->query_temp("marks/forgiveok"))
	{
		message_vision("$N几乎被这些可怜的人感动的哭了.....\n",me);
		message_vision("$N指了指镖车，你们要银子做本钱是吧，我有！.....\n",me);
		me->set("marks/救济劫匪",1);
		me->delete_temp("marks/得到镖银");
		message_vision("$N千恩万谢的拿着银子走了。\n",robber);
		call_out("robber_gone",2,robber);
		me->start_busy(3);
		return 1;
	}
	else
	{
	       	tell_object(me,"毛贼头目说道：您肯饶我一条狗命就行，我哪里敢要您的东西。\n");
        	return 0;  
        }    
}

void checking()
{
        object robber;
        robber = this_object();
        if (robber->is_fighting()) 
        {
        	if((int)robber->query("kee")* 100 / (int)robber->query("max_kee") <= 80)
        	{
                	if (!living(robber)) 
                		return;
               		else 
                	{
               			message_vision("\n$N叫道：点子扎手，加把劲啊！\n\n",robber);
                        	return;
                	}
       		}
        }
}

void robber_gone(object ob)
{
	destruct(ob);
}
