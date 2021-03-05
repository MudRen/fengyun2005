inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("五彩小鱼", ({ "rainbowl fish", "fish", "wu_cai fish" }) );
    set_weight(120);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一条活蹦乱跳的小鱼，身上有着五彩颜色。\n");
        set("unit", "条");
        set("value", 500);
        set("food_remaining", 3);
        set("food_supply", 60);
    	set("marks/catfood", 1);
    }
    ::init_item();
}

void init() {
	::init();
	call_out("inWater", 30);
}

void inWater() {
	object container;
	
	container = environment(this_object());
	if(container->name() != "小鱼缸" || !container->query("marks/haswater")) {
		set("long", "小鱼死了，原本色彩鲜艳的五彩鳞变的毫无光泽。\n");	
		set("name", "臭掉了的鱼");
		set("marks/catfood", 0);
		set("value", 0);
	}
}
