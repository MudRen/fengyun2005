// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("缅甸白玉佛", ({ "yufo","yu fo"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "章");
		set("long",
			"一个可以和洛阳玉美人相媲美的玉佛像。\n");
		set("value", 7000);
		set("material", "stone");
		set("skill", ([
			"name": 		"incarnation",	
			"exp_required":	0,		
			"sen_cost":		10,	
			"difficulty":	1,	
			"max_skill":	160		
		]) );
	}
}
