#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("蚌普寺的喇嘛",({"bangpu lama","lama"}));
	set("long", "这是蚌普寺打扫寺院的小喇嘛。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1200000);
		
	
   	set("inquiry", ([
		"转经":		"绕寺千转，自有所得！\n", 
		"糌粑":		"我天天用糌粑喂鱼儿，它们只爱吃这个。\n",	
   		"鱼儿":		"我天天用糌粑喂鱼儿，它们只爱吃这个。\n",
   		"司空掏星": "这猴精贼头狗脑的，我就知道他没安好心。\n",
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
		"喇嘛把手里的糌粑捏碎，兴致勃勃地扔到河里，顿时鱼儿们就活跃了起来。\n",  
		
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("wang",120,160,0,"/obj/weapon/","fighter_u","yiyangzhi",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	
}
