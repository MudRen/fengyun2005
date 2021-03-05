// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "卧龙馆内院");
        set("long", @LONG
四墙足足有两人多高，上面没有任何东西，滑不留手。院子里唯一的一棵树也
用一丈多高的栅栏围了起来，似乎就怕有人会爬在树上。内院还有一口枯井，深不
见底。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"jdi",
  "west" : __DIR__"wol",
]));
        set("objects", ([
        __DIR__"npc/dau": 1,
                        ]) );
	set("no_magic",1);
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
 	if( dir=="down" ) 
 	{	
 		if(me->query_temp("marks/asked_jianu") && present("jianu"))
 		{
 			tell_object(me,"你抓住贾女垂下的绳索慢慢向井下降去。\n");
 			return 1;
 		}
 	 	else
 			return notify_fail("井太深了，下去会摔死的。\n");
 	}else 
 		return 1;
}
