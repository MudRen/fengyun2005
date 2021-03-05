// annie 07.2003
// dancing_faery@hotmail.com

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIR"小香囊"NOR, ({ "sachet" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 0);
		set("material", "jade");
		set("long", "一个散着一缕缕销魂蚀骨香气的小小香囊。\n");
	}
	::init_neck();
}

void init()
{
	if (environment(this_object()) == this_player())
	{
		remove_call_out("greeting");
		call_out("greeting", 60, this_player());
	}
}

void greeting(object me)
{
	int i;
	object env, *inv, obj,victim;

	if (!me->is_fighting() || me->query_temp("armor/neck") != this_object())
	{
		call_out("greeting", 60, this_player());
		return;
	}
	message_vision(HIC"$N"HIC"身上散发出一阵阵销魂蚀骨的甜香．．．\n",me);
        
    env = environment(me);
	inv = all_inventory(env);
	           
	for(i=0; i<sizeof(inv); i++)
	{
		victim=inv[i];
		if (victim == me)	continue;
		if (victim->is_corpse() || !victim->is_character()) continue;
		if (!me->is_fighting(victim) && !userp(victim)) continue;	// 不在战斗的NPC，过。
		if (!victim->query("can_speak")) continue;	// 不会说话的，过。
//		if (me->query("gender") == victim->query("gender"))	continue;	// 同性的，过。

		victim->apply_condition("sachet",5);
		tell_object(victim,HIW"甜香一点一点地浸进你的鼻中，熏得你如痴如醉，心旌神摇．．．\n"NOR);
	}
	call_out("greeting", 60, this_player());
	return;
}


