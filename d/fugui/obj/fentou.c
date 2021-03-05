inherit ITEM;

void create()
{
        set_name("坟头", ({ "fentou", "坟头","tomb" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
		set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个坟头，上边还压着几张纸。\n");
                set("value", 1);
        }
		::init_item();
}

int is_container() { return 1; }

