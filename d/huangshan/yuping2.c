// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "玉屏楼一楼");
        set("long", @LONG
楼不大，每一层约有四五个房间，门外是长廊。房间内还算干净，并没有落满
蛛网尘埃，然而四壁空空，只剩下雕花的窗户。临长廊种着一颗石榴树，茂密的枝
条已经伸展到楼上。此楼据说是一来自京城富商所建，为了寻找在黄山隐居的神医
为其独子治病，结果如何没有人知道。
LONG
        );
    set("exits", ([ 
  		"down" : __DIR__"yuping",
		"up" : __DIR__"yuping3",
	]));

    set("indoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",50);
                set("objects", ([
	__DIR__"npc/xiaosi" : 2,
                        ]) );
    
	setup();
        replace_program(ROOM);
}
