// cloth.c
//

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"被鲜血浸透的布条"NOR, ({ "cloth piece" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是条被鲜血浸透的布条。\n");
		set("value", 10);
		set("material", "cloth");
	}
	::init_item();
}
