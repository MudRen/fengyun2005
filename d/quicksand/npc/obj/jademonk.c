inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT"玉佛像"NOR, ({ "jade statue", "statue"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",
			"一个用上好的白玉雕成的佛像。\n");
		set("value", 500000);
		set("material", "steel");
		set("skill", ([
			"name": 	"buddhism",	
			"exp_required":	1000000,		
			"sen_cost":	50,	
			"difficulty":	50,	
			"max_skill":	49		
		]) );
	}
	::init_item();
}
