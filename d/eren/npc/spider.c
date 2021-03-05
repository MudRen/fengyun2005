#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("黑蜘蛛",({"spiderman"}));
	
	set("long", "
一个身材瘦小的黑衣人，不但全身被一件闪闪发光的紧身衣服紧紧裹住，
一张脸也蒙着漆黑的面具，只剩下一双黑白分明的眸子，黑的地方如漆，
白的地方如雪。\n");

	set("age",25);
	set("combat_exp", 3300000);
	
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );

	auto_npc_setup("guardian",200,180,1,"/obj/weapon/","fighter_w","lefthand-sword",1);
	
	setup();
	carry_object(__DIR__"obj/darkcloth")->wear();
}



