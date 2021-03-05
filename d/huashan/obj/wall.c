inherit ITEM;

void create()
{
	set_name("残墙", ({ "wall", "残墙" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "堵");
	    set("long", "一片残墙断瓦，旁边杂草衍生。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

