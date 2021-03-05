inherit ITEM;

void create()
{
        set_name("大床", ({ "bed", "床" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张收拾得香喷喷、干干净净的大床。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }
