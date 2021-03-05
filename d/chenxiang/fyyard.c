inherit ROOM;

void create()
{
	set("short", "紫藤花苑");

	set("long", @LONG
这里是风云客栈的紫藤花苑，通向大堂和两旁的客房。园子不大，开满了紫色
的花儿。一个紫衣少女站在紫藤花下，站在这轻纱般的迷雾里。一种神秘而朦胧的
美，使得她身旁的紫藤花也似已失去颜色。树下阴影中还似乎有个黑衣人静静地站
着。
LONG);

	set("type","grassland");
	set("exits",([
		"west":__DIR__"tingfengge",
		"south":__DIR__"fyhall",
	]) );
        set("outdoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",60);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/yuan":1,
		__DIR__"npc/wei":1,
	]));
	setup();
	replace_program(ROOM);
}
