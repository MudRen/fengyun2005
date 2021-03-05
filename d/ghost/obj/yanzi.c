inherit ITEM;

void create()
{
        set_name("小燕子",({ "yanzi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "paper");
                set("long", "一只小燕子。\n");
        }
	::init_item();
}
