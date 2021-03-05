#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("黑火药", ({ "gun powder" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"这是神机营专为火枪所配置的火药，硝酸钾、硫黄、木炭的配比恰
到好处。"
);
		set("unit", "堆");
		set("base_unit", "份");
		set("base_weight", 5);
		set("base_value", 1);
		set("volumn",10);
	}
	set_amount(10);
}
