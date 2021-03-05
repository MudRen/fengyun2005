inherit ITEM;

void create()
{
	set_name("碗", ({ "bowl", "rice bowl", "碗"}) );
    set("no_shown", 1);
	set("no_get",1);
    set_weight(500);
    set_max_encumbrance(200);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
		set("prep", "in");
        set("long", "一个青花瓷碗，碗周围的米粒都被舔得干干净净。\n");
        set("unit", "个");
        set("value", 20);
    }
    ::init_item();
}

int is_container() { return 1; }
