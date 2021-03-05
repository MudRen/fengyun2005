inherit ITEM;

void create()
{
        set_name("床", ({ "bed", "床" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
               set("long", "一张收拾得干干净净的小木床，隐隐散发着一丝淡淡的香气。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

