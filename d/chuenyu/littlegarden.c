
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这是刘老汉的小花园。花园里有很多美丽的花朵。刘老汉就是靠卖花来维持生
计的。现在正是花开的大好季节，有很多年轻姑娘们一边剪花，一边说笑。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"home",
]));
        set("objects", ([
                __DIR__"npc/flowergirl" : 5,
        ]) );
        set("outdoors", "chuenyu");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-20);
	setup();
}

