// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "夜叉殿");
	set("long", @LONG
这是少林一百零八罗汉堂的首堂。夜叉者，维护众生界者，吃妖食鬼。《维摩 
经》注：夜叉三类：在地，在空虚，天夜叉也。殿上四壁刻着夜叉八大将，獠牙青 
面，栩栩如生。两个天夜叉雕像站在通道两边，怒目而向，钢叉指天，大殿肃穆静 
寂，似乎一丝风都没有。
LONG
	);

	set("exits", ([ 
		"out" : 	AREA_SONGSHAN"houmen",
		"east" : 	__DIR__"sl-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",70);
	set("coor/y",30);
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
		
	maze_room=find_object(__DIR__"sl-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"突然四殿佛唱一般轰隆隆巨响起来，逐渐又平息了下来。\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

