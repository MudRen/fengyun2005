// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "玉凹子", ({ "aozi","jade aozi"  }) );
    set("unit", "个");
    set("value",200);
    set_weight(500);
	::init_item();
}
