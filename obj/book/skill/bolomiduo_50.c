// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("经文", ({ "经文","jingwen", "jing" }));
	set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "");
		set("long",
			"《金刚般若波罗蜜经》\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("skill", ([
			"name": 	"bolomiduo",	
			"exp_required":	0,		
			"sen_cost":	10,	
			"difficulty":	10,	
			"max_skill":	49		
		]) );
	}
    ::init_item();
}
