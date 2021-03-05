// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
    set_name("嘛呢堆", ({ "嘛呢堆","mani picture","picture"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "幅");
		set("long",
            "密密麻麻刻满了各种神佛和宗教箴言以及藏传佛经。\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
            "name":         "lamaism",    
            "exp_required": 1000,      
			"sen_cost":		50,	
			"difficulty":	50,	
            "max_skill":    30      
		]) );
	}
    ::init_item();
}
