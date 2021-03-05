inherit ITEM;

void create()
{
	set_name("忘忧草", ({"grass", "wang you"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "株");
	    set("long", "一株碧绿的草，比花更美，比翡翠还绿。\n");
	    set("value", 1000);
	}
	::init_item();
}



