#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("萧别离",({"xiao bieli","xiao","bieli"}));
    	set("title","服装很华丽、修饰很整洁的中年人");
    	set("long","
他两鬓斑白，脸上每一条皱纹中，都不知隐藏着多少欢乐，多少痛苦，多少
秘密，但一双手却仍柔细如少女。他穿着很华丽，华丽得甚至已接近奢侈。\n");

     	set("gender","男性");
    	set("age",52);
    	 	
   		set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"萧别离正在将骨牌一张张慢慢地摆在桌上，摆成了个八卦。\n"
    	}) );    	    	
    	
		auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
		set_skill("tanzhi-shentong",160);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "富贵团金褂",
    						"long": "一件富贵团金褂。\n",
    						 ]))->wear();     
    
}
