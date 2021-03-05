// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "鲜鱼", ({ "freshfish","fish"  }) );
    set("unit", "条");
    set("value",8);
    set("long","
一条上好的鲜鱼
\n");
    set_weight(5);
	::init_item();
}
