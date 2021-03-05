
inherit ROOM;

void create()
{
        set("short", "塞外风光");
        set("long", @LONG
地势到这豁然开朗，你的西边是一望无际的沙漠。狂风在呼哮，漫天黄沙在飞
舞，飞沙滚滚。沙砾打在你的身上，就像是苍穹怒投下的冰雹。冥冥中仿佛已有种
邪恶的力量，任何人随时都有可能突然像野狗般死在沙砾上。路牌上指着：
    [33m  『大沙漠向西，行商需备足水源，结队而行』[32m
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"saiwai",
  "west" : __DIR__"desert_entrance",
]));
        set("outdoors", "quicksand");
	set("coor/x",-1060);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

