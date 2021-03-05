#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "沙河底");
	set("long", @LONG
原来这里是一道暗河，冰冷的水让你忘却了身在沙漠，周围一片昏暗，都是迷
迷蒙蒙的沙水，你可以感觉到水中的沙子轻轻地摩擦着你的面颊，屏住一口气，你
微微睁眼向四周望去，斜上方好像有个洞口，透出微微红光。 
LONG
	);
	set("exits", ([ 
  		"southup" : __DIR__"sandriver1",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",-50);
	set("underwater",150);
	set("water_damage",20);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}


int valid_enter(object me) {
	tell_object(me, "\n突然间，压力减轻了，四周的流沙也不见了，你从高处落下，扑通一声掉到了水里。\n\n");
	message("vision", "\n扑通一声，" + me->name() + "掉到了你身旁的水中。\n", this_object(), me);
	return 1;
}


int valid_leave(object me, string dir) {
	if (dir=="southup") {
		message_vision(HIB"\n$N屏住气，摸索着向前游去。\n"NOR, me); 	
	} 
	return 1;
}

