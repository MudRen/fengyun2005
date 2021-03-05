inherit ROOM;
void create()
{
        set("short", "风云衙门");
        set("long", @LONG
这里是朝廷所设，风云城里的纠纷都可以在这里上状请求处理。大厅南首一张卷
檐木案，案上有个小竹桶，里面插着几根有知府官印的竹签。木案后的太师椅上铺着
雪绒皮，椅后屏风上红日青云图。上悬金边匾：
[31m
				明察秋毫
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
  "east" : __DIR__"shufang",
]));
        set("objects", ([
        __DIR__"npc/yayi1" : 3,
        __DIR__"npc/yayi" : 3,
        __DIR__"npc/yayi2" : 3,

                        ]) );
	set("NONPC",1);
	set("coor/x",-63);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
