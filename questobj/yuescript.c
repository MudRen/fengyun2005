#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"武穆遗书" NOR, ({ "yue-script" }));
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本传自岳武穆的兵法手册，内文均是行军打仗、布阵用兵的精义要诀。\n");
		set("material", "paper");
		set("skill", ([
			"name": 	"strategy",		
			"exp_required":	50000,				
			"sen_cost":	30,			
			"difficulty":	30,			
			"max_skill":	80		
			]) );
		}
}
