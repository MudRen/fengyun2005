
inherit ROOM;

void create()
{
        set("short", "山谷口");
        set("long", @LONG
四下无声，只有风吹松涛，幽韵天成，仰视苍天，注视群山，令人不觉怆然而
发思古之幽情！往前看，只见一道飞岩，下临绝崖，只有一条宽约七寸的独木桥，
通达对崖。危桥在凛冽的谷风中不停地抖动。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bridge",
  		"northwest":	__DIR__"palace_gate",
  		"southwest" : AREA_EASTCOAST"palace_path5",
]));
        set("outdoors", "palace");

	set("coor/x",-110);
	set("coor/y",100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

