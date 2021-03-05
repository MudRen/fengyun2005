inherit ITEM;

void create()
{
        set_name("铁锅", ({ "tieguo", "铁锅" }) );
        set_weight(500);
        set_max_encumbrance(40000);        
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "铁锅\n");
                set("value", 1);
                set("long", "一只大铁锅，木头盖子半盖着，里边有几只烤鸭。\n");
        }
	::init_item();
}

int is_container() { return 1; }

