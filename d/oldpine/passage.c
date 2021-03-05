// Room: /d/oldpine/passage.c

inherit ROOM;

void create()
{
        set("short", "秘密通道入口");
        set("long", @LONG
你现在正站在一个岩石的通道之中，在你南边有一片亮晶晶的帘幕，从帘幕後
面传来阵阵轰隆隆的水声，通道两边的石壁上安置著许多铜铸的烛台，照亮了这个
密穴，往北似乎有亮光。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  		"帘幕" : "这片帘幕似乎是用一种极薄的丝绸织成的，後面还传来阵阵水声。\n",
	]));
        set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"secrectpath1",
  		"south" : __DIR__"waterfall",
	]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/maniac" : 1,
	]));
        
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
