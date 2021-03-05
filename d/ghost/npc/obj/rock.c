inherit ITEM;

void create()
{
        set_name("石头", ({ "rock", "石头"}) );
        set_weight(500);
        set_max_encumbrance(800);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "under");
                set("unit", "张");
                set("long", "一块大青石。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

