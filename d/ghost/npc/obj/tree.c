inherit ITEM;

void create()
{
        set_name("大树", ({ "tree"}) );
        set_weight(100);
	set("no_get", 1);
        set("no_shown", 1);
        set_max_encumbrance(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "一棵茂密的大树。\n");
        }
	::init_item();
}

int is_container() { return 1; }

