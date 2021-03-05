inherit ITEM;

void create()
{
        set_name("草丛", ({ "grass" , "草丛"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("long", "长长的茅草覆盖着路面。\n");
                set("value", 1);
        }
    ::init_item();
}

int is_container() { return 1; }


