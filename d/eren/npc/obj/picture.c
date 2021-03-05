inherit ITEM;


void create()
{
	set_name("羊皮纸" , ({ "paper"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("24dao",1);
		set("unit", "张");
		set("long", "一张草图，图上是一个小孩的画像。\n");
		set("value", 100);
	}
	::init_item();
}



