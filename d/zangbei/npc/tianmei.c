#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("天美公主",({"tianmei"}));
    	set("title",YEL"魔教"NOR);
    	set("long", "
天美公主是魔教前教主夫人弱柳夫人的女儿，多年前和三大长老铁燕，银龙，
金狮一起叛教出走，另立新帜。其间又与神剑谢晓峰有过一段情缘，生下了
女儿谢小玉。\n");

		set("gender","女性");
	set("age",50);
	set("combat_exp", 8500000);
	set("attitude","friendly");
	
	set("reward_npc",10);
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) ); 		

	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","necromancy",1);
		
	setup();
	carry_object("obj/armor/surcoat",([	"name": "黑漆斗篷",
    						"long": "一件黑漆斗篷。\n",
    						"value": 2,
    						 ]))->wear();
    	carry_object("obj/armor/cloth")->wear();
}
