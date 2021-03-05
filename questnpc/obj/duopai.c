// movebook.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"玉牌"NOR, ({ "yu pai", "pai" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("for_bandit",1);
		set("long",
			"一块玉雕的腰牌，上面雕着一柄权杖。\n");
		set("value", 0);
		set("material", "jade");
		set("skill", ([
			"name": 		"wenhou-claw",	
			"exp_required":	800000,				
			"sen_cost":		40,				
			"difficulty":	70,		
			"max_skill":	51,		
		]) );
	}
}
