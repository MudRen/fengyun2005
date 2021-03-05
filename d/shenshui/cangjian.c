// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏剑楼");
        set("long", @LONG
房间很空旷，但你在此不由感到呼吸有些困难，房子中央是三个兵器架，上面
分格摆满了各种武器，有的甚至还带有点点血迹，每种武器上方都有一字条，武器
上散发出的杀气，杀意令人倍感压力。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huayuan",
]));
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
