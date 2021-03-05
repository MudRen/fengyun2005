inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "罗布林卡");
        set("long", @LONG
大昭城里城外有许多园林，藏语称林卡，这些大都是僧俗官员夏日休闲游乐的
地方。过去僧官有僧官的林卡，俗官有俗官的林卡，每家贵族、每座寺院都有自己
的一片园林。恰克卜里山脚下的罗布林卡，是历辈达赖喇嘛夏秋两季的住地，所以
又称达赖夏宫。
LONG
        );
        set("exits", ([ 
		"northeast":  __DIR__"lake2",
		"southwest":	__DIR__"sela",
	]));
        set("objects", ([
        	
	]) );
	set("outdoors", "guanwai");
        set("coor/x",50);
        set("coor/y",-10);
        set("coor/z",10);
	setup();

}
