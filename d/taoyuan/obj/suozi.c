
inherit ITEM;

void create()
{
	set_name("梭子", ({ "suo zi" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个用来修补渔网的梭子。\n");
		set("value", 100);
	}
    ::init_item();
}



