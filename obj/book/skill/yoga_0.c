// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"华严血经"NOR, ({ "xuejing","jing"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "部");
		set("long",
			"一部公禅师历时二十八年以鲜血写成的华严血经\n");
		set("value", 700);
		set("material", "stone");
		set("skill", ([
			"name": 		"yoga",	
			"exp_required":	1000000,		
			"sen_cost":	10,	
			"difficulty":	10,	
			"literate": "fanwen",
			"liter_level":  800,
			"max_skill":	0		
		]) );
	}
}
