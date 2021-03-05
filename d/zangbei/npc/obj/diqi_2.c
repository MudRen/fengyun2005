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
		set("long", "一块崭新的泰安广场地契，钱银已迄，就等着你去盖房了。\n");
		set("value", 1);
		set("material", "paper");
		set("taian",1);
	}
	::init_item();
}
