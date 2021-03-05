inherit ITEM;

void create()
{
	set_name("书架", ({ "book shelf", "shelf", "书架"}) );
	set_weight(5000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("prep", "on");
	    set("unit", "个");
	    set("long", "一个紫木书架，摆满了各种书籍。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

