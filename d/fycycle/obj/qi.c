// maple_leaf
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("小锦旗", ({ "small flag", "flag" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一面精致的小锦旗，红底白花，绣着“比武招亲”四个金字。\n");
		set("unit", "面");
		set("weight",50);
		set("value", 100);
	}
	::init_item();
}
