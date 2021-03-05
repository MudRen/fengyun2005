#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条长长的甬道，甬道两旁嵌有铜灯。甬道斜斜地伸如地下，不知有多长，
也不知伸向何处，但两壁铜灯俱都擦得极为光亮，显见此地经常有人行走。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath2",
  "west" : __DIR__"secretpath0",
]));
        set("objects", ([
        __DIR__"npc/redbeast" : 1,
                        ]) );


	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}
void init()
{       object ob;
        int exp;
        if( interactive( ob = this_player()))
        {
        exp = ob->query("combat_exp");
        if(exp < 2000) {
        ob->move(__DIR__"secretpath0.c");
        message_vision(HIR"\n$N被一股热浪当了回来。\n\n"NOR, ob);
        }
        }
}

