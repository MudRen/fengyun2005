//TIE@FY3
inherit ITEM;
void create()
{
        set_name("醉石", ({ "醉石", "zuishi","drunk stone" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
	set("prep","under");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "李白醉酒卧眠的醉石，石上一人形依稀可见，观其形状恰似
酒至鼾处。\n");
                 set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }
