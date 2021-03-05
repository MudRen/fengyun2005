inherit ITEM;

void create()
{
    set_name("铁锅", ({ "pot" , "铁锅", "锅"}) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "口");
        set("long", "一口普普通通的铁锅，却还淡淡地残留着一点葱香。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }


