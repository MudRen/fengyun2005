inherit ITEM;

void create()
{
	set_name("大花盆", ({ "pot", "花盆", "大花盆", "盆"}) );
	set_weight(700);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个大花盆，里面种着各式茶花。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

