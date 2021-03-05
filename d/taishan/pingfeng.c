// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","屏风崖");
  set("long",@LONG
山势陡峭，东壁立千尺，宛如刀削，向泰山之屏障，千古绝险，犹如屏风，更
有摩崖石刻，添姿添采，崖上尽多枯藤，顺崖而下，想历代能工巧匠，刻那摩崖，
都是沿枯藤而下，刻字不易，可见一斑，你的心中不由燃起一股钦佩之情。
LONG
  );
	set("exits",([
		"westdown" : __DIR__"wangmu",
	]));
	set("objects", ([
		__DIR__"obj/cliff" : 1,
	]) );

    set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",10);
	setup();
}
void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        
        if( arg == "枯藤" || arg == "down" || arg == "vine")
        {
	        me = this_player();
    	    if (me->is_busy()){
        		tell_object(me, "你现在正忙。\n");
        		return 1;
        	}
            message_vision("$N抓着突出的枯藤，慢慢的顺着谷壁爬了下去。\n", me);
        	me->start_busy(1);
        	call_out("fliping",2,me);
        	return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}


int fliping(object me)
{
	if (!me || me->is_ghost())	return 1;
	me->move(__DIR__"shandong");
    message_vision("$N顺着枯藤爬了下来。\n", me);
	return 1;
}

