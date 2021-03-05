// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "寝宫");
        set("long", @LONG
这里是白水娘娘的居所，屋中陈设平平，惟有墙上多了几幅挂画，诗词笔力遒
劲，下笔有神，似乎出自男子手笔。。。。。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"huayuan",
  "southeast" : __DIR__"gong",
]));
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
