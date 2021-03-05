// Room: qiongjie3.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "穷街");

	set("long", @LONG
附近百里的人谈到穷街都不免要眉头紧皱，因为这里简直是乞丐的天堂，加上
四处都是臭虫蟑螂老鼠，但奇怪的是却总是有些江湖汉子出入这里，当然大多是春
风得意地来，灰心丧气地走，因为不远处便是在江湖中小有名气的"金胡子赌坊"。
LONG);
	//{{ --- by MapMaker
	set("exits",([
	"northeast":__DIR__"qiongjie2",
	"northwest":__DIR__"qiongjie4",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/snakebeggar" :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",25);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
