#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("牙齿", ({ "tooth"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一颗人的臼齿，镶嵌在一个小小的檀木盒中。\n");
		set("value", 1);
	}
}
