inherit ITEM;

void create()
{
        set_name("砚台", ({ "yan tai", "青砚台", }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个巴掌大小色泽青碧，温润莹洁，旁边雕刻着松竹的砚台。\n");
                set("value", 1000);
                set("color", "青");
        }
	::init_item();
}


