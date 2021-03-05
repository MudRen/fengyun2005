// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "古瞭望台内");
    set("long", @LONG
瞭望台的一半已经倒塌。脚下踩着一片片碎裂的石瓦，仿佛岁月在无声间
流过，曾经傲立于山颠似乎永远不会倒下的岗哨，也已半化作还归自然的枯土
。瞭望台背风的另一半勉强还可称未坏，有架摇摇欲坠的半朽扶梯摆放在角落
中，想来是当年遗留下来的古物。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/pot":2,
	]));
	set("item_desc", ([

	"石瓦":"当年的石瓦如今早已片片碎裂，散落满地，覆得瞭望台内的地面高低不平。\n",
	"tile":"当年的石瓦如今早已片片碎裂，散落满地，覆得瞭望台内的地面高低不平。\n",
	"扶梯":(: look_stone :),
	"ladder":(: look_stone :),

	]) );
	set("exits",([
  		"eastdown" : __DIR__"path6",
//  		"up" : __DIR__"peak4",		// Climb up,remove this later.
	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}


string look_stone()
{
	object me = this_player();
	if (!query("ladder"))
	{
		tell_object(me,"扶梯断成数截朽在地上。\n");
		return " ";
	}
	if (me->query_temp("annie/cyan_ladder"))
		tell_object(me,"腐朽不堪的扶梯下放着两个经年历久，早已褪去色泽的陶罐。\n");
	else
		tell_object(me,"一架摇摇欲坠，腐朽不堪的扶梯，你有点怀疑它还能不能经受住你的重量。\n");
	me->set_temp("annie/cyan_ladder",1);
	return " ";
}


void init()
{
	add_action("do_climb","climb");
	add_action("do_search", ({"search"}));
}

int do_climb(string arg)
{
	object me,room;
	me=this_player();
	if (!arg || (arg!="ladder" && arg!="扶梯") || !me->query_temp("annie/cyan_ladder"))

		return notify_fail("你想爬什么？\n");;
	if (!query("ladder"))
		return notify_fail("这里没有"+arg+"。\n");;
	
	if (me->query_encumbrance() > 10000 )
	{
		if (!me->query_temp("annie/cyan_ladder"))
		{
			me->set_temp("annie/cyan_ladder",1);
			return notify_fail("这扶梯可不太结实，看来得放下些东西再爬．．．\n");
		}
		else
		{
			set("ladder",0);
			tell_object(me,CYN"\n只听得喀嚓一声，腐朽的梯子难以承受你的重量，一下子塌了下来！\n尘土飞扬中你砰一声摔在地上，额头撞到墙角，鼓起了一个小包．．．\n\n还是减肥以后再来吧。\n"NOR);

    set("long", @LONG
瞭望台的一半已经倒塌。脚下踩着一片片碎裂的石瓦，仿佛岁月在无声间
流过，曾经傲立于山颠似乎永远不会倒下的岗哨，也已半化作还归自然的枯土
。瞭望台背风的另一半勉强还可称未坏，角落中堆积着一堆朽烂的木头和破碎
的陶片。
LONG
NOR
        );
		room=this_object();
		me=present("陶罐",room);
		if (me)
			destruct(me);
		me=present("陶罐",room);
		if (me)
			destruct(me);

			return 1;
		}
	}


	room=find_object(__DIR__"peak4");
	if (!objectp(room)) room=load_object(__DIR__"peak4");
	tell_object(me,"你沿着扶梯向瞭望台顶爬去。\n");
	tell_room(room, this_player()->name() + "从瞭望台下爬了上来。\n");
	this_player()->move(room);
	return 1;
}


int do_search(string arg)
{
	object me = this_player(),he;
	if (me->is_busy() || me->is_fighting())
	{
		write("你现在正忙。\n");
		return 1;
	}
	if (!query("ladder"))
	{
		write("扶梯的残尸横七竖八地躺在地上。\n");
		return 1;
	}

	message_vision("$N在残砖碎瓦中四处摸索。\n",me);
	if (query("get2") || random(3))
		tell_object(me,"然而你什么都没有找到。\n");
	else
	{
		set("get2",1);
		message_vision("$N似乎摸到了什么，鬼鬼祟祟地揣进怀里。\n",me);
		he = new(__DIR__"obj/tile");
		he->move(me);
	}

	me->perform_busy(4);
	return 1;
}

void reset()
{
	object river,stone,*inv;
	
	::reset();
	set("ladder",1);
	    set("long", @LONG
瞭望台的一半已经倒塌。脚下踩着一片片碎裂的石瓦，仿佛岁月在无声间
流过，曾经傲立于山颠似乎永远不会倒下的岗哨，也已半化作还归自然的枯土
。瞭望台背风的另一半勉强还可称未坏，有架摇摇欲坠的半朽扶梯摆放在角落
中，想来是当年遗留下来的古物。
LONG
NOR
        );


	river = present("陶罐 2", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 && !query("get"))
	{
		stone = new(__DIR__"obj/amulet7");
		if(stone)
			stone->move(river);
		set("get",1);
	}

	delete("get2");
	return;
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


