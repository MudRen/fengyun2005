inherit ITEM;

void create()
{
    set_name("栽花", ({ "flowerpot", "栽花","花盆", "盆" }) );
	set_weight(700);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
        set("long", "一个大花盆，里面种着一些奇异的黑色花朵，散发着令人眩晕的香味。。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

