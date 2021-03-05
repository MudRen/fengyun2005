#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    set_name("孙剃头",({"barber sun","barber","sun"}));
    set("title","斩草除根");
    set("long","
孙剃头原名孙福贵，以给人理发为生，有次喝醉酒把顾客的眉毛胡子剃了
个精光。从此就得了个斩草除根的绰号。\n");
     	set("gender","男性");
    	set("age",52);
    	
    	set("combat_exp",1200000);  
    	set("attitude", "friendly");
    	  	
  		set("inquiry", ([
        	"剃头" : 	"客官想理发？请先坐下吧！（ｓｉｔｄｏｗｎ）\n",
           	"haircut" : 	"客官想理发？请先坐下吧！（ｓｉｔｄｏｗｎ）\n",
   		]));
		
  
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n孙剃头说：我这辈子没伤过一个人啊，为什么啊！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"孙剃头笑眯眯地说：客官要剃头么？\n",
    	}) );    	    	
 
    	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/blade")->wield();  
    
}


void 	init(){
	::init();
	add_action("do_haircut","sitdown");
}


int 	do_haircut(){
	object sun,me;
	me=this_player();
	
	if (me->is_fighting() || me->is_busy()) 
		return notify_fail("你现在正忙。\n");
	if (is_busy())
		return notify_fail("孙剃头正忙着呢。\n");
	
	message_vision(CYN"孙剃头朝着$n左打量右打量，叹了口气说：“你这个头，歪瓜烂枣的，没法剃呀！”\n"NOR,this_object(),me);
	return 1;
}


	
	