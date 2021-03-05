// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","唐槐亭");
  set("long",@LONG
山行从此向东开始陡峭，一座凉亭前有一棵大槐树，据称唐代名将秦琼曾在此
栓马歇息，此树从此四季常绿，长得郁郁葱葱，遮天蔽日。许多登山者都在此歇脚。
交叉路口，向东是两条山道，一条通向著名的[33m『兴国禅寺』[32m，另一条是山下的[33m集市[32m，
往南前行，便是泉城[33m『济南』[32m。
LONG
  );
  set("exits",([
         "west"  :__DIR__"shanjiao.c",
         "eastup":AREA_QIANFO"qiyan.c",
         "east" : AREA_QIANFO"road",
	 "south" : __DIR__"gate"
               ]));
        set("objects", ([
                AREA_QIANFO"npc/horse" : 1,
		AREA_QIANFO"npc/climber" : 2,
       ]) );
        set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "往树下走了过来。\n");
        }
}

int do_climb(string arg)
{
        if( arg!="tree" ) return 0;

        message_vision("$N手脚并用，敏捷地爬上了凉亭前的大槐树。\n",
                this_player());

        tell_room(__DIR__"tree1", this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(__DIR__"tree1");

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir=="eastup") dir="east";
        tell_room(__DIR__"tree1",
                "树下的" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        if (dir=="east") dir ="eastup";
        return 1;
}

