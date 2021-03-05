inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("石碑", ({ "石碑" , "bei","shibei"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", WHT"石碑上刻着几个龙飞凤舞的字：入谷入谷  永不为奴		（善人村）\n"NOR);
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


