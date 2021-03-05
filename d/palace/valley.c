
inherit ROOM;

void create()
{
        set("short", "谷地");
        set("long", @LONG
只见四下流泉白石，奇松异草，将这四山环绕的谷地，点缀得有如神仙世界一
般。林木流水之间，点缀著许多栋飞檐凤阁，及一些假山亭台，一条石板缀成的道
路，蜿蜒通向前方。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house",
  "west" : __DIR__"garden3",
]));
        set("outdoors", "palace");

	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

