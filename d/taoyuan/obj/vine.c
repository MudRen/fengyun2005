inherit ITEM;

void create()
{
        set_name("枯枝", ({ "vine" , "枯枝"}) );
        set_weight(10000);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "根");
                set("long", @LONG
一根粗粗的树枝，还没有完全枯死，上面模模糊糊地刻着几个小字：
		武当禁地　擅入者死！
LONG
		);
                set("value", 1);
        }
    ::init_item();
}

int is_container() { return 1; }

