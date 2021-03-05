
inherit ITEM;

void create()
{
	set_name("翁仲石像", ({ "shixiang" ,"石像","statue"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("prep", "on");
		set("long", "雕塑得栩栩如生衣甲俱全的石像\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


