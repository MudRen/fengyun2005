#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "魔宫");
        set("long", @LONG
一座华丽已极的宫殿出现在你的眼前。这座宫殿简直就像是天外飞来，却又上
不接天，下不及地，仿佛飘浮在风雾中。十三只怪鸟拥着一团火焰在铃声中翩翩舞
来。美丽的怪鸟，有孔雀的翎，有蝙蝠的翅，有燕子的剪尾，有蜜蜂的毒针，半边
的翅是兀鹰，半边的翅是蝙蝠，半边的羽毛是孔雀，半边的羽毛是凤凰。每一只鸟
的脖子都挂着一个铃。铃声怪异而奇怪，仿佛要慑人的魂魄。
LONG
        );
        set("exits", ([ 
		"down":  __DIR__"dream7",
		"south":  __DIR__"dream9",
	]));
	set("objects", ([
               	__DIR__"npc/parrot": 1,
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

