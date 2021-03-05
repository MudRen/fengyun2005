// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("息庵禅师道行之碑", ({ "息庵禅师道行之碑","daoxing","daoxingzhibei"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "章");
		set("long",
			"日僧邵元撰的“息庵禅师道行之碑”。\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
//	if(random(2))
		set("skill", ([
			"name": 		"xiaochengforce",	
			"exp_required":	0,		
			"sen_cost":		10,	
			"difficulty":	10,	
			"max_skill":	49		
		]) );
/*	else 
                set("skill", ([
                        "name":                 "buddhism",
                        "exp_required": 0,
                        "sen_cost":             50,
                        "difficulty":   50,
                        "max_skill":    49
                ]) );*/
	}
}
