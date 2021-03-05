
inherit ITEM;

void create()
{
	set_name("金铃", ({ "bell", "金铃" , "一只小小的金铃"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一只小小的金铃\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
