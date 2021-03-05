inherit ITEM;

void create()
{
        set_name("灶台", ({ "zaotai", "灶台" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "灶台\n");
                set("value", 1);
                set("long", "油烟把灶台熏得黑得跟锅底似的，上边有一口大铁锅。\n");
        }
	::init_item();
}

int is_container() { return 1; }

