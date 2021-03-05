inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("骷髅", ({ "skull","skeleton","骷髅",}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "骷髅幽幽的，端端正正的盘膝坐在石榻之上，深陷的眼窝里隐约闪烁着惨绿的磷光。。\n");
		set("value", 1);
		set("prep", "on");
	}
	::init_item();
}

int is_container() { return 1; }


