#include <ansi.h>
inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "莽林之中");
        set("long", "四周"YEL"古树"NOR"参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出昼夜。
四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼嚎随着腥风
飘至耳际。
"
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"groupe1",
  		"west" : __DIR__"groupw1",
  		"north" : __DIR__"groupn1",
  		"south" : __DIR__"groups1",
	]));
	
	set("item_desc", ([
		"tree":	"树上有很多突出的树枝，你可以试着爬上去（ｃｌｉｍｂ）看看。\n",
		"树":	"树上有很多突出的树枝，你可以试着爬上去（ｃｌｉｍｂ）看看。\n",
		"古树":	"树上有很多突出的树枝，你可以试着爬上去（ｃｌｉｍｂ）看看。\n",
	]));
	
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
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
                return 0;
        }
        if( arg == "tree" || arg == "古树" || arg == "树")
        {
	        me = this_player();
        	if (me->is_busy() || me->query_temp("manglin/climb"))
        		return notify_fail("你现在正忙。\n");
        	message_vision("$N抓着突出的树枝，慢慢地顺着树杆爬了上去。\n", me);
        	me->start_busy(2);
        	me->set_temp("manglin/climb",1);
        	call_out("fliping",3,me);
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
	if (!objectp(me))	return 1;
	
	me->delete_temp("manglin/climb");
	if(!interactive(me) || environment(me) != this_object()){
		return 1;
	}
	
	if(!me->is_ghost()){
		me->move(__DIR__"top1");
		message_vision("$N顺着树杆爬了上来。\n", me);
	       	me->stop_busy();
	}
        return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

