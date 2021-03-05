inherit ITEM;

void create()
{
	set_name("小木棚", ({ "storage" , "小木棚", "木棚" }) );
    set_weight(50000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
    	set("unit", "个");
    	set("long", "小木棚不大但是干净清爽。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }


