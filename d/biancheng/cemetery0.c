#include <ansi.h>

inherit ROOM;
string *names=({
	__DIR__"cemetery1",
	__DIR__"cemetery2",
	__DIR__"cemetery3",
} );


void create()
{
        set("short", "坟场");
        set("long", @LONG
天色阴森，风也更冷，远处高低起伏，关帝庙的后面竟是一片无边无际的荒坟。
虽然是白天，荒坟间仍然有雾，坟中也仍然有自骨死人。阴沉的天气，凄迷的冷雾。
昏暗的天空中，一只鸟影正飞向西方，带着铃声飞向西方。西方有极乐世界。西方
也有穷山，恶水，旷野，荒坟。
LONG
        );
        set("outdoors", "biancheng");
        set("objects", ([
        	__DIR__"npc/oldman":	1,
	]) );
        set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	set("map","zbwest");
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=2;i++)
	{
		j=random(3);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : __DIR__"temple",
		"west" : names[2],
	]));
}


int valid_leave(object me, string dir) {
	
	object oldman;
	
	if (dir=="south" || dir =="north" || dir =="west")
	if (!REWARD_D->check_m_success(me,"扫荡僵尸")
		&& !REWARD_D->riddle_check(me,"扫荡僵尸")
		&& oldman=present("oldman",this_object())) {
		return notify_fail(oldman->name()+"挡住你说：坟地有鬼，还是不要去的好。\n");
	}
	return 1;
}

	
	