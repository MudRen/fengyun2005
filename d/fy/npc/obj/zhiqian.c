
inherit ITEM;
void create()
{
	set_name("纸钱" , ({ "zhiqian" , "纸钱"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("long", "一串纸钱\n");
		set("value", 100);
	}
	::init_item();
}



