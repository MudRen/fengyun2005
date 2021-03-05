// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "当归", ({ "lycii","fructus lycii"  }) );
    set("unit", "块");
    set("value",20);
    set("long","
一块上好的当归
\n");
    set_weight(5);
	::init_item();
}
