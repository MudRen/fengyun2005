inherit ITEM;

void create()
{
        set_name("小锅", ({ "small wok", "wok" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "一口专门为方丈和大和尚烧菜的小锅\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

