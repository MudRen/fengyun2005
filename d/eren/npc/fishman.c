#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("王小路",({"fishman xiaolu","fishman","wang"}));
    	set("title","网开一面");
    	set("long","
王小路是村里鱼塘的主人，他整天总是乐呵呵的，打鱼时见好就收，所以
得了个外号叫“网开一面”。。\n");

    	set("gender","男性");
    	set("age",42);


    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
        	"龙鲤鱼" :	"什么龙鲤鱼，没听说过。\n",
             	"神仙鱼" :	"神仙鱼啊，只有在沼泽地附近才能钓到。。\n",
             	"鱼饵" :	"钓不同的鱼得用不同的鱼饵，你想要哪一种？\n",
             	"鱼竿" :	"自己去做一个，很容易的。\n",
             	"bait" :	"钓不同的鱼得用不同的鱼饵，你想要哪一种？\n",
             	"fishpole" :	"自己去做一个，很容易的。\n",
             	"红蚯蚓" :	"这你可找对地方了，这附近草地里就有很多，你自己去挖就成了。\n",      	
             	"王大路" :	"大路是我的双胞胎哥哥，也是个渔夫。\n",      	
   	]));
    	
    	set("death_msg",CYN"\n$N叹口气说：我真想再能去钓一次鱼。。 \n"NOR);
       	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n王小路叫道：来人啊，杀人啦！！！\n",
        ]) );    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"王小路说：捕鱼要网开一面，才能细水长流。\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fumostaff",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/staff")->wield();  
    	
    
}
