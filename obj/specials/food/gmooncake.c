// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"豆沙双黄", "莲蓉双黄", "枣泥双黄", "凤梨双黄", "百果双黄"});
    set_name( order[random(5)] + "月饼", ({ "mooncake", "moon cake" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个皮薄馅多香气扑鼻的月饼。\n");
		set("unit", "个");
		set("value", 500);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "中秋节");
	}
	 ::init_item();
}

	