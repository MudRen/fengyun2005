inherit ITEM;

void create()
{
        set_name("绿草", ({ "grass" , "绿草"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("long", "海风中摇曳飘舞的绿草，似乎格外顽强，那几点绿意却赛过无数红花。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }


