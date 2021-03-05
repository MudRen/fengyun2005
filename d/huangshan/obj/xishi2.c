inherit ITEM;

void create()
{
        set_name("歙石", ({ "she shi", "歙石", "stone", }) );
        set_weight(1500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块双掌大小色泽紫红，温润莹洁，叩之有声，纹理绚烂的石头。
是做砚台的上好石料。\n");
                set("value", 500);
                set("color", "紫红");
                set("砚台料", 1);
        }
	::init_item();
}


