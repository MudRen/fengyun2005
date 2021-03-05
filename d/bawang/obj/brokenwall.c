inherit ITEM;
void create()
{
    set_name("断墙", ({ "断墙","残墙", "duanqiang","duan qiang","wall" }) );
    set_weight(999999);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
	set("prep","under");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "堵");
            set("long", "一堵断墙，摇摇欲坠。\n");
            set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }

