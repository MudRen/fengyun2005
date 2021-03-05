#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "大海");
        set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。
耳边只有海浪的拍打声（listen wave）。
LONG
        );
	set("coor/x",-310);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}
void init()
{
	add_action("do_look",({"look","listen"}));
}

int do_look(string arg)
{
 	object me,room;
 	
 	me = this_player();
 	
 	if(!arg || arg!= "wave") {
 		return 0;
 	} 	
 	
 	if(!random(5)) {
  		tell_object(me, BLU "突然间，你的船触礁了！一个大浪打来，你被抛入空中．．．\n"NOR);
  		room = load_object(__DIR__"anbian");
  		me->move(room); 
  		return 1;
 	} else {
 		tell_object(me, BLU "海浪就象是一头头恶狼，唑咬着你的船！\n"NOR);
 		return 1;
 	}
}
