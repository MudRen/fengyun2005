// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create() 
{
    set_name( "小木筏", ({ "boat","little boat"  }) );
    set("unit", "块");
    set("value",20);
    set("floating",1);
    set("long","一个小小的小木筏。\n");
    set_weight(150000);
    ::init_item();
}
