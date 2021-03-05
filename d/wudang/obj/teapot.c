inherit ITEM;

void create()
{
	set_name("瓷茶壶", ({ "tea pot", "茶壶"}) );
	set_weight(100);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "只");
	    set("long", "一只瓷茶壶，上面画着武当山水。\n");
	    set("value", 100);
	}
	::init_item();
}

