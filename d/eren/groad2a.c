inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "青草地");
        set("long", @LONG
走过来是郁郁葱葱的青草地，草很绿，很齐，像是日常有人修剪。草丛里这儿
那儿盛开着簇簇的野花，走过的人便走在一阵淡淡的花香中，不时还会惊起几只蚱
蜢，一蹦一蹦地跳远。
LONG
        );
        set("exits", ([ 
	"southwest" : __DIR__"groad1",
	"northeast" : __DIR__"groad2",
	
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",30);
        set("coor/y",80);
        set("coor/z",0);
	set("map","eren");
	setup();

}


void dig_notify()
{
     	object me, worm,worm2;
     	    	
     	me = this_player();
     	if (me->is_busy()) {
     		tell_object(me,"你现在正忙。\n");
     		return;
     	}
     		
     	worm=present("yellow worm",this_object());
     	worm2=present("red worm",this_object());
     	
     	if(objectp(worm)|| objectp(worm2)) {
     		tell_object(me,"地上已经挖出一条蚯蚓了。\n");
     		return;
     	}
     	
     	message_vision("$N在地上找了块潮湿的地方挖了起来。\n", me);
     	if(query("already")>=5) {
     		tell_object(me,"这儿的蚯蚓都挖光了。\n");
     		return;
     	}
     	
     	if (!random(5))	worm = new(__DIR__"obj/redworm");
        	else worm=new(__DIR__"obj/worm");
        worm->move(this_object());
        message_vision("$N从地上挖出一条"+worm->name()+NOR"。\n", me);
     	me->start_busy(2);
     	add("already",1);

}

void reset() {
	:: reset();
	set("already",0);
}


