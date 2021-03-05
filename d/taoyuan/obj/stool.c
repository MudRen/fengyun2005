inherit ITEM;

void create()
{
    set_name("木凳", ({ "stool" , "木凳"}) );
    set_weight(2000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
        set("unit", "个");
        set("long", "一个长条木凳。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }


