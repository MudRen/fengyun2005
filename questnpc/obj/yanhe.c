#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"鼻烟盒"NOR, ({ "yanhe" }) );
	set_weight(200);
	set_max_encumbrance(4000);
//	set("no_get", 1);
//	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个玉雕的鼻烟盒\n");
		set("value", 150);
	}
}

int is_container() { return 1; }
