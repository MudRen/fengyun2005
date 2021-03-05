// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("菩提达摩的石像", ({ "damo" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",
			"一个双手合十，面貌庄重的达摩石像，上面好象刻着一些字。\n");
		set("value", 70);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"xiaochengforce",	
			"exp_required":		1000,		
			"sen_cost":		30,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
	::init_item();
}
