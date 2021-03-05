inherit ITEM;

void create()
{
        set_name("薄被", ({ "buobei", "薄被" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "席");
                set("long", "一席薄被。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

