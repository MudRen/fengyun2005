
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
		set("long", "罗刹牌上的神魔像栩栩如生，只是玉质好象差了点。\n");
		set("fake", 1);
		set("value", 100);
	}
}



