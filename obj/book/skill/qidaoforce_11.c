
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("圣灵披风", ({ "pifeng" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long",
			"一件色彩鲜艳的披风。\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"qidaoforce",	
			"exp_required":	0,				
			"sen_cost":	2,				
            "difficulty":   1,  
            "max_skill":    10,    
            "literate":	"qidaoforce",
            "liter_level":	1,   	
		]) );
		set("armor_prop/armor",10);
		}
	::init_cloth();
}
