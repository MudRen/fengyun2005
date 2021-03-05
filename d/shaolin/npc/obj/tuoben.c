// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("碑文拓本", ({ "tuoben"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"少林寺中碑文的拓本。字迹模糊，甚是难以辨识。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"literate",	
			"exp_required":	0,		
			"sen_cost":		50,	
			"difficulty":	90,	
			"max_skill":	9		
		]) );
	}
}
