inherit ITEM;

void create()
{
	set_name("荆棘丛", ({ "jingji", "荆棘" }) );
	set_weight(5000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "丛");
	    set("long", "一丛荆棘，黄绿色的枝茎上长满了椭圆形带刺的蒺藜。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

