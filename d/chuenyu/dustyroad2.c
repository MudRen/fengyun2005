// Room: /d/chuenyu/dustyroad2.c

inherit ROOM;

void create()
{
        set("short", "三叉路口");
        set("long", @LONG
三岔路口向北是通往黑松山里的小路。东北方向是一个小镇，镇上人家不多，
大部分砍柴种地为生。小小的住家，住家的后面是个很大的花园。花园里有很多小
童在嬉耍。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"dustyroad3",
  "south" : __DIR__"dustyroad",
  "north" : __DIR__"sunnyroad",
]));
        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}

