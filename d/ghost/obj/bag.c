inherit ITEM;

void create()
{
        set_name("皮囊", ({ "bag"}) );
        set_weight(100);
        set_max_encumbrance(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个粉红色的皮囊。\n");
                set("value", 150);
        }
	::init_item();
}

int is_container() { return 1; }

