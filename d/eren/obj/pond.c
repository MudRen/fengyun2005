inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("池塘", ({ "池塘" , "pool","pond"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一方很深的池塘，塘内养着许多鱼鳖！\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


