inherit ITEM;

void create()
{
    set_name("树冠", ({ "treetop" , "leaf", "树冠"}) );
    set_weight(50000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
     	set("prep", "in");
        set("unit", "丛");
        set("long", "碧绿茂密的树冠。\n");
        set("value", 1);
    }
	::init_item();
}

int is_container() { return 1; }


