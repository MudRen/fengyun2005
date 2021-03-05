#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("中年马贼",({"bandit"}));
	set("long", "这是一伙专门打劫行商的马贼。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 2500000);
	set("group","bandit");
		
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("guardian",180,150,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();
}



void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() ) return;
	if (REWARD_D->riddle_check(ob,"司马小烟"))
		message_vision(CYN"$N有气无力地说：“头儿在帐篷里等你！”\n"NOR,this_object());
}
