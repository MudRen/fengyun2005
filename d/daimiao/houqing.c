//mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","后寝宫");
  set("long",@LONG
宋真宗封泰山时，认为泰山神既然封为帝，就应有皇后，于是又想象了个“淑
明后”，因建三宫：中为正宫，两侧是配宫。神龛内奉东岳大帝和帝后塑像，高一
丈，两伺女分立左右，神龛外两侧配有太监塑像，平台上有日形和月形碑各一块，
以示日月同辉之意。很多虔诚的信徒都在这儿膜拜（ｍｏｂａｉ）。
LONG
  );
  	set("exits",([
	         "north":__DIR__"tongting.c",
	         "south":__DIR__"tiankuang.c",
	         "east" :__DIR__"peiqing1.c",
	         "west" :__DIR__"peiqing2.c",
        ]));
        set("objects", ([
                __DIR__"npc/master_demi" : 1,
        ]) );
        set("item_desc", ([
                "东岳大帝": "东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n",
        ]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_mobai", "mobai");
}

int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N虔诚地跪在东岳大帝塑像前磕了个头。\n" ,who);
       who->receive_damage("sen",50);
       who->set_temp("last_damage_from","在泰山膜拜过于劳累而死。\n");
       if( (int)who->query("bellicosity") > 0)
           	who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);

	return 1;
}
