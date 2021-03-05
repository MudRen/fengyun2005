inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("祭桌", ({ "jizhuo", "table" , "祭桌"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一方祭桌，上面放着两个黑鼎，一个黑盆。\n");
		set("prep","up");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


