inherit ITEM;

void create()
{
	set_name("小册子", ({"book", "puti steps"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个小册子，但是上面写满了密密麻麻的小字，仔细辨认你只认出少林两字。\n");
	    set("value", 10);
	}
	::init_item();
}



