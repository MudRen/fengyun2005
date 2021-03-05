
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("杀手牌", ({ "pai" , "杀手牌"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", HIR "鲜红似血的杀手牌\n"NOR);
		set("value", 1000);
	}
	::init_item();
}



