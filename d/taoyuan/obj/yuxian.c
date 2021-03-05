
inherit ITEM;

void create()
{
	set_name("鱼线", ({ "string" , "yu xian"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条长长的用来修补渔网的线。\n");
		set("value", 50);
	}
    ::init_item();
}



