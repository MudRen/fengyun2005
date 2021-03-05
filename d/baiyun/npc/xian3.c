inherit SMART_NPC;
#include <ansi.h>

void create()
{
	object armor;
	set_name("慧大师", ({ "hui dashi","hui"}) );
	set("gender", "女性" );
	set("title",HIW"世外三仙"NOR);
	set("nickname",HIR"小域岛主"NOR);
	set("age", 370+random(10));
	set("class","lama");        
	set("long",		"一个满脸肃重之色的老尼。\n");
	set("class","shaolin");
        set("combat_exp", 10000000);
        set("score", random(90000));
        set("reward_npc", 1);
	set("difficulty",10);
	
	set("attitude","friendly");
	
	set("fly_target",1);
	
	set("no_busy",8);
	
	set("chat_chance", 1);
    set("chat_msg", ({
                "慧大师忽然地双袖一舞，走出那套妙绝人寰的“诘摩神步”，四十九
种步法施完，身形一拔，竟拔起十丈。\n",
                }) );
        
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","huidashi",1);
    setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("丝织的道服",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}

