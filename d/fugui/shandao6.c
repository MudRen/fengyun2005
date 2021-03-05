inherit ROOM;

void create()
{
	set("short", "白玉山路");

	set("long", @LONG
这是一条通往富贵山庄的崎岖山道。道旁半枯的秋草在夕阳下看来宛如黄金，
遍地的黄金石板砌成的小径斜向上方伸展，宛如黄金堆中的一串白玉。一抬头，可
以看见几个或是蜈蚣状，或是老鹰状的风筝高高飞舞在蓝天白云中。
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "southdown":__DIR__"shandao7",
        "northup":__DIR__"shandao5",
	]) );

	set("coor/x",10);
	set("coor/y",140);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
