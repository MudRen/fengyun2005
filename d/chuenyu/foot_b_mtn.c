// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "黑松山");
        set("long", @LONG
你顺着山路走着。小路向着东边不断的伸展，越来越陡。小路两侧的松林死气
沉沉，静得连鸟叫声都没有……。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"base_b_mtn",
  "east" : __DIR__"foot_b_mtn2",
]));

	set("objects", ([
                __DIR__"npc/jiading" : 2,
	]) );

        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}
