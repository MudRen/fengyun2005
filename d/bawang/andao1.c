inherit ROOM;

void create()
{
	set("short", "暗道");

	set("long", @LONG
这是一条暗道，本是饿虎山上的强盗们把财宝从断塔运至聚义厅的捷径，不过
显然很久已经没人来过了，阴暗潮湿的空气里，带著种腐朽的臭气，刺激得你几乎
连眼睛都睁不开。
LONG);

	set("type","street");
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",-10);
	set("exits",([
		"southup":__DIR__"andao2",
		"out":__DIR__"undertower2",
	]) );
	setup();
	replace_program(ROOM);
}
