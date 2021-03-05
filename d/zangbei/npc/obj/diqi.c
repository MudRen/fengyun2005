#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("地契", ({ "diqi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一块快活林的地契，看上去有年头了。\n");
		set("value", 1);
		set("material", "paper");
		set("kuaihuo",1);
	}
	::init_item();
}
