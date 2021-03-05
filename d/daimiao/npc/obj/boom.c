// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "小竹拂尘", ({ "fuchen","fuchen"  }) );
    set("unit", "块");
    set("value",20);
    set_weight(5);
    ::init_item();
}
