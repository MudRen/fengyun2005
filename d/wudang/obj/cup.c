inherit ITEM;

void create()
{
	set_name("细瓷茶杯", ({ "tea cup", "茶杯"}) );
	set_weight(40);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "只");
	    set("long", "一只细瓷茶杯。\n");
	    set("value", 100);
	}
	::init_item();	
}

