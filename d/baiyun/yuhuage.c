//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{        set("short", "雨花阁");
    set("long", @LONG
再行片刻，繁花覆地，白云在天。清泉怪石，罗列其间。眼前处处是花径。走出
花径又是条花径，穿过花丛还是花丛。前面半顷荷塘上的九曲桥头，有个朱栏绿瓦的
水阁。红尘中所有的烦恼忧伤，都早已被隔绝在四面青山外。水阁上题：
                           花    红
                           茵    尘
                           如    似
                           锦    梦
LONG
    );
    set("exits",
      ([
	"southwest" : __DIR__"feixianting",
	"northdown" : __DIR__"maze1",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	__DIR__"npc/huayin" : 1,
	__DIR__"obj/stone" :1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-55);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
