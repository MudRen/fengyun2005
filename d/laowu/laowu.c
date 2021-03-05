
inherit ROOM;

void create()
{
        set("short", "拉哈苏");
        set("long", @LONG
“拉哈苏”就在松花江之南，这三个字的意思就是“老屋”，它的名字虽然充
满了甜蜜和亲切，其实却是个荒僻而寒冷的地方，每到重阳前后，就开始封江，直
到第二年的清明才解冻。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"town",
  "south" : __DIR__"road5",
]));
        set("outdoors", "laowu");

	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

