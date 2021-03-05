// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "玄冰洞");
        set("long", @LONG
冰洞处在山上的背阴一面，终年不得阳光直射，洞中的冰棱犬牙相错，粗
的需数人合抱，而细的也只不过小指宽长。绕过洞口的冰棱，可以见到玄冰洞
深处还有一个细窄的小口，似是洞中之洞，里面一片墨黑。
LONG
        );
	set("objects", ([
		__DIR__"npc/iceguardian" : 1,
	]));
	set("item_desc",	([
		"冰棱": "洞中的冰棱犬牙相错，粗的需数人合抱，细的只不过小指宽长（pick）。\n",
		"icicle":"洞中的冰棱犬牙相错，粗的需数人合抱，细的只不过小指宽长（pick）。\n",
		"小口":	"洞深处还有一个细窄的小口，似是洞中之洞，里面一片墨黑。\n",
	]));
	
	set("exits",([
		"up":	__DIR__"narcissus_place",
  		"out" : __DIR__"huxian",
  		"enter" : __DIR__"icecave-maze/entry",
	]) );

	set("indoors", "xiangsi");

	set("iceblade",3);

	set("NONPC", 1);
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
}

void generate_maze()
{
	object icecave;
	object maze_room;
	string flush_msg;
	int boss_x,boss_y;

	if (query("icecave/maze"))
		return;
	set("icecave/maze",1);

	maze_room=find_object(__DIR__"icecave-maze");
	if (!maze_room)
		maze_room=load_object(__DIR__"icecave-maze");
	flush_msg=HIR BLK"\n冰洞里传来阵阵开裂的声音，措手不及间，你脚下的冰块突然粉\n碎，将你自冰层上抛了下去．．．\n\n"NOR;
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();

	icecave = this_object();
	boss_x = random(8);
	boss_y = random(10);
	icecave->set("icecave/boss_x",boss_x);
	icecave->set("icecave/boss_y",boss_y);

}

void generate_maze2()
{
	object icecave;
	object maze_room;
	string flush_msg;
	int boss_x,boss_y;

	if (query("icecave2/maze"))
		return;
	set("icecave2/maze",1);

	maze_room=find_object(__DIR__"icecave2-maze");
	if (!maze_room)
		maze_room=load_object(__DIR__"icecave-maze");
	flush_msg=HIR BLK"\n冰洞里传来阵阵开裂的声音，措手不及间，你脚下的冰块突然粉\n碎，将你自冰层上抛了下去．．．\n\n"NOR;
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();

	icecave = this_object();
	boss_x = random(8);
	boss_y = random(10);
	icecave->set("icecave2/boss_x",boss_x);
	icecave->set("icecave2/boss_y",boss_y);

}

void init()
{
	add_action("do_pick", "pick");
	generate_maze();
}

int do_pick(string arg)
{
	object me = this_player(),iceblade;
	if (!arg)
		return notify_fail(WHT"你要摘什么？\n"NOR);
	if (arg != "冰棱" && arg != "ice" && arg != "iceblade" && arg!="icicle")
		return notify_fail(WHT"你要摘什么？\n"NOR);
	if (!query("iceblade"))
		return notify_fail(WHT"冰柱上光秃秃的，早已都被人折没了。\n"NOR);
	if (me->query("class") != "moon" && present("ice guardian"))
		return notify_fail(WHT"你刚伸出手去，一股寒气就侵进你的衣颈，顺着脊背下滑．．．\n你打了一个冷颤：有鬼耶．．．还是算了吧！\n"NOR);
	message_vision(HIW"\n$N伸手握在冰柱上，用力一掰，一截冰棱应手而落。\n\n"NOR,me);
	iceblade = new(__DIR__"obj/iceblade");
	iceblade->move(me);
	add("iceblade",-1);
	return 1;	
}

void reset()
{
	::reset();
	set("iceblade",3);
}

