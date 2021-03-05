#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

string look_lu();

void create()
{
    	set_name("无名老人",({"anonymous oldman","oldman"}));
		set("long",(: look_lu() :));
   		set("gender","男性");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","longfenghuan",1);
	
		setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
    	carry_object("/obj/weapon/hammer/tiedan")->wield(); 
 
}



string look_lu(){
	this_player()->set_temp("marks/kuaihuo/快活林_陆漫天",1);
	return "这人的身材高大，很魁伟穿着件淡青色的长袍，花白的头发挽了发髻，手
里叮当作响，像是握着两枚铁胆。\n";
}