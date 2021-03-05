// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "石灰石", ({ "limestone"}) );
    set("unit", "块");
    set("value",200);
    set("long","这是一块很厚的石灰石，上等的建屋材料。\n");
    set_weight(10000);
	::init_item();
}
