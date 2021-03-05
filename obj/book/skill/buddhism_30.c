// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("壁画", ({ "bihua","壁画"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long",	"一幅饱含佛理的壁画。\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"buddhism",	
			"exp_required":	0,		
			"sen_cost":		1,	
			"difficulty":	5,	
			"max_skill":	29,	
		]) );
	}
}


