inherit ITEM;

void create()
{
	set_name("茸毛", ({ "rongmao" , "deer hair", "hair", "茸毛"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "团");
		set("long", "一团细密的茸毛。\n");
		set("value", 100);
	}
    ::init_item();
}



