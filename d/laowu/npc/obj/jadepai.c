
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("罗刹牌" , ({ "luosha" , "pai"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块罗刹牌\n");
		set("value", 10000);
	}
}



