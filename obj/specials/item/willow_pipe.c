
inherit ITEM;
void create()
{
	set_name("柳笛" , ({ "willow pipe" , "liu di", "pipe"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个小柳笛。\n");
		set("value", 100);
		set("holiday", "清明节");
	}
	::init_item();
}



