// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("青苔", ({ "lichen" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("long", "青苔会让石头的表面变得额外光滑。\n");
                set("value", 0);
        }
	::init_item();
}

