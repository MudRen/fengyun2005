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
                set("long", "鲜嫩欲滴的绿草，似乎还有几滴露珠在叶子上闪着微光。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }


