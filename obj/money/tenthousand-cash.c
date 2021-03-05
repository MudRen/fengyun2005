//tenthousand-cash.c

inherit MONEY;

void create()
{
	set_name("一万两银票", ({"tenthousand-cash", "tenthousand-cash_money", "ttcash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-cash");
		set("long", "一张面额值一万两银子的银票。\n");
		set("unit", "叠");
		set("base_value", 1000000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

