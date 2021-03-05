inherit ITEM;

void create()
{
	set_name("沙子", ({ "sand" , "海沙"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
		set("long", "晶莹洁白的沙子。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
