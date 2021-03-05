inherit ROOM;

void create()
{
	set("short", "石室");

	set("long", @LONG
两尺厚的石门里，是一间九尺宽的石屋子。屋里阴森而寒冷，仿佛已到了古代
帝王陵墓的中心。本来应该停放棺材的地方，现在却摆着个巨大的铁箱，除此之外
什么也没有。
LONG);

	set("type","indoors");
	set("objects",([
		__DIR__"obj/case": 1,
		__DIR__"npc/guard" : 1,
	]) );
	set("exits",([
		"west":__DIR__"fyhall",
	]) );
        set("indoors", "chenxiang");
	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
