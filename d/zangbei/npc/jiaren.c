#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("老家人",({"lao jiaren","jiaren"}));
	set("title","薛家庄");
   	set("long","
一个白发苍苍的老家人，身子佝偻。他幼时本是薛斌的书童，在薛家已近六
十年。少年时，他也是个精壮的小伙子，也舞得起三十斤重的铁斧，也杀过
些绿林好汉。但现在，他不但背已驼，腰已弯，身上的肌肉已松弛，而且还
得了气喘病，走几步路都会喘起来。\n");
     	set("gender","男性");
    	set("age",72);
    	 	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	    	
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
    	    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/jiapu");
    	
}
