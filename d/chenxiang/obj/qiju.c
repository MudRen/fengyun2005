// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "小面馆的地契", ({ "diqi","qi"  }) );
    set("unit", "张");
    set("value",200);
    set("long","
小面馆地契
		----------------
		|沉香镇县府大印|
		----------------
\n");
    set_weight(1);
	::init_item();
}
