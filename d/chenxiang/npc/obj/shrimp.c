// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "小虾", ({ "shrimp","small shrimp"  }) );
    set("unit", "条");
    set("value",5);
	set("fish_bait", 1);
    set("long","
一条用来钓鱼的小虾。
\n");
    set_weight(1);
	::init_item();
}
