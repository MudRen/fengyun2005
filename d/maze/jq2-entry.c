// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "地牢入口");
	set("long", @LONG
这里是金钱帮的地牢所在，上官枭雄之志，江湖中的异己若非必杀之而后快，
便是暗中囚禁于此。近日江湖传言，上官得一异人，可炼制各种各样的秘药，或杀
人无形，或驱人疯狂，或制人神智。。。一时之间，江湖中人皆惶惶不可终日。而
据说无数为金钱捕获的高手尽在地牢中被炼化成无知无觉，只晓杀戮的行尸走肉。 
LONG
	);

	set("exits", ([ 
		"up" : 		__DIR__"jq1-entry",
		"east" : 	__DIR__"jq2-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",-40);
	set("coor/y",-15);
	set("coor/z",-20);
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
		
	maze_room=find_object(__DIR__"jq2-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"一阵阴风吹过，刺人骨髓，仿佛一场恶梦。。。\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

