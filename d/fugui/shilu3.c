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
		"south":__DIR__"shilu4",
		"northwest":__DIR__"shilu2",
	]) );
	set("coor/x",50);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
