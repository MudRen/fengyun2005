#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"温玉"NOR, ({ "jade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块触手温润的玉石，雕的是一匹低头吃草的马。\n");
		set("value", 300);
		set("material", "stone");
	}
	::init_item();
}
