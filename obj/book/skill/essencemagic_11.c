
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("玄武战袍", ({ "zhanpao" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long",	"一件色彩鲜艳的战袍。\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"essencemagic",	
			"exp_required":	0,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	10		
		]) );
		set("armor_prop/armor",10);
	}
	::init_cloth();
}
