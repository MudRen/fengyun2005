#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int secret();

void create()
{
    	set_name("老大",({"laoda"}));
    	set("title","七杀手");
    	set_temp("condition_type",RED"< 奄奄一息 >"NOR);
    	set("long","
这人身上一袭黑衣，腰问一条红缎带，挂一口带鞘长刀，不过，刀鞘还在，
刀却不知去向，人也是奄奄一息。\n");
     	set("gender","男性");
    	set("age",52);
    	
    	set("combat_exp",3200000);  
    	set("no_heal",1);
    	
    	set("eff_kee",2000);
    	set("eff_sen",2000);
    	set("eff_gin",2000);
    	set("kee",2000);
    	set("sen",2000);
    	set("gin",2000);
    	  	
	  	set("inquiry", ([
	        	"鬼":		"老蛔虫、他、他，一举手就毁了我六个兄弟。",
	        	"老蛔虫":	"老蛔虫、他、他，一举手就毁了我六个兄弟。",
	        	"六个兄弟":		(: secret :),
	        	"兄弟":			(: secret :),
	        	"*":	"厄。。。。厄。。。\n",
	   	]));
		
  
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n老大说：我跟你拼了！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"老大惊恐地说：“那不是人，是"YEL"鬼"NOR"，是"YEL"鬼"NOR"！！”\n",
    	}) );    	    	
 
    	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();  
    
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1+random(3), ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			message_vision("老大惊恐地说：“那不是人，是鬼，是鬼！！”\n",this_object());
			break;
		case 1:
			message_vision("老大喉咙里咕咕几声，又吐出一口血来。\n",this_object());
			break;
		case 2:
			message_vision("老大挣扎着用手在地上摸索着什么。。。\n",this_object());
			break;
	}
}

int secret(){
	
	message_vision(CYN"老大喉咙里咕咕几声，又吐出一口血来。
老大艰难地说：三爷。。武三爷出一千两金子让我们七兄弟去抓血奴，我。我们
几乎已经得手，没想到被老蛔虫半路截住，他、他只用一只手就毁了我的兄弟们，
我也活不成了。。。。\n"NOR, this_object());
	this_player()->set("marks/parrot/七杀手",1);
	return 1;

}