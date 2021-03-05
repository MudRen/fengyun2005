#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("伛偻老头",({"old singer","singer","oldman"}));
        set("title","说书的");
        set("long","
伛偻老头今年已经七十多岁了，在边城以说书卖艺为生。岁月虽然已在他身上留下
了很多残酷的痕迹，这老人却没有低头，他的背虽已弯，行动己不太灵活，但是他
还是凭着自己的努力去赚取生活的费用。\n");
    	set("gender","男性");
    	set("age",72);
    	 	
    	set("combat_exp",2000000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N喉咙里咕咕几声，似乎想说什么，却终于没说出来。 \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n伛偻老头叫道：我这把老骨头跟你拼了！！！\n",
        ]) );    	

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
    	set("chat_chance",1);
    	set("chat_msg",({
		"伛偻老头拿起胡琴吱吱呀呀拉了几声唱道:“天皇皇，地皇皇。眼流血，月无光。
一入万马堂，刀断刃，人断肠！”\n",
		"伛偻老头接着唱道：“天皇皇，地皇皇。泪如血，人断肠。一入万马堂，
休想回故乡。”\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","fumostaff",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/music/erhu")->wield();  
    
}
