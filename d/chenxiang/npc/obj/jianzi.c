// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "鸡毛毽子", ({ "jian zi","jian"  }) );
    set("unit", "个");
    set("value",20);
    set("long","
一个用花花绿绿的鸡毛插成的毽子。
\n");
    set_weight(5);
	::init_item();
}
