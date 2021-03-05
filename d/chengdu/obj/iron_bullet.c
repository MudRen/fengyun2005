#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("铁弹丸", ({ "iron bullet" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"神机营所研究出的火枪填装物。"
);
		set("unit", "堆");
		set("base_unit", "颗");
		set("base_weight", 50);
		set("base_value", 1);
		set("volumn",10);
	}
	set_amount(10);
}
