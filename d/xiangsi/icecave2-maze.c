// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	set_inherit_room(__DIR__"icecave2-room");

	set_maze_long(8,10);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("north");

	set_link_entry_dir("north");
	set_link_entry_room(__DIR__"icecave-exit");
	set_link_entry_room_x(-20);
	set_link_entry_room_y(-120);
	set_link_entry_room_z(30);
	
	set_link_exit_dir("south");
	set_link_exit_room(__DIR__"icecave-exit");	// 没有实际出口，与迷宫入口相连

	set_entry_short(HIR BLK"冰结小道"NOR);
	set_entry_desc(@LONG
小心翼翼的行进在这七尺高下的冰道上，还要不时提防磕到洞顶垂下的冰棱，
或是被地上凹凸不平的冰坑冰渣绊倒，有时隔着薄薄的冰层已可看见出口，前方却
又是偌大的冰石阻住去路。你越向前行，心里的惊慌弥漫得越紧，而所有的期望，
都寄托在手中明灭不定的微弱光芒之上。
LONG
);

	set_exit_short(HIR BLK"冰结小道"NOR);
	set_exit_desc(@LONG
小心翼翼的行进在这七尺高下的冰道上，还要不时提防磕到洞顶垂下的冰棱，
或是被地上凹凸不平的冰坑冰渣绊倒，有时隔着薄薄的冰层已可看见出口，前方却
又是偌大的冰石阻住去路。你越向前行，心里的惊慌弥漫得越紧，而所有的期望，
都寄托在手中明灭不定的微弱光芒之上。
LONG
);

	set_maze_room_short(HIR BLK"冰结小道"NOR);
	set_maze_room_desc(@LONG
小心翼翼的行进在这七尺高下的冰道上，还要不时提防磕到洞顶垂下的冰棱，
或是被地上凹凸不平的冰坑冰渣绊倒，有时隔着薄薄的冰层已可看见出口，前方却
又是偌大的冰石阻住去路。你越向前行，心里的惊慌弥漫得越紧，而所有的期望，
都寄托在手中明灭不定的微弱光芒之上。
LONG
);

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
