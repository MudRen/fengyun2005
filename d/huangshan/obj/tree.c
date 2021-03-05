inherit ITEM;

void create()
{
    set_name("天女树", ({ "tree" , "天女树", "树"}) );
    set_weight(50000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
     	set("prep", "on");
        set("unit", "棵");
        set("long", "不甚高大的树长着圆形的翠绿叶片。\n");
        set("value", 1);
    }
	::init_item();
}

int is_container() { return 1; }


