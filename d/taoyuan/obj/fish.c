inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	string *names = ({ "石斑鱼", "虎纹鱼", "鲇鱼" });
	i = random(3);
    set_name(names[i], ({ "fish" }) );
    set_weight(500);
    if( clonep() )
	    set_default_object(__FILE__);
    else {
        set("long", "这是一条刚刚钓上来的鲜鱼。\n");
        set("unit", "条");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 10);
    	set("marks/catfood", 1);
    }
    ::init_item();
}

void init() {
	::init();
	call_out("badfish", 120);
}

void badfish() {
	set("long", "已经不再新鲜的鱼散发着一股腥臭味。\n");
	set("name", "散发着腥臭味的鱼");
	set("marks/catfood", 0);
	set("value", 0);
}

