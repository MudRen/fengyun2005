inherit ITEM;

void create()
{
        set_name("小花", ({ "flower" , "小花"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "丛");
                set("long", "白的，紫的，红的，一丛五颜六色的小花儿。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }


