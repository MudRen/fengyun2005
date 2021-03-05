// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "石狮子", ({ "stonelion","stone lion"  }) );
    set("unit", "个");
    set("value",2000);
    set("long","这是一个雕刻精美的石狮子，并不大，但活灵活现的。\n");
    set_weight(10000);
	::init_item();
}
