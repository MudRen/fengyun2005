// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "大理石", ({ "stone"}) );
    set("unit", "块");
    set("value",3000);
    set("long","这是一块打磨得很光的大理石。\n");
    set_weight(10000);
	::init_item();
}
