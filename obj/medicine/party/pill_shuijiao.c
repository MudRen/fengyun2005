inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(WHT"水饺"NOR , ({ "shui jiao" }) );
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"大寒小寒，吃饺子过年。\n"NOR);
        	set("unit", "只");
        	//set("lore",1);
        	set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	int force, max_force, atman, max_atman, mana, max_mana, bonus, bonus2, bonus3;
	object me = this_player();
	
	message_vision(BGRN + HIY"$N感觉浑身气血澎湃，精力倍增！\n"NOR,me);
	
	force = me->query("force");
	max_force = me->query("max_force");
	
	atman = me->query("atman");
	max_atman = me->query("max_atman");

	mana = me->query("mana");
	max_mana = me->query("max_mana");

	bonus = max_force * 120 /100;
	bonus2 = max_atman * 120 /100;
	bonus3 = max_mana * 120 /100;
	
	if ( atman + bonus2 > 2* max_atman)	
		me->set("atman",2*max_atman);
	else
		me->add("atman",bonus2);

	if ( force + bonus > 2* max_force)	
		me->set("force",2*max_force);
	else
		me->add("force",bonus);

	if ( mana + bonus3 > 2* max_mana)	
		me->set("mana",2*max_mana);
	else
		me->add("mana",bonus3);

	me->force_status_msg("atman");
	me->force_status_msg("force");
	me->force_status_msg("mana");

  destruct(this_object());
 	return 1;
}
