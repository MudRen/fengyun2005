
inherit ITEM;

void create()
{
    set_name("蚯蚓", ({ "qiu yin", "qiuyin"}) );
	set_weight(1);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
        set("unit", "条");
        set("long", "土红色筷子般粗细的蚯蚓。 \n");
        set("value", 1);
		set("fish_bait", 1);
    }
}

