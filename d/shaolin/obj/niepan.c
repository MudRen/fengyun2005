// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit COMBINED_ITEM;
void create()
{
	set_name("《涅磐经》", ({ "niepan"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "捆");
		set("base_unit","卷");
		set("long", "大明正统五年御赐的《涅磐经》\n");
		set("base_value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 	"buddhism",	
			"exp_required":	0,		
			"sen_cost":	10,	
			"difficulty":	10,	
			"max_skill":	199,
			"literate" : "fanwen",
			"liter_level":  50
		]) );
	}
	set_amount(1);
}
