inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("鸣钟入门", ({ "book"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "一本教授基本鸣钟心得的书。\n");
		set("value", 1);
	}
}



