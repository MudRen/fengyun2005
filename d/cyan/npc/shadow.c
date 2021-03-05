// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("隐在枝叶中的黑影", ({ "hidden shadow","shadow" }) );
        set("gender", "男性" );

		set("age",47);

	set("chat_chance",2);
	set("chat_msg", ({
		"一阵悉悉索索的声音传来，不知道隐在枝叶中的黑影在拨弄什么。\n",
	}) );

        set("combat_exp", 4000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

		set("death_msg",CYN"\n$N抽搐了几下，直挺挺地不动了。\n"NOR);

		auto_npc_setup("ouyang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);
		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("皱皱的白衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("挂破的白衣", ({ "cloth" }) );
		weapon->set("value",0);
    	
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
		write(MAG"黑影隐在枝叶之中，你什么也看不清。"NOR"\n");
		return 1;
	}
	return 0;
}