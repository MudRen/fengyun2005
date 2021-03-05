inherit ITEM;

void create()
{
        set_name("马车", ({ "mache", "cart" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "一辆半新不旧的木马车。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

