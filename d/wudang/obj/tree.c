inherit ITEM;

void create()
{
	set_name("悬松", ({ "悬松", "松","tree" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "棵");
	    set("long", "一棵悬松，根直峭壁，身悬空中，虬枝伸展，刚毅挺拔。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

