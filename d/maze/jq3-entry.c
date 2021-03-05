// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "富贵门");
	set("long", @LONG
烟雾散尽，你发现自己竟到了另一个所在。金钱帮富甲天下，权可倾国，果
真不是风云城里那几件屋子可以容纳的下的，事实上，那几间豪宅只是上官金虹
处心积虑，掩人耳目的幌子，这里才是金钱帮的藏宝之地。从富贵门往里，每一
处都放满了金钱帮掠夺而来的财宝异物，自然也有无数的金钱死士守卫着。
LONG
	);

	set("exits", ([ 
		"east" : 	__DIR__"jq3-maze/entry",
		"exit" : AREA_FY"tang3",
	]));
	set("NONPC",1);
	set("coor/x",-20);
	set("coor/y",-9);
	set("coor/z",10);
	setup();

}

//	这儿演示 refresh maze,可以用flush来人工reset maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"jq3-maze");
	if (!maze_room) return 1;
	flush_msg=HIR"灯影摇红，地面轻轻地颤动，嘎吱一声后死一般的静了下来。\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

