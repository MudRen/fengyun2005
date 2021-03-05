inherit ITEM;

void create()
{
        set_name("大锅", ({ "giant wok" }) );
        set_weight(500000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "一个明代所铸的大锅。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

