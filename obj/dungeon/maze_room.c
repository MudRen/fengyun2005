// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
}


void setup_room_desc(object room,int length, int width,int height, int x, int y,int z) {
	
	int exit_number;
	string name;
	if (z == height)
		name = "天";
	else if (z == 0)
		name = "地";
	else
		name = "间";
	
	if (y == 0)
		name += "南";
	else if (y == width)
		name += "中";
	else
		name += "北";

	if (x == 0)
		name += "西";
	else if (x == length)
		name += "中";
	else
		name += "东";

	exit_number= sizeof(room->query("exits"));
	if (exit_number == 3)
		name += "门";
	else if (exit_number == 2)
	{
		if (random(2))
			name += "路";
		else
			name += "道";
	}
	else
			name += "角";


	room->set("short",HIB BLK+name+NOR);
	room->set("long",@LONG

LONG
	);
	
}

void setup_room_obj(object room,int length, int width, int height,int x, int y,int z)
{
	room->set("x",x);
	room->set("y",y);
	room->set("z",z);
    room->set_max_encumbrance(100000000000);

	room->setup();
}

int destruct_maze()
{
	object user;
	user=find_player(query("mark_ob"));
	if (!user)
		return 0;	// 等待600秒销毁函式自行作用
//	message_vision("a"+user->query_temp("maze")->query_owner(),user);
	user->query("private_mazex/maze")->remove_all_players(user->query("private_mazex/maze"),user->query_temp("maze_entry"),"突然传来一阵天崩地裂般的撼动，你吓得连忙冲出迷宫，\n转头看去，整个迷宫已经崩毁於无形。\n");
	user->query("private_mazex/maze")->refresh_maze();
	return 1;
}

int setup_entry_room()
{
//	add_action("do_out","out");
	return 1;
}

int init()
{
	object boss,user,blocker;
	user=find_player(query("owner"));

	if (query("entry_room"))
		add_action("do_out","out");
	
	if (!user)
		return 0;	// 等待销毁函式作用，此间不会有任何npc出现
	
	seteuid(getuid());
	if (query("exit_room") && !query("exist"))	// 不可以放在setup-exit裡
	{
		boss=new("/d/bashan/npc/mazemaster2");
		if (!boss)
			return notify_fail("Error #13398. Please call wizard.\n");
		set("exist",1);
		boss->invocation(user);
		boss->move(this_object());
	}

	return 1;
}

object check_blocker()
{
	if (query("blocker"))
		if (environment(query("blocker")))
			if (environment(query("blocker")) == this_object())
				return query("blocker");
	return 0;
}

int valid_leave(object me,string dir)
{
	object who;
	if (who=check_blocker())
		return notify_fail(who->name()+"正拦在必经之路上，解决掉这个麻烦才能前进。\n");
    return 1;
}

int do_out()
{
	object me = this_player();
	object room;
	if (!room=me->query_temp("maze_entry"))
//		return notify_fail("Error #13447. Please call wizard.\n");
		return notify_fail("什么？\n");
	me->move(room);
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

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


