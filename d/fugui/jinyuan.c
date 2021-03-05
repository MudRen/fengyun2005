inherit ROOM;

void create()
{
	set("short", "金风玉露园");

	set("long", @LONG
若你以为金大帅象他的名字那么俗气，那就大错特错了，金大帅的涵养学识极
高，从金风玉露园你便可知道，园中假山峰峦叠嶂，曲折盘旋，石洞连绵不断，幽
深莫测。凭栏眺望，满目石峰嶙峋，古柏虬枝盘绕，园外平台宽阔，俯瞰沃野；远
眺群峰逶迤。
LONG);

	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"southeast":__DIR__"jinshi",
		"northeast":__DIR__"jinmen",
	]) );
	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/guard1":1,
		__DIR__"npc/guard1a":1,
    __DIR__"obj/jiashan" : 1,
    __DIR__"obj/hole" : 1,
	]));
	setup();
	replace_program(ROOM);
}
