inherit ITEM;

void create()
{
    set_name("花", ({ "花", "flower" }) );
    set_weight(50000);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    set("prep","under");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "丛");
        set("long", "一丛丛鲜花怒放，百花的芳香弥漫在空气中。\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }

