#include <ansi.h>

inherit __DIR__"cemetery";

string *names=({
	__DIR__"cemetery4",
	__DIR__"cemetery5",
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
        set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

/*
int valid_leave(object obj, string dir){
	object another;
	int num;
	
	seteuid(getuid());
	
	if (!present("zombie", this_object()) && random(10)>7) {
		switch (obj->query("quest/quest")) {
			case "老僵尸":	another = new(__DIR__"npc/zombie4");
							break;
			
			case "高僵尸":	another = new(__DIR__"npc/zombie3");
							break;
			
			case "瘦僵尸":	another = new(__DIR__"npc/zombie2");
							break;
			
			case "小僵尸":	another = new(__DIR__"npc/zombie1");
							break;
		}	
		
		if (!objectp(another)) {
			sscanf(file_name(this_object()),__DIR__"cemetery%d",num);
			switch (num) {
				case 1:
				case 2:
				case 3:
				case 4:	 another = new(__DIR__"npc/zombie1");
						 break;
				case 5:
				case 6:
				case 7:
				case 8:  another = new(__DIR__"npc/zombie2");
						 break;
				case 9:
				case 10:
				case 11:
				case 12: another = new(__DIR__"npc/zombie3");
						 break;
				default: another = new(__DIR__"npc/zombie4");
						 break;
			}
		}		
		another->move(environment(obj));
		message_vision(YEL"坟堆里慢慢站起一个人形向你扑来!\n"NOR, obj);	
		return notify_fail(another->name()+"张牙舞爪地挡在了你的面前。\n");
	}	
	return 1;
}*/
