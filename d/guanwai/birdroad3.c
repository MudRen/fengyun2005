inherit ROOM;

void create()
{
	set("short", "鸟道");

	set("long", @LONG
远处便是圣母雪峰了，藏人也称之为喜马拉雅山，晶莹的雪峰象一排排白玉雕
成的擎天玉柱，高插云霄，隐隐露出头来，似是正在倾听流浪者的哀弦凄诉。高原
空气稀薄，呼吸也颇困难，小路也弯弯曲曲，十分难行，因此当人称之为鸟道，意
思是连鸟儿都很难飞过这里。
LONG);
	
	set("type","street");
	set("exits",([
		"southwest":__DIR__"shanjiao",
		"northeast":__DIR__"timetree",
	]) );
        set("outdoors", "guanwai");
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
