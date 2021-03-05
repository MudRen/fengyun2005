inherit ROOM;

void create()
{
	set("short", "青石巷");

	set("long", @LONG
这是条青条石砌成的小巷，比起吉祥镇的小街宽敞了不少，倒也还算平整，路
旁两排楠木树修剪地整整齐齐，时不时还有几辆四轮的马车沿路飞快的冲入巷子。
再往南走就是远近闻名的金府了，想当初金大帅的连珠神弹十二发在江湖上也是一
绝，罕有敌手。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"south":__DIR__"jinmen",
		"north":__DIR__"shilu3",
	]) );
	set("coor/x",50);
	set("coor/y",70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
