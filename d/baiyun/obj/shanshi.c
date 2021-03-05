inherit ITEM;

void create()
{
    set_name("山石", ({ "山石", "rock" }) );
    set_weight(500);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    set("prep","under");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "座");
        set("long", "一座嶙峋险峻，棱角分明的山石。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }

