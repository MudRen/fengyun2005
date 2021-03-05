#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("家谱", ({ "jiapu" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张薛家的家谱。\n");
		set("value", 1);
		set("material", "paper");
	}
	::init_item();
}
