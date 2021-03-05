// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "霜笛清晓");
        set("long", @LONG
清晨的雾霭从带露的草叶上慢慢升起，在茂密的树叶上形成一片亮绿色的
朦胧。空气中漂浮着一丝难以觉察的淡淡清香，溪流里几朵落花打着旋儿向下
游荡去。四周寂然无声，没有哪怕是一点的动静，仿佛整个世界都在这一刻屏
住了呼吸。
LONG
        );
	set("objects", ([
		__DIR__"npc/suu" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"huju",
  		"south" : __DIR__"lingque",
	]) );
	set("no_fly",1);
	set("item_desc", ([
		"树叶": "你凝目看去，发现那是长势极好的新茶。\n",
		"leaf": "你凝目看去，发现那是长势极好的新茶。\n",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	set("tea",3);
	setup();
}


void init()
{
	add_action("do_pick", "pick");
}


int do_pick(string arg)
{
   
   	object me, tea;

   	me = this_player();
      
	if(!arg || (arg != "leaf" && arg != "tea" && arg!= "tealeaf" && arg!="新茶" 	&& arg!="茶"))
	{
		write("你要摘什么？\n");
		return 1;
	}

	if (!query("tea"))
	{
		write("茶叶已经被人摘光了。\n");
		return 1;
	}

	add("tea",-1);
	tea = new(__DIR__"obj/tea");
	tea->move(me);
	message_vision(CYN"$N摘下一些新成的茶叶。\n"NOR,me);
    return 1;
}

void reset()
{
	::reset();
	set("tea",3);
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (dir == "south" && present("suu zhanqing"))
	{
		me->add_temp("annie/blocked_by_suu",1);
		switch (me->query_temp("annie/blocked_by_suu"))
		{
		case 1:
			message_vision(CYN"苏绽青伸手拦住$N道：对不起，江姐姐正在那边沐浴，请不要过去。\n"NOR,me);
			return notify_fail(" ");
			break;
		case 2:
			message_vision(CYN"苏绽青对$N皱眉道：我不是已经告诉你不要过去了么？\n"NOR,me);
			return notify_fail(" ");
			break;
		case 3:
			message_vision(CYN"苏绽青对着$N一哼：你是一定要强闯的了？\n"NOR,me);
			return notify_fail(" ");
			break;
		}
		message_vision(CYN"苏绽青道：不许过去！\n"NOR,me);
		who->delete_temp("annie/blocked_by_suu");
		present("suu zhanqing")->kill_ob(me);
			return notify_fail(" ");
	}
	if (dir == "north") {
		who->delete_temp("annie/blocked_by_suu");
	}
	return ::valid_leave(who,dir);
}
