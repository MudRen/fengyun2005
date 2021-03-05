#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"白山千鸟"NOR, ({"flower"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "朵");
	    set("long", "这朵花只得拇指大小，洁白的花萼中带着几缕浅浅的绿纹，
唯有早春的几个月才有机会见到。\n");
	    set("value", 100);
	}
	::init_item();
}



