inherit ITEM;

void create()
{
	set_name("崖壁", ({ "崖壁", "cliff", "ya bi"}) );
	set_weight(50000);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "堵");
	    set("long", "一堵直立的悬崖，上边有一些拳头大小的洞。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

