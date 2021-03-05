// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "城隍印", ({ "yin","chenghuang yin"  }) );
    set("unit", "个");
    set("long","这是一个官印样的东西，但非金非木，很是奇怪。\n");
    set_weight(5);
	::init_item();
}
