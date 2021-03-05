// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("神妃", ({ "神妃","shenfei", "神妃像" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",
			"一个着衣端坐的神妃像，上面好象刻着一些字。\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("skill", ([
			"name": 	"incarnation",	
			"exp_required":	0,		
			"sen_cost":		10,	
			"difficulty":	10,	
			"max_skill":	90		
		]) );
	}
	::init_item();
}
