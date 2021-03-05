// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	set_inherit_room(__DIR__"icecave-room");

	set_maze_long(8,10);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("north");

	set_link_entry_dir("out");
	set_link_entry_room(__DIR__"icecave");
	set_link_entry_room_x(-20);
	set_link_entry_room_y(-10);
	set_link_entry_room_z(30);
	

	set_link_exit_dir("south");
	set_link_exit_room(__DIR__"icecave-exit");

	set_entry_short(HIR BLK"冰洞入口"NOR);
	set_entry_desc(@LONG
往洞中深处走来，四面的寒气越来越重。看似坚硬的冰层在你脚下嘎吱作
响，脚步声回荡在冰洞之中，显得分外清晰。在洞外斜射进的微光照射下，隐
隐约约可以见到洞内雪柱倾横，晶莹的冰壁浑然各处，构成了一座天成的冰雪
迷宫。
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
