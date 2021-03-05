
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("绿石盒", ({ "box", "stone box"}) );
    set_weight(800);
    set_max_encumbrance(500);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "个");
		set("long", "一个碧绿色的小石盒。你可以试着把它打开(open)\n");
		set("value", 0);
		set("no_stack",1);
       	set("prep", "in");
    }
	::init_item();
}

int is_container() {return 1;}

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
    	if(ob->query_temp("marks/opened")) {
    		return notify_fail("石盒已经被打开过了。\n");
	}
	
	if(query("box_owner")!= me) {
		message_vision("$N试着打开小石盒，小盒有如一整块石头，纹丝不动。\n", me);
		return 1;
	}	
	
	if(me->query("force_factor")<50) {
		tell_object(me,"你累得满头大汗，但是力气不够，小盒如石头般纹丝不动。
（至少需50点加力）\n");
		return 1;
	}
		
	message_vision("$N用力把$n打开．．．\n", me, ob);
    	set("long", "一个绿色的小石盒，盒盖已经被打开了。\n");

	item = new(__DIR__"paper");
	message_vision("$N看着$n里的东西，惊讶得说不出话来！\n", me, ob);
	item->move(ob);

	me->set("annie/gstone",1);	
	me->delete_temp("marks/search_turtle");
	me->delete("marks/turtle_room");
	
   	ob->set("value", 0);
	ob->set_temp("marks/opened",1);
    return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
