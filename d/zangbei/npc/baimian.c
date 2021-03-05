#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("白面郎中",({"baimian langzhong","baimian","langzhong"}));
		set("title",YEL"龙虎寨 老二"NOR);
   		set("long","
白面郎中是龙虎寨的二当家。他的脸部不很白，也从没做过郎中，不过，绿林
好汉若没有一个响亮的外号，那还成什么绿林好汉，所以他几乎已将自己本来
名字忘了。\n");
     	
     	set("gender","男性");
     	set("group","longhuzhai");
     	
    	set("age",32); 	 	
    	    	
    	set("reward_npc",2);
    	
    	set("longhu_boss", 1);
    	set("combat_exp",4500000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n$N说：“善者不来，来者不善啊。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"白面郎中道：“我们这里的人本来就不喜欢打架的。”\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/gsword")->wield();    
    
}


void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
        	if(owner=me->query("possessed")) me = owner;
//        	if (REWARD_D->riddle_check(me,"义助宋福贵")==1)
        		me->set("marks/longhuzhai/白面郎中",1);
        }
        ::die();
}
