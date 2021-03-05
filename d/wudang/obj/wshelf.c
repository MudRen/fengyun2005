inherit ITEM;

void create()
{
	set_name("兵器架", ({ "weapon shelf", "shelf", "兵器架"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("prep", "on");
	    set("unit", "个");
	    set("long", "一个兵器架，摆满了各式兵器。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

