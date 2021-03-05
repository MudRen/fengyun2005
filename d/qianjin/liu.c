inherit ROOM;
void create()
{
        set("short", "湖上柳");
        set("long", @LONG
湖上柳，烟里不胜催。
宿雾洗开明媚眼，东风摇弄好腰肢，烟雨更相宜。
环曲岸，阴覆画桥低。
线拂行人春晚后，絮飞晴雪暖风时，幽意更依依。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"yue",
  "west" : __DIR__"xue",
]));
        set("objects", ([
        __DIR__"npc/liu" : 1,
                        ]) );

	set("coor/x",-45);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
