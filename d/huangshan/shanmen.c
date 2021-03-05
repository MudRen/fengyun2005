// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石雕门坊");
        set("long", @LONG
这是一座石雕门坊，过了石门后，便是黄山，从石门望去，只见万峰叠翠，入
眼一片翠绿。群峰连绵百里，峰顶云雾缭绕，苍松翠柏迎来游人无数。路北有一小
酒肆，供游人歇脚。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan", 
  "north" : __DIR__"jiusi", 
  "east" : AREA_CHENXIANG"cxs1",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
