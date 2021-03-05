#include <ansi.h>
inherit __DIR__"cemetery";

string *names=({
	__DIR__"cemetery10",
	__DIR__"cemetery8",
	__DIR__"cemetery4",
	
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
        set("coor/x",-100);
	set("coor/y",0);
	set("coor/z",0);
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
		"north" : __DIR__"cemetery_a",
		"south" : names[0],
		"east" : names[1],
		"west" : names[2],
	]));
}
