
inherit ITEM;

void create()
{
	set_name("沙子", ({ "sand" , "流沙"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
		set("long", "缓缓流动的流沙就象一头待人而噬的巨兽，匍匐在你脚下。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


