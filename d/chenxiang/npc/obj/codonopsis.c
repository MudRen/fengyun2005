// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "党参", ({ "codonopsis","radix codonopsis"  }) );
    set("unit", "块");
    set("value",20);
    set("long","
一块上好的党参
\n");
    set_weight(5);
	::init_item();
}

