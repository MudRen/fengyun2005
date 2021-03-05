#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"菩提花"NOR, ({"flower", "puti hua"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "朵");
	    set("long", "几片绿色的花萼衬托着洁白的花瓣显得那么清雅迷人，更有阵阵清香从中透出。\n");
// change to 2 coin :D
// by akuma	    
//	    set("value", 200);
	    set("value", 2);	
	}
	::init_item();
}



