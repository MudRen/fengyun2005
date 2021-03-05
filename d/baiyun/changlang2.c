//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "甬道");
    set("long", @LONG
接天楼背靠绝壁，谁也无法想象绝壁之中竟然有如此一条笔直而幽长的甬道，两
旁点着不灭的长明灯，光线虽不很亮，但也可辨道路，似乎本是依着山腹中天然洞穴
修凿而成，人工开凿处甚是狭窄，有时却豁然开阔，只觉渐行渐低，道中出现了流水
之声，琮琮铮铮，清脆悦耳，如击玉罄。而前方似乎有些许灯光忽明忽暗。
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"changlang",
	"south" : __DIR__"changlang3",
	"west" : __DIR__"changlangx",
	//       "enter" : __DIR__"mysticroom",
      ]));
    set("objects", 
      ([ 
	//       __DIR__"npc/jianchi" : 1,
      ]));

    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-260);
    set("coor/z",30);
    setup();
}

/*
int	valid_leave(object who, string dir)
{
    object me;
    me = who;
    if (dir == "west" && REWARD_D->riddle_check(who,"王图一梦") !=12)
    {
	tell_object(me,"这条岔道太过阴暗，还是不去为妙。\n");
	return notify_fail("");
    }
    return ::valid_leave(who,dir);
}

*/
/*

	       (\~~~/)            
	       ( ．．)        

	       (_____)~．      

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
