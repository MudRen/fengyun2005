inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"金甲武士"NOR, ({ "golden soldier","soldier"}) );
	set("title",RED"八面威风"NOR);
	set("gender", "男性" );
	set("age", 30+random(20));
	set("long","丈八的汉子，手持铁戟，肃立在红毡两旁，灯光映铁戟，闪闪发寒光。\n");
	set("combat_exp", 4500000);
    set("class","fugui");
        

	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear2",1);
	setup();
	carry_object(__DIR__"obj/g_armor")->wear();
    carry_object(__DIR__"obj/g_spear")->wield();
}
