inherit ITEM;

void create()
{
        set_name("地板", ({ "stone floor", "floor", "地板"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep", "on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一片打扫得光洁干净的青石地板。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }
