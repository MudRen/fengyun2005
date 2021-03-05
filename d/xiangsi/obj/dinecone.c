#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("松果", ({"pinecone"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "枚");
	    set("long", "一枚小小的、尖尖的松果。\n");
	    set("value", 100);
	}
	::init_item();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
