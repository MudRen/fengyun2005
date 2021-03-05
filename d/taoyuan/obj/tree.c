inherit ITEM;

void create()
{
    set_name("小树", ({ "tree" , "小树"}) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
        set("unit", "棵");
        set("long", "一棵紧邻潭水的小树。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }


