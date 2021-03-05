inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "兽穴");
        set("long", @LONG
洞穴四壁上长满了青苔，偶尔从树叶间隙里透下的天光萎萎缩缩地不敢进入，
洞里黑漆一团，越往里走，就越能闻到一股血腥和膻骚味，让人浑身不自禁地起了
鸡皮疙瘩。可以感到脚下有许多硬硬的东西，一摸，都是啃的精光的动物骨头。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
        set("coor/x",-1620);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("west","rock","巨石","east",DOOR_CLOSED);
}

void reset(){
	int i;
	object bear;	
	
	i = NATURE_D->get_season();	
	
	if (objectp(bear=present("bear",this_object())))
	{
		if (userp(bear) 
			|| bear->is_fighting() 
			|| !bear->is_character())	
		return;
	else
		destruct(bear);
	}
	if(i == 1 || i == 4 ) {
		bear=new(__DIR__"npc/bear_w");
		bear->move(this_object());
	} else {
		bear=new(__DIR__"npc/bear");
		bear->move(this_object());
	}
	::reset();
}

int valid_leave(object me, string dir) {
	object bear;
	if (dir == "west")
	if (bear = present("bear",this_object()) )
	if (bear->is_fighting(me))
		return notify_fail("野熊那巨大的身躯堵住了洞口。\n");
		
	return ::valid_leave(me,dir);
}