inherit __DIR__"no_killing_place";
void create()
{
        set("short", "山林");
        set("long", @LONG
山林疏密有致，空气清新。脚下的柔软细草恰可没足，耳边有啾啾鸟语，鼻中
又嗅着花草幽香，面前的大树下有几只猴子在玩耍，不远处还有一群猴儿在林间跳
跃相戏，这里的一切充满了祥和的气息。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"linjian",
    ]));
    set("objects", ([
        __DIR__"npc/monkey1": 1,
//        __DIR__"npc/monkey2" : 1,
    ]) );
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
    replace_program( __DIR__"no_killing_place");
}


