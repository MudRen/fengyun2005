inherit ITEM;

void create()
{
    set_name("岩石", ({ "岩石", "stone", "岩石堆","yanshi" }) );
    set_weight(100000);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
	set("prep","on");
    if( clonep() )
            set_default_object(__FILE__);
    else {
  		set("unit", "堆");
        set("long", "一堆形状各异的岩石。\n");
        set("value", 1);
    }
	::init_item();
}

int is_container() { return 1; }

