// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "大槐树上");
        set("long", @LONG
你现在正攀附在一株大槐树的树干上，从这里可以很清楚地望见树下的一切动
静，而不被人发觉，似乎是个干偷鸡摸狗勾当的好地方。
LONG
        );
        set("objects", ([
                AREA_QIANFO"npc/spy":1 ,
		AREA_QIANFO"npc/maque" : 2,
	]) );

        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tanghuai",
]));

	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
