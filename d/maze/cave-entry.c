// silencer@fy4 workgroup 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "鬼窟");
	set("long", @LONG
这儿原来只是个很普通的山洞，由于地处偏僻，罕无人迹，三清观的道人们经
常到这儿练气打坐，甚至还放了一个鼎炼丹，后来不知为了什么道人们再也不来了，
洞里却时常穿出一些奇怪的响动，几个胆大的当地人打着火把进区查看，三天后逃
出来唯一的一个，却已经吓疯了，从此这个洞就被叫做“鬼窟”。 
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ 
		"out" : AREA_DAOGUAN"ping_tai",
		"south" : __DIR__"cave-maze/entry",
	]));
	set("NONPC",1);
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();

}

//	这儿演示 refresh maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"cave-maze");
	if (!maze_room) return 1;
	flush_msg=HIB"忽然间一阵阴风吹过，周围的洞壁忽然移动起来。。。。
一阵天摇地转，你发现自己又回到了鬼窟的进口。\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

/*
太阳春辣至极，正发出万度光芒，刺于地面。
    天空没有一片云，而地上也没有一棵树。
    但一丛丛枯黄且多刺的野草仍是随处可见，却更添荒凉
况味．
    此处连绵一百七十里，尽是黄土，而小山丘及畸形巨石
有满四周，并无间断。
*/