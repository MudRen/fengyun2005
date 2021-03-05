// Room: qiongjie5.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "穷街");

	set("long", @LONG
附近百里的人谈到穷街都不免要眉头紧皱，因为这里简直是乞丐的天堂，加上
四处都是臭虫蟑螂老鼠，但奇怪的是却总是有些江湖汉子出入这里，当然大多是春
风得意地来，灰心丧气地走，因为不远处便是在江湖中小有名气的"金胡子赌坊"，
凡是男人没有不想到这来的，那里没有美丽的风景，没有很堂皇的房子，但却有好
酒、好菜、好看的女人、公平的赌博，十个男人中就至少有九个喜欢去。
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"west":__DIR__"pomen",
	"northeast":__DIR__"qiongjie4",
	]) );
	//}}
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
