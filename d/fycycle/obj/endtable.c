inherit ITEM;

void create()
{
        set_name("石几", ({ "endtable", "table"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("prep", "on");
                set("long", "一张青石茶几\n");
                set("value", 1);
        }
}

int is_container() { return 1; }