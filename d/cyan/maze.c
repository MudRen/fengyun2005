// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER2;

void create()
{
	set_inherit_room(__DIR__"maze-room");

	set_maze_long(4,4,7);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("down");

	set_link_entry_dir("out");
	set_link_entry_room(__DIR__"bottom17");
	set_link_entry_room_x(-10);
	set_link_entry_room_y(40);
	set_link_entry_room_z(900);
	
	set_link_exit_dir("up");
	set_link_exit_room(__DIR__"bottom18");

	set_entry_short(MAG"祭天塔底"NOR);
	set_entry_desc(@LONG
祭天塔中与塔外光洁的光景大相径庭，只见蛛网牵结，尘土密布，两侧的佛
像覆满烟灰，一根根香烛烬冷，孤零零地立在台座之上，阵阵冷风幽幽，掠塔而
过，檀木的楼梯盘旋着向塔顶延去。
LONG
);

	set_exit_short(CYN"祭天塔顶"NOR);
	set_exit_desc(@LONG
祭天塔中与塔外光洁的光景大相径庭，只见蛛网牵结，尘土密布，两侧的佛
像覆满烟灰，一根根香烛烬冷，孤零零地立在台座之上。楼梯在这里盘旋而尽，
向上望去，已经可见缝隙中透出塔外的天空，不知从哪里传来一阵一阵凄凉的笛
音，拂动着你的心绪。
LONG
);

	set_maze_room_short(MAG"祭天塔"NOR);
	set_maze_room_desc(@LONG
祭天塔中与塔外光洁的光景大相径庭，只见蛛网牵结，尘土密布，两侧的佛
像覆满烟灰，一根根香烛烬冷，孤零零地立在台座之上，阵阵冷风幽幽，掠塔而
过，檀木的楼梯盘旋着向塔顶延去。
LONG
);

//	set_outdoors(1);

}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
