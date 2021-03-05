inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"鸟屋"NOR);

	set("long", @LONG
鸟屋是栋奇怪的木屋，建造在巨大的光阴树上。木屋的四周都有栏杆，屋檐鸟
翅般向外伸出，檐下挂满了手工精细的鸟笼。手工精细的鸟笼里，鸟语啁啾，木屋
宽大空阔，中壁的木板都已很陈旧，有的甚至已干裂，无疑已是栋多年的老屋，屋
里只有一张低矮的木桌、一个巨大的火盆和一个人。
LONG);

	set("type","street");
	set("exits",([
		"down":__DIR__"timetree",
	]) );
        set("indoors", "guanwai");

	set("objects", ([
                __DIR__"npc/xiaofang" : 1,
	]) ); 
	set("coor/x",-10);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
