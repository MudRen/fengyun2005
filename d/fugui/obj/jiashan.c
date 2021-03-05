inherit ITEM;

void create()
{
        set_name("假山", ({ "rock", "假山" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "一座巧夺天工，以假乱真的假山。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

