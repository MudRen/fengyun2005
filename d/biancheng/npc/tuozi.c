#include <ansi.h>
inherit SMART_NPC;


int burn_it();

void create()
{
    	set_name("丁求",({"ding qiu","ding"}));
	set("title",HIY"金背驼龙"NOR);
   	set("long","
一个脸色发白的驼子穿着套崭新的青布衣裳，瘦得就像是个挂在竹杆上的
风球。不过，敢当面说他驼子的人没有一个还活在世上。\n");
     	
     	set("gender","男性");
    	set("age",52);
    	 	
    	set("int",22);
    	set("cor",30);
    	
    	set("reward_npc",1);
    	set("difficulty",5);
    	
    	set("combat_exp",52000000);  
    	set("attitude", "friendly");
    	
    	
//    	set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(:  burn_it()  :),
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({

    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","thunderwhip",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();   
    	carry_object("/obj/weapon/whip",([	"name": WHT"银龙长鞭"NOR,
    						"long": "一条银光灿灿的长鞭。\n",
    						"value": 0,
    						 ]))->wear();     
    	
    
}


int burn_it()	{
	object me,ob,coffin,env;
	
	me=this_player();
	ob=this_object();	
	
	coffin=present("coffin",environment(ob));
	
	if (coffin) {
		if (userp(coffin)) {
			command("say 这世上真有人抢着进棺材？");
			message_vision(HIR"$N一掌击在$n的脑门上。\n"NOR,ob,coffin);
			coffin->die();
			return 1;
		}
		
		if (!coffin->query("burnt") && !coffin->query("burning")) {
			command("grin");
			message_vision(HIY"$N一伸手拿出个火折子点燃了往棺材上一扔。\n"NOR,ob);
			coffin->set("burning",1);
			set("start_time",time());
			return 1;
		}
		
		if (time()>query("start_time")+20 && !coffin->query("burnt")) {
			message_vision(HIR"\n轰的一声，棺材在烈焰中倒塌了。\n"NOR,ob);
			coffin->set("burnt",1);
			coffin->delete("burning");
//			coffin->set("long", "一具烧得黑乎乎的棺材架子，什么也看不出来。\n");
			return 1;
		}
		
		if (!coffin->query("burnt"))
			message_vision(RED"火势越来越猛烈了，眼看就要把整个棺材吞没。\n"NOR,ob);
			
		
	}
	return 1;
}


void die()	{
	
	object coffin,ob;
	
	ob=this_object();
	coffin=present("coffin",environment(ob));
	
	if (coffin->query("burning")) 
		message_vision(HIG"棺材上的火势渐渐小了下去。\n"NOR,ob);
	coffin->delete("burning");
	ob->delete("start_time");
	::die();
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 5);
		return 1;
	}
	return ::heal_up() + 1;
}


void leave()
{
	object coffin;
	
	coffin=present("coffin",environment(this_object()));
	
	if (objectp(coffin))
	if (coffin->query("burning")) {
		message_vision(HIR"\n轰的一声，棺材在烈焰中倒塌了。\n"NOR,this_object());
		coffin->set("burnt",1);
		coffin->delete("burning");
	}
	message_vision("$N一纵身，跃上屋檐消失了。\n",this_object() );
	environment(this_object())->set("tuozi_out",0);
	destruct(this_object());
}
	