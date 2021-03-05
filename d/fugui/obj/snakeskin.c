inherit ITEM;
void create()
{
	set_name("菜花蛇皮", ({ "snake skin","skin"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "张");
		set("long",
			"一块菜花蛇过冬褪去的“蛇皮”。\n");
		set("value", 0);
		set("material", "food");
	}
	::init_item();
}
