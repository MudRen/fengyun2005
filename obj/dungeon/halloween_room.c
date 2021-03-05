// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
}


void setup_room_desc(string owner,object room,int length, int width,int height, int x, int y,int z) {
	object who;
	int exit_number;
	string name;

	who = find_player(owner);

	name = owner+CHINESE_D->chinese_number(z+1)+"层";
	
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
		name += "堆";
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

int destruct_maze()
{
	object user;
	user= query("mark_ob");
	if (!user)
		return 0;	// 等待600秒销毁函式自行作用
//	message_vision("a"+user->query_temp("maze")->query_owner(),user);
	user->query("private_mazer/maze")->remove_all_players(user->query("private_mazer/maze"),user->query_temp("maze_entry"),"郭大妈高喊道：出来，出来了诶！封窖的时候到了！\n你现在可以向郭大妈回报结果(end)了……\n");
	user->query("private_mazer/maze")->refresh_maze();
	return 1;
}

void setup_room_obj(string owner,object room,int length, int width, int height,int x, int y,int z)
{
	object who,i;
	int file;

	seteuid(getuid());
	who = find_player(owner);

	if (who)
		room->set("long",owner+"的南瓜仓库。\n");

	room->set("x",x);
	room->set("y",y);
	room->set("z",z);
    room->set_max_encumbrance(100000000000);

	if (!who)
		return;

	room->setup();

	if (room->query("aaaa"))
		return;
	

	room->set("aaaa",1);
	who->add_temp("annie_quest/halloweenx",1);
		
	if (!random(3))
	{
		if (who->query_temp("annie_quest/halloween")< 20)	// 上限上限 :)
			who->add_temp("annie_quest/halloween",1);
		i=new(__DIR__"pumpkin");
		i->move(room);
		i->set("ol",who);
	}
	else
		who->add_temp("annie_quest/halloweenc",1);

}

int setup_entry_room()
{
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


