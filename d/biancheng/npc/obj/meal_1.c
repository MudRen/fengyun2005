inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("红烧排骨", ({ "hspg", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘家常小菜。\n");
		set("unit", "盘");
		set("value", 2000);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
        set_name("盘子", ({"panzi"}));
	set("value",200);
        set("long", "一只蓝底儿雕花的景泰蓝大盘子。\n");
        return 1;
}

void init() {
	::init();
	if (!query("in_decay")) {
		set("in_decay",1);
		call_out("badmeal", 180);
	}	
}

void badmeal() {
	set("long", "一盘家常小菜，可惜时间太长，已经不新鲜了。\n");
	set("name", "馊了的小菜");
	set("value", 0);
}