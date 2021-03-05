
inherit ITEM;

void create()
{
	set_name("高山流水", ({ "hill" , "water", "高山流水"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块高山流水的景色！\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
