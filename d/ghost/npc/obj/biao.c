// dart.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("铜钱镖", ({ "biao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"铜钱镖是一种十分常见的暗器。\n");
		set("unit", "些");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 0);
		set("volumn",20);
	}
	set_amount(40);
	::init_throwing(20);
}
