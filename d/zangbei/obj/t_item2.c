#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("塔公寺地契", ({ "diqi"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张塔公寺的地契，纸色已经泛黄了。\n");
		set("value", 1);
	}
}
