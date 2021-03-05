#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(HIY"唐代玉玺"NOR, ({ "yuxi"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "传说中的唐代传国玉玺。\n");
		set("unit", "块");
		set("value", 500);
		set("thief_obj",1);
	}
	::init_item();
}

