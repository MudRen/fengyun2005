inherit ROOM;
void create()
{
        set("short", "孤峰绝顶");
        set("long", @LONG
海风劲吹。天下尽在眼底，这才是人间的绝顶。只有举世无匹的高手才能登上
这里，但是高处不胜寒！
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"renjiandao3",
]));
        set("outdoors", "bat");
        set("objects", ([
        __DIR__"npc/baiyiren": 1,
                        ]) );

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",70);
	setup();
}
