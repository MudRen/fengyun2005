// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y,int z) {
	
	int exit_number;

		string name;

	name = "祭天塔";
	name += chinese_number(z+1);
	name += "层";
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
	} else 	if (exit_number==1) {		//	Deadend
		room->set("pos","deadend");
	} else {							//	Normal description
		room->set("pos","normal");
	}
	
		room->set("long",@LONG
祭天塔中与塔外光洁的光景大相径庭，只见蛛网牵结，尘土密布，两侧的佛
像覆满烟灰，一根根香烛烬冷，孤零零地立在台座之上，阵阵冷风幽幽，掠塔而
过，檀木的楼梯盘旋着向塔顶延去。
LONG
	);

	room->set("short",MAG+name+NOR);

}

void 	setup_npc_obj(object room,int length, int width, int x, int y, int z)
{
		object icecave;
		int boss_x,boss_y;

		z++;
		
		room->set("objects",([				
			__DIR__"npc/maze_guard"+z:	1,
//			__DIR__"npc/maze_guard"+(random(z)+1):	!random(4),	
		]));	
		
		room->setup();
		
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
