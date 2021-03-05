// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));

	switch (random(6))
	{
	case 0:
		room->set("short",CYN"惊鸿踏雪"NOR);
		room->set("long",@LONG

[1;36m   　　　　　       踏　　　雪 。  。  。 

[1;37m　　　八荒唯玉屑，万里何冰洁。足倦浮痕浅，断桥清泪绝。
[2;37;0m
LONG
	);
		break;
	case 1:
		room->set("short",CYN"他乡流泉"NOR);
		room->set("long",@LONG

[1;32m   　　　　　       听　　　泉 。  。  。 

[1;36m　　　琤琤谁叩弦，静夜诉缠绵。泫泫思乡泪，涓涓不尽泉。
[2;37;0m
LONG
	);
		break;
	case 2:
		room->set("short",CYN"尺素明珠"NOR);
		room->set("long",@LONG

[1;37m   　　　　　       读　　　诗 。  。  。 

[1;32m　　　青云落赤墀，紫燕唤相思。床头鸳鸯枕，枕边无字诗。
[2;37;0m
LONG
	);
		break;
	case 3:
		room->set("short",CYN"仙人落子"NOR);
		room->set("long",@LONG

[1;33m   　　　　　       敲　　　棋 。  。  。 

[1;31m　　　方圆处处羁，黑白总相持。落子闻余韵，岂关半目棋。
[2;37;0m
LONG
	);
		break;
	case 4:
		room->set("short",CYN"佳期如梦"NOR);
		room->set("long",@LONG

[1;34m   　　　　　       拈　　　花 。  。  。 

[1;33m　　　村墟沐晚霞，林壑宿青鸦。浅醉觉歌远，素手悄拈花。
[2;37;0m
LONG
	);
		break;
	case 5:
		room->set("short",CYN"深宫汉曲"NOR);
		room->set("long",@LONG

[1;31m   　　　　　       顾　　　曲 。  。  。 

[1;34m　　　菊艳橙新绿，风轻池水渌。西窗红泪烛，玉指阳关曲。
[2;37;0m
LONG
	);
		break;
	}
	
}



void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;
		icecave = load_object(__DIR__"enterance");
		icecave->generate_maze1();
		boss_x = icecave->query("maze1/boss_x");
		boss_y = icecave->query("maze1/boss_y");


		room->set("objects",([				
			__DIR__"mazenpc/maze"+(random(2)+2)+"_guard"+(random(8)+1):1,
		]));		

	if (x == boss_x && y == boss_y)
		room->set("objects",([				
			__DIR__"npc/jat":1,
		]));		


		set("x",x);
		set("y",y);
		room->set("exits/up",__DIR__"enterance");
		room->set("perma_exist",1);
		set("perma_exist",1);

		room->setup();
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
