#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("大牢钥匙", ({ "key" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("material", "iron");
        set("long", "一枚用来打开天牢中门的钥匙。\n");
	}
	set("prison_key",1);
	::init_item();
}