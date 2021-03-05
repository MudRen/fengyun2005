
inherit ITEM;

void create()
{
    set_name("钟乳石", ({ "stone" , "钟乳石"}) );
	set_weight(500);
    set_max_encumbrance(800000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "条");
        set("long", "钟乳石上用炭歪歪扭扭写了几行字：字谕。。高。。立。。危险，速。。。至。。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


