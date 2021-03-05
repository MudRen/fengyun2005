#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
    set("short", "烟水亭顶");
	set("long", @LONG
翘檐揽月，尖顶簪霞，湖心的烟水小亭不止有内中美丽，此处风色更是绝
佳无匹。站在亭顶四望，但三百里大明湖波光景色尽入眼中，风起处莲舟远荡
，云水间吞吐氤氲。
LONG
	);
	set("exits", ([ 
  "down" : __DIR__"bridge4",
]));
        set("objects", ([
//        __DIR__"npc/song" : 1,
// 回家了..
//        __DIR__"npc/thief" : 1,
// 搬家了..
                        ]) );
	set("coor/x",100);
	set("coor/y",120);
    set("outdoors", "jinan");
	set("coor/z",100);
	setup();
	set("no_fly", 1);
	set("max_lv",120);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"bottom");
	if (!exitroom)
		exitroom = load_object(__DIR__"bottom");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"你脚下突然一空，扑通一声摔进了冷澈骨髓的湖水中。\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

