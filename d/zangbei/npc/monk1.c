#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("冲古寺的喇嘛",({"chonggu lama","lama"}));
	set("long", "这是冲古寺护卫寺院的喇嘛。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 4500000);
	
	
   	set("inquiry", ([
		"转经":		"绕寺千转，自有所得！\n", 
		"司空掏星": "是哪位香客？没见过这人啊。\n",
   	]));
   	
	set("chat_chance", 1);
        set("chat_msg", ({
		
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","liuxing-hammer",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	carry_object("/obj/weapon/hammer",([	"name": "金瓜錘",
    						"long": "短短的把手, 上接一個鐵鑄的圓球, 重量驚人。\n",
    						"weight": 20000,
    						"value" : 1,
    						 ]))->wield();    
}
