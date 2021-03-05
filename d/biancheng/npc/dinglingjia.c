#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("丁灵甲",({"ding lingjia","ding","lingjia"}));
	set("title","丁家庄 二少爷");
   	set("long","
一个很高大、很神气的棉衣少年，脸上带着种不可一世的傲气。他的确有理由
为自己而骄做的。他不但高大神气，而且非常英俊，剑一般的浓眉下，有一双
炯炯发光的眼睛，身上穿的衣服，也华丽得接近奢侈。\n");
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
		
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    
}
