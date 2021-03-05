inherit ROOM;
void create()
{
        set("short", "黑暗走廊");
        set("long", @LONG
这的走廊似乎更加黑暗和阴冷，还透着浓厚的血腥气味。周围的空气似乎都已
经凝结了起来，沉重地让人透不过气来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
         "east" : __DIR__"zoulang1",
         "west" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/dizi": 1,
                        ]) );

	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
