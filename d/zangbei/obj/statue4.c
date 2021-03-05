inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("自塑雕像", ({ "自塑雕像" , "雕像", "statue"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "佛学大师噶玛巴都松钦巴原籍甘孜州新龙县，为扩大自身影响建此寺，进
行讲经学法，并自作自身佛像供世人朝奉。\n");
		set("value", 1);
		set("prep","on");
	}
	::init_item();
}

int is_container() { return 1; }


