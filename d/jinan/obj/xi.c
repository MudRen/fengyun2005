inherit ITEM;

void create()
{
        set_name("西墙", ({ "xiqiang", "西墙","west wall","wall" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "堵");
                set("long", "一堵墙\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

