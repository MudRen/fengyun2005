// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "小圆镜子", ({ "mirror","small mirror"  }) );
    set("unit", "个");
    set("value",200);
    set("long","一面圆圆的小镜子，一看就是女人用的东西。\n");
    set_weight(10);
	::init_item();
}
