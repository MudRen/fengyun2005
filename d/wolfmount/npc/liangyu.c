#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("温良玉", ({"wen liangyu", "liangyu","wen" }));
	set("nickname", HIC"谦谦君子"NOR HIG"温良如玉"NOR );
	set("gender", "男性");
	set("age", 42);
	set("long",	"白衣高冠，温文儒雅，手里轻摇着一把折扇，看上去可佩可亲。\n");
	set("attitude","friendly");
	create_family("狼山", 3, "大头领");
	
/*	set("apprentice_available", 5);
	set("rank_nogen",1); 
	set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));	*/
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.luori" :),
	}) );
	
	set("chat_chance", 1);
	set("chat_msg", ({
		"太阳使者慢慢道：“你若是诚心皈依，我就收容你。引导你到极乐和永生。” \n",
	}));
       
    set("combat_exp", 10000000);
	set("score", -50000);
	
	set_skill("force", 150);
	set_skill("bibo-force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("luoriquan", 220);
	set_skill("move", 180);
	set_skill("fengyu-piaoxiang", 200);
	set_skill("parry", 200);
	
	map_skill("force"  , "bibo-force");
	map_skill("unarmed", "luoriquan");
	map_skill("dodge"  , "fengyu-piaoxiang");
	map_skill("move"  , "fengyu-piaoxiang");
	
	setup();
	carry_object(__DIR__"obj/mask")->wear();
	carry_object(__DIR__"obj/silkcloth")->wear();
}

void die()
{
	object me, xiaoma, killer;
	object grass;

	if (xiaoma = present("xiao ma", environment()))
		xiaoma->delete_scene();

	if(objectp(me = query_temp("last_damage_from")))
	{
		if (objectp(killer = me->query("possessed")))
			me = killer;
			
		command("say 都怪我大意，纵虎归山。悔之晚矣！\n");
		me->set("marks/杀太阳使者",1);
		grass = new(__DIR__"obj/grass");
		grass->move(this_object());
	}
	 ::die();
}

void init()
{
	object me;
	::init();      
	if( interactive(me = this_player()) && !is_fighting()) 
	{
		call_out("greeting", 1, me);
	}
	add_action("do_kill", "kill");
}

int greeting(object me)
{
	object npc;
	object xiaoma;
	npc = this_object();
	if ( me->query_temp("marks/wolf_xiaoma_good") )
	{
        	message_vision(HIY "$N冷笑道：嘿嘿，怪不得小马这么有勇气，原来是找了个帮手，还等什么？\n"NOR, npc);
	}
	else
	{
        	message_vision(HIY "$N缓缓道：诚心皈依我吧，你会永享极乐！\n"NOR, npc);
	}
	return 1; 
}


int do_kill(string arg)
{
        object me,ob;
        me = this_player();
        ob = this_object();

		if (!arg)	return 0;		
		if (!present(arg,environment()))	return 0;
		
		if (ob!= present(arg,environment()))	return 0;	
		
		me->kill_ob(ob);
       	ob->kill_ob(me);
   		environment(me)->kill_notify(ob,0);
    	return 1;
}
