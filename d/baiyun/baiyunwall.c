//Sinny@fengyun
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"白云城"NOR);
    set("long", @LONG
远远望去，城墙坚厚，威严耸立。一道金水河婉蜒绕城，冉冉而行。城垣之上，
又有楼亭。城门之上气势不凡的篆刻着三个金字：

                    白        云         城

LONG
    );
    set("exits", 
      ([ 
	"out" : __DIR__"hillroad2",
	"south" : __DIR__"skystreet",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/guard5" : 1,
	__DIR__"npc/guard4" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-120);
    set("coor/z",30);
    setup();

}


int valid_leave(object me, string dir)
{
   	if (QUESTS_D->verify_quest(me,"白云揽胜"))
		QUESTS_D->special_reward(me,"白云揽胜");
	return ::valid_leave(me, dir);		
	
}

