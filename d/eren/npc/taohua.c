#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;

void create()
{

	set_name("桃花娘子",({"taohua","niangzi","taohua niangzi"}));
    set("title",YEL"梅花庵主持"NOR);
	set("long", "看不出她脸上的表情，可是她眼睛里那种仇恨怨毒之色，还是无论谁
都能看得出的。。\n");
	set("gender","女性");
	set("age",39);
	set("combat_exp", 7500000);
	set("attitude", "aggressive");
	
	set("reward_npc",8);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	   	(: auto_smart_fight(50) :),    
     }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object another;
	message("vision",name() + "叹了口气，又成了一个苍老干枯的老尼。\n", environment(),
		this_object() );
	another = new(__DIR__"liaoyin");
	another->move(environment(this_object()));
	destruct(this_object());
}

