// Room: /d/oldpine/keep3.c

inherit ROOM;

void create()
{
        set("short", "老云寨大厅");
        set("long", @LONG
这里就是老云寨的大厅了，靠北边的地面上铺了一张巨大的熊皮，上面摆了三
张椅子，大厅四周散落著几个取暖用的火盆，几个上了锁的木箱子，比较奇特的是
中央掘了一个大坑，坑里是许多头骨，浸在一种发着恶臭的黄水之中。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"keep2",
                "south" : __DIR__"keep4",
        ]));
        set("objects", ([
                __DIR__"npc/bandit_leader": 3,
                __DIR__"npc/bandit_commander":1,
                __DIR__"npc/bandit_guard" : 3,
        ]) );

        set("coor/x",60);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
