// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "城隍庙");
    set("long", @LONG
每个城镇不论大小都有个庙，沉香镇也不例外，据说这里的城隍老爷特别灵验，
如果家里有谁生了病，只要到这儿磕几个头便能消病去灾，所以庙虽然不大但香
火却很旺盛，远近的达官贵人纷纷前来，逢年过节的时候这里就摆满了各种各样
的祭品，连宫里的娘娘们也常来祈求平安。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"cxs2",
        ]));
    set("objects", ([
        __DIR__"npc/omonk": 1,

        ]) );
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
    setup();
}

void init()
{
    add_action("do_ask","ask");
}

int do_ask(string arg)
{
    object me,obj;
    string aa,bb;
    me = this_player();
    if(!query("marks/gone") && me->query_temp("marks/huier"))
    {
        if(!stringp(arg)) return 0;
        if(sscanf(arg,"%s about %s",aa,bb) != 2) return 0;
        if( aa != "舅爷" &&  aa != "jiuye") return 0;
        if( bb != "印" && bb != "yin") return 0;
        set("marks/gone",1);
        obj = new(__DIR__"obj/yin");
        obj->set("huier",1); 
        obj->move(this_object());
        tell_object(me,"你只听到＂啪＂的一声，有一件东西从房顶掉了下来。\n");
        return 1;
    }
    return 0;
}

void reset()
{
    ::reset();
    delete("marks/gone");
}

