// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"万载冰晶"NOR, ({ "ice" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "ice");
            set("long", "一块半透明的六棱冰晶，在你手中散着幽幽寒气。\n");
			set("real",1);
			set("value",1000);
          }
	::init_item();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		call_out("freeze",3,me);
}

void freeze(object me)
{
	if (environment() == me || environment(environment()) == me)
	{
		tell_object(me,HIW"万载冰晶在你怀中散出丝丝寒气．．\n");
		message_vision(NOR WHT"$N忽然打了一个寒颤，牙齿格格作响。\n"NOR,me);
		me->set_temp("last_damage_from","得了寒痨冻死了。");
		me->receive_damage("kee",300);
		me->start_busy(1+random(2));
		call_out("freeze",11,me);
	}
}
