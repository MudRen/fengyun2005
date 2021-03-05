// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void heal();

void create()
{	
	object weapon;
	set_name("小小冰人", ({ "healer"}) );
	set("combat_exp", 4000000);
	set("str",-100);
	set("attitude", "friendly");
	set("long","一个小小小小小冰人。\n");
	set("no_arrest",1);
	set("no_fly",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: heal() :),
	}) );
	set("chat_chance", 100);
	set("chat_msg", ({
		   (: heal() :),
	}) );

	setup();
}

void heal()
{
	object owner,me = this_object();
	owner = query("owner");
	if (environment() == environment(owner) && owner->is_fighting())
	{
		message_vision(CYN"$N飞快的在$n身边串来串去，将团团冰雪拍在$n身上。\n"NOR,me,owner);
		owner->receive_fulling("gin",500);		
		owner->receive_fulling("kee",500);		
		owner->receive_fulling("sen",500);		
		perform_busy(2);
	}
	else
	{
		message_vision(CYN"$N哧溜一声钻进雪堆里去了。\n"NOR,me);
		destruct(this_object());
	}
}
