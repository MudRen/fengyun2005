inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("纸马", ({ "paper","纸马" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 1);
		set("long","用来祭祀的纸人纸马。\n");
	}
	
	::init_item();
}


