// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("密密的铁栏", ({ "bars","铁栏"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "章");
		set("long",
			"一排刻着道德经的铁栏\n");
		set("value", 70);
		set("material", "iron");
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"daode",	
			"exp_required":	0,		
			"sen_cost":		50,	
			"difficulty":	90,	
			"max_skill":	49		
		]) );
	}
}
