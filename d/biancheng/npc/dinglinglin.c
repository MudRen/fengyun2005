#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("丁灵琳",({"ding linglin","ding","linglin"}));
	set("title","要命的");
   	set("long","
她穿着件轻飘飘的月白衫子，雪白的脖子上，戴着个金圈圈，金圈圈上还挂着
两枚金铃裆。她手上也戴着个金圈圈，上面有两枚金铃裆，风吹过的时候，全
身的铃裆就“叮铃铃”的响。。\n");
     	set("gender","男性");
    	set("age",32);
    	 	
    	set("reward_npc",1);
    	set("difficulty",5);
    	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	
    	
    	set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"丁灵琳笑得花枝招展，全身的铃裆也开始“叮铃铃”的直响。\n",
		"丁灵琳笑了。她笑起来的时候，身上的铃档又在“叮铃铃”的响，就像她的笑声一样清
悦动人。\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    
}
