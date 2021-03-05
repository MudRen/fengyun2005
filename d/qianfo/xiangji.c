// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void close_path();
void create()
{
  set("short","香积厨");
  set("long",@LONG
香积厨为禅寺的厨房，供奉的是万紧那罗王，相传曾显化为一火头僧，运三尺
棍趋散红巾首领的犯寺。
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang4.c",
            "west" :__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
 	set("resource/water", 1);
    	set("liquid/container", "水缸");   
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void init()
{
add_action("do_push","push");
}


int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要推开什么？\n");
                return 1;
        }
        if( arg == "luowang" || arg == "万紧那罗王" || arg == "罗王")
        {
        me = this_player();
        message_vision("$N推开万紧那罗王，发现了一条密道。\n", me);
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"changlang4");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("你推了推"+arg+"。\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","万紧那罗王又转了回来，堵住了向北的路。\n",this_object() );
        delete("exits/north");
        return;
}

