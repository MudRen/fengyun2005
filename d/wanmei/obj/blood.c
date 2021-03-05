inherit COMBINED_ITEM;
void create()
{
	set_name("半干的血滴", ({ "blood", "dry blood" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "滩");
		set("base_unit", "滴");
		set("base_weight", 1);
		set("base_value", 1);
	}
	::set_amount(1);
}
