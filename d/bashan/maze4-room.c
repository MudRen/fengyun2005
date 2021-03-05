// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short",CYN"藤条网上"NOR);
		room->set("long",@LONG
树枝上漫挂着无数的粗实的藤蔓，在这里编成了一道密匝的藤网。藤网如蛛网
般搭挂着边上的几条巨木，只要略加小心步过结实的藤网，就可以踩上直能让人齐
肩并行的粗大枝干。
LONG
	);
	} else 	if (exit_number==1) {		//	Deadend
		room->set("pos","deadend");
		room->set("short",CYN"树干尽头"NOR);
		room->set("long",@LONG
到了这里，你惊觉去路已尽，粗大的枝条渐渐收细，悬着的藤条也已经摇摇欲
坠，实在没有可能再承载一个人的重量。尽管不远处就有另一根粗干斜挂，却离开
你直有三五丈远，如果不想冒着坠落的危险尝试飞跃，就只有回头一途。
LONG
	);		
	} else {							//	Normal description
		room->set("pos","normal");
		room->set("short",CYN"粗大枝干"NOR);
		room->set("long",@LONG
行走在参天巨木的粗大枝干之上，你不由感叹於造化之奇，竟能有这样密密一
片树林，为巴山深处的隐秘提供了一道人力难以桓越的天然屏障。枝干前方挂着几
根儿臂粗细的藤条，看起来甚是结实，或许能让你继续前进。
LONG
	);
	}
	
}

void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;

	room->setup();

		icecave = new(__DIR__"mazenpc/maze1_guard"+(random(8)+10));
		icecave->move(room);

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
