inherit ITEM;

void create()
{
        set_name("山涧", ({ "brook" , "山涧"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条轻快流淌的山涧，水声清脆仿佛唱歌一般。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }


