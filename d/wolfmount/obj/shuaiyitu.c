// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("率意图", ({ "shuaiyi picture","picture"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "幅");
		set("long",
            "\n率   意   图\n\n狼山山主朱五年少时意气风发，叱咤江湖，率狼山儿郎们驰骋大江南北，快意恩仇。\n某日，朱五醉酒后，遥想当年搏浪沙大力士锤击始皇之义举，一时兴起，一气呵成\n作了此画，名之率意，画得便是搏浪沙之举，图中竟隐隐有燕赵悲歌，慷慨击杀\n之意。\n");
		set("value", 70);
		set("material", "stone");
		set("skill", ([
            		"name":         "assassin-hammer",    
            		"exp_required":	100000,      
			"sen_cost":	50,	
			"difficulty":	50,	
            		"max_skill": 	30      
		]) );
	}
    ::init_item();
}
