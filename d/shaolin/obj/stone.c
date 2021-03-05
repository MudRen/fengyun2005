inherit ITEM;

void create()
{
        set_name("夹杆石", ({ "stone", "夹杆石" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块夹旗杆的大石头\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

