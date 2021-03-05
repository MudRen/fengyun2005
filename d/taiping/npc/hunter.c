#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int test(int num);

void create()
{
    	set_name("张猎户",({"hunter zhang","zhang","hunter"}));
    	set("title","百步穿杨");
    	set("long","
一个精干的汉子，拿着小刀正在仔仔细细地削着一根白杨树干。张猎户在
这儿遐迩闻名，不仅是由于他百步穿杨的弓技，更因为他擅长驯兽，能驱
使虎豹。\n");
    	
    	set("gender","男性");
    	set("age",32);
    	 	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N长叹一声说：“老子成天打鹰，今儿个却叫小雀啄瞎了眼。” \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n张猎户说：杀我这样的老实人，你不得好死啊！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"张猎户拿起削好的白杨树枝，将它弯成弓形，拿在手里比划了个架势。\n",
    	}) );    	    	

		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
	
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/shuzhi");  
    	carry_object(__DIR__"obj/hdagger")->wield();  
}


