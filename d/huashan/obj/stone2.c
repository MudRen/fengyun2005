inherit ITEM;

void create()
{
	set_name("大石头", ({ "石", "stone" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "块");
	    set("long", "一块上面爬满藤萝的石头。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

