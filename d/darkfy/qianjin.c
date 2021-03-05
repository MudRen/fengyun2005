inherit ROOM;
int check_container(object ob);
void create()
{
        set("short", "千金楼");
        set("long", @LONG
这里就是当年红极一时的风月场所，千金楼。紧闭的枣红色的大门似乎依旧没变，可是
哪些漂亮的姑娘们早已经不知所踪，只剩下门口两只石狮子仍然静静的凝视着这
这一些。
long
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/fy/swind4",
]));


	set("outdoors","fengyun");
        set("objects", ([
        __DIR__"npc/" : 2,
                        ]) );
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",-300);
	setup();
}




