inherit ITEM;

void create()
{
        set_name("佛龛", ({ "佛龛", "fekan" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一块檀香木做的小盒子。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

