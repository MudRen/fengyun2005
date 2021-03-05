// movebook.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"玉牌"NOR, ({ "yu pai", "pai" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long",
			"一块玉雕的腰牌，上面雕着一个赤裸的女人。\n");
		set("value", 0);
		set("material", "jade");
		set("skill", ([
			"name": 		"yuxiao",	
			"exp_required":	1000000,				
			"sen_cost":		50,				
			"difficulty":	75,		
			"max_skill":	51,		
		]) );
	}
}
