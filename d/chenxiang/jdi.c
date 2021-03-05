// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "枯井底");
    set("long", @LONG
这里都是半腐烂的杂草和树叶，特别的松软，这口底就象是一个葫芦，上面的
井口特别窄小。井底很宽，因阳光的渗入，所以并不是特别的阴暗。
LONG
        );
    set("objects",([
        __DIR__"npc/snake":1]));
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",-10);
    setup();

}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
//      object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        
        if( arg == "上" || arg == "up" || arg == "well")
        {
	        me = this_player();
    	    if (me->is_busy()){
        		tell_object(me, "你现在正忙。\n");
        		return 1;
        	}
            message_vision("$N抓着井壁艰难地向上爬去。\n", me);  
          	me->start_busy(3);
        	call_out("fliping",6,me);
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
	me->move(__DIR__"wol2");
    message_vision("$N浑身湿淋淋地从水井中爬了上来。\n", me);
	return 1;
}