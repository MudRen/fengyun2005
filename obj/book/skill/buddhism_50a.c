
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("朱雀战衣", ({ "zhanyi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long",
			"一件色彩鲜艳的战衣。\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"buddhism",	
			"exp_required":	5000,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	50		
		]) );
		set("armor_prop/armor",10);
	}
	::init_cloth();
}
