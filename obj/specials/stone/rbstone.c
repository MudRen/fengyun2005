#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("五彩石", ({"rainbow stone", "stone" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "块");
		set("long", "晶莹的石头上有一层五彩光芒旋转流动，令人眩目。\n");
            	set("value", 2000000);
        }
	::init_item();
}


/* the design is bugged and thus temperary disabled.  by silencer 9/22/02

void init() {
	object me, *pros;
	me = this_player();
	pros = me->query_temp("protectors");
	if(pros) {
		pros +=  ({ this_object() });
	} else {
		me->set_temp("protectors", ({ this_object() }));
	}
}
int protection() {
	int result;
	
	result = random(4) > 0 ? 1 : 0;
	set("protected", result);
	return result;
}

string protection_msg() {
	object me = environment(this_object());
	
	return query("protected") ?  me->name() + MAG"佩戴的五彩石发出彩虹般的五色光芒笼罩在"NOR
			+ me->name() + MAG"周围。\n$N根本无法攻入光障的范围。 \n"NOR
			: MAG"五彩石发出淡淡的五色光芒，形成一道光幢，$N依然破幢而入！\n"NOR;
}
*/