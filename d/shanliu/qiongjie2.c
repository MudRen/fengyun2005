// Room: qiongjie2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "穷街");

	set("long", @LONG
附近百里的人谈到穷街都不免要眉头紧皱，因为这里简直是乞丐的天堂，加上
四处都是臭虫蟑螂老鼠，但奇怪的是却总是有些江湖汉子出入这里，当然大多是春
风得意地来,灰心丧气地走，因为不远处便是在江湖中小有名气的"金胡子赌坊"，
近几个月来金胡子赌坊正在大张旗鼓地进行维修，从各地运来的土木材料把道路都
堵住了。
LONG);

	//{{ --- by MapMaker
	set("exits",([
	"southeast":__DIR__"qiongjie1",
	"southwest":__DIR__"qiongjie3",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object who, string dir){
	
	if (dir == "southwest"){
		return notify_fail("小街上堆满了土木材料，一时半会儿怕是走不过去了。\n");
	}
	
	return ::valid_leave(who,dir);
}
