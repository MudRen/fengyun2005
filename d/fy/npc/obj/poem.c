// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "风云赞歌", ({ "poem song","poem"  }) );
    set("unit", "首");
    set("long","
		是非成败转头空，
                	风云依旧在，
                		几度血光红。

\n");
    set_weight(1);
    ::init_item();
}
