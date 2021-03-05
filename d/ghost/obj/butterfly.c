inherit ITEM;

void create()
{
        set_name("花蝴蝶",({ "butterfly" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "paper");
                set("long", "一只粉红色的蝴蝶。\n");
        }
	::init_item();
}
