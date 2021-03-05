inherit ROOM;

void create()
{
	set("short", "青石巷");

	set("long", @LONG
这是条青条石砌成的小巷，比起吉祥镇的小街宽敞了不少，倒也还算平整，路
旁两排楠木树修剪地整整齐齐，时不时还有几辆四轮的马车沿路飞快的冲入巷子。
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"southeast":__DIR__"shilu3",
		"southwest":__DIR__"shilu1",
	]) );
	set("coor/x",40);
	set("coor/y",90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
