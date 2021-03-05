// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;

void create()
{
        set_name("就公塔", ({ "塔", "就公塔","ta","tower"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "behind");
                set("unit", "座");
                set("long", "天竺和尚就公塔，高约三十余尺。（ｃｌｉｍｂ）\n");
                set("value", 1);
        }
}

int is_container() { return 1; }
