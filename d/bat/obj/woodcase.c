
inherit ITEM;

void create()
{
	set_name("柜子", ({ "woodcase" , "柜子","case"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个用来放杂物的柜子。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
