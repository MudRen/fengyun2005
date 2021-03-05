inherit ITEM;

void create()
{
	set_name("小鸟窝", ({ "nest", "鸟窝" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个用小树枝搭成的鸟窝，里面垫衬着绒绒的羽毛。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

