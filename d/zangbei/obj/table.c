inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("香案", ({ "ken", "香案"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "用来祭祀死者，或是供奉祖先和神灵的案台。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


