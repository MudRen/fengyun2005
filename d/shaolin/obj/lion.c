inherit ITEM;

void create()
{
        set_name("石狮", ({ "stone lion", "lion", "石狮"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "behind");
                set("unit", "对");
                set("long", "细刻石狮一对，蹲在高大的须弥雕花座上。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

