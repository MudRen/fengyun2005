// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "观音石");
        set("long", @LONG
穿过云门到天都峰下，即可看到一个亭亭玉立的石人，活象一尊古装仕女，人
称观音石。正面一块小石，恰如跪拜之童子，这“小甚侏儒大娉婷”的两块巧石，正
好构成“童子拜观音”。从这里便开始了“盘空千万仞，险若上丹梯。迥入天都里，
回看鸟道低”的登顶过程。
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"mroad3",
  "westup" : __DIR__"yingke",
  "northwest" : __DIR__"tanhai",
]));
        set("objects", ([
        __DIR__"obj/guanyin" : 1,
	__DIR__"obj/xiaotong" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
