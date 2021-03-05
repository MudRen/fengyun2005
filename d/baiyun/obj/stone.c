inherit ITEM;

void create()
{
    set_name("怪石", ({ "怪石","stone","rock"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "块");
        set("long", "一块嶙峋的怪石。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
