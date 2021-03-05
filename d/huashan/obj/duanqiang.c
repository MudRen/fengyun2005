inherit ITEM;

void create()
{
	set_name("断墙", ({ "duan qiang", "wall", "断墙" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一节断墙，断墙的四周长满了杂草和野菊花。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

