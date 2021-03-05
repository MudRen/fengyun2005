inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤乳猪", ({ "fried pig","pig" }) );
	set_weight(950);
	if( clonep() )
	set_default_object(__FILE__);
	else 
	{
		set("long", "一只烤得金黄的脆皮小乳猪。\n");
		set("unit", "只");
		set("value", 6000);
		set("food_remaining", 20);
		set("food_supply", 40);
		set("material", "meat");
	}
  ::init_item();
}
