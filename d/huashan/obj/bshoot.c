inherit ITEM;

void create()
{
	set_name("竹笋", ({"bamboo shoot", "shoot"}) );
	set_weight(100);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个嫩竹笋。\n");
	    set("value", 50);
	}
	::init_item();
}



