inherit ITEM;

void create()
{
    set_name("怪石", ({ "怪石", "stone" }) );
    set_weight(500);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    set("prep","under");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "座");
        set("long", "一座怪石，嶙峋狰狞，十分骇人。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }

