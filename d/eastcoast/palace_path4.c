#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "迷茫风雨路");
    set("long", @LONG
山势越来越高，雾气越来越浓厚，周围的景象在浓雾中若隐若现。浓雾中的水
气穿透了你的衣裳，你的心也像被冰冷的雾气包围了。这…到底是通往天堂的艰途，
还是通往地狱的不归之路？
LONG
    );
    set("exits", ([ 
	"eastup" : __DIR__"palace_path5",
	"westdown" : __DIR__"palace_path3",
      ]));
    set("outdoors", "palace");
    set("coor/x",160);
    set("coor/y",0);
    set("coor/z",20);
    setup();
}

void init()
{
    if (!random(2))
    {
	message("vision",WHT"\n云雾弥漫，北面的雾气似乎在轻轻流动。\n\n"NOR, this_object());
	add_action("do_north", "go");
	add_action("do_look", "look");
    }
}



int do_north(string arg)
{
    object room, me;
    if (arg == "north") {
		me = this_player();
		if (!room= find_object("/d/cyan/enterance"))
		    room=load_object("/d/cyan/enterance");
		me->move(room);
		REWARD_D->riddle_done( me, "明霞之秘",10,1);		
		return 1;
    }
    return 0;
}


int do_look(string arg)
{
    object me;
    me = this_player();

    if (arg!="north" && arg!="雾气")
	return 0; 
    tell_object(me,WHT"北面的雾气在轻轻流动，雾气后面隐隐约约有条山路。\n"NOR);      
    return 1;
}  
