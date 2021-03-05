inherit ITEM;

void create()
{
        set_name("砚台", ({ "yan tai", "紫红砚台", }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "紫红色的砚台温润莹洁，砚台的边上按照石头的纹理色泽雕刻了一棵红梅树。\n");
                set("value", 1000);
                set("color", "紫红");
        }
	::init_item();
}


