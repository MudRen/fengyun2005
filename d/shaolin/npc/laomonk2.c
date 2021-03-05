inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("送菜的老和尚", ({ "old monk", "monk" }) );
	set("nickname",HIW"一丝不苟"NOR);
	set("gender", "男性" );
	set("age", 62);
    set("vendetta_mark","shaolin");
	set("class","shaolin");
    set("long",
		"在少林寺里送菜烧饭的老僧，据说个个是深藏不露的高手。\n"
		);
		
    set("chat_chance", 1);
    set("chat_msg", ({
           (: random_move :)
     }) );
	
	set("combat_exp", 3200000);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/ironfist")->wield();
}

    	   