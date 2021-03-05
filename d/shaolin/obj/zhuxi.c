inherit ITEM;

void create()
{
        set_name("竹席", ({ "zhuxi", "竹席" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep","under");
                set("unit", "张");
                set("long", "一张薄薄的竹席。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

