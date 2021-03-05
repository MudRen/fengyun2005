// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "会善寺");
        set("long", @LONG
会善寺左倚象鼻山，右靠卧龙岭，苍松翠柏，芳草如茵，清泉潆绕，景色清幽，
后成为名僧澄觉大师的精舍。但是真正出名是因为这里是天文家僧一行出家的地方。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shita", 
  "southwest" : __DIR__"talin",
]));
        set("objects", ([
                __DIR__"obj/status" : 1,
		__DIR__"npc/xiangke" : 1,
       ]) );
	set("coor/x",70);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
