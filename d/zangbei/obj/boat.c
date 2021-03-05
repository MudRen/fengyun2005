inherit ITEM;

void create()
{
        set_name("小船", ({ "boat" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只小船。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

