
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("青石盒", ({ "box", "stone box"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "个");
		set("long", "一个青绿色的小石盒。你可以试着把它打开(open)。\n");
    	set("value", 500);
    }
	::init_item();
}

void init()
{
   add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
    	if( !arg || arg != "box" ) {
    		return notify_fail("你要打开什么？\n");
    	}
		message_vision("$N试着打开小石盒，小盒有如一整块石头，纹丝不动。\n", me);
		return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
