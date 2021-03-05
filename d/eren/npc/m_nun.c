#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;

void create()
{

	set_name("扫地的中年女尼",({"middle aged nun","nun"}));
	set("long", "一个三四十岁的女尼，正在门前打扫落叶，清秀的脸上隐隐露出愁苦之色。\n");
	set("age",39);
	set("gender","女性");
	set("combat_exp", 3500000);
	set("attitude", "friendly");
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
	auto_npc_setup("nun",200,160,0,"/obj/weapon/","magician","necromancy",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/necklace",([	"name": "青木佛珠",
    						"long": "一条青木佛珠连成的颈链。\n",
    						"value": 1,
    						 ]))->wear();  
}


