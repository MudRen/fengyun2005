#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;


void create()
{
    set_name("李木匠",({"carpenter li","carpenter","li"}));
    set("title","小鲁班");
    set("long","
李木匠的手艺在这太平镇上是出了名的，上至婚宴的家具，下至丧办的棺材，
都由他一家包办。\n");
    	set("gender","男性");
    	set("age",32);
    	 	
    	set("combat_exp",2200000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N满眼泪水地看了一眼屋子里的家具。。。。 \n"NOR);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n李木匠叫道：老子今天免费送你一个棺材！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"李木匠手持刨斧，兴致勃勃地在屋子里忙碌着。\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","wuche-axe",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/paxe")->wield();  
    
}
