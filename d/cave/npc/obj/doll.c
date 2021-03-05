
inherit ITEM;
void create()
{
    set_name("布娃娃" , ({ "doll"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("long", "一个做工精细的布娃娃，可爱有趣，是高立自远方买来送给双双的。\n");
        set("value", 5);
	}
	::init_item();
}



