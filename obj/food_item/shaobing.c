// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("烧饼", ({ "shaobing" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个烤得香喷喷的烧饼，芝麻香味扑鼻而来。\n");
		set("unit", "个");
        set("value", 50);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
	::init_item();
}
