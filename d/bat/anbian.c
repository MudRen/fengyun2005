// Apstone, Inc.
inherit ROOM;
void create()
{
 set("short", "人间地狱");
 set("long", @LONG
石头是死灰色的，冷、硬、狰狞；怒涛拍打着海岸，宛如千军呼啸，万马奔腾。
岛的四周礁石罗列，几乎每一个方向都有触礁的船只，看来就像是一只只被恶兽巨
牙咬住的小兔。无论多轻巧，多坚固的船，都休想能泊上海岸。天地萧杀。
LONG
	);

    set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"dong",
        "west" : __DIR__"kongdi",
    ]));
	set("objects", ([
        __DIR__"npc/dizi"   : 2,
        __DIR__"npc/xunluo" : 1,

    ]));

	set("outdoors", "bat");
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}



