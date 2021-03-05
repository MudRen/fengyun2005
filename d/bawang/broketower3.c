#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断塔三层");

	set("long", @LONG
这是断塔第三层。除了蛛网灰尘和一阵阵阴冷的风外，四下似乎什么都没有。
四面窗户上糊著的纸已残破了，被风吹得“哗啦，哗啦”的响。越走到上面，风越
大。声音越响，你的心也跳得越快。往上走的木梯腐朽破败，似乎随时会塌落。
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"broketower4",
		"down":__DIR__"broketower2",
	]) );

	set("objects", ([
		__DIR__"npc/ghost": 3,
	]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping exits;
	object room;
	exits=query("exits");
	room=load_object(exits["down"]);
	if( dir == "up" && (int)me->query("food")-random(10)> 650)
	{
		message_vision(HIR"“喀吧！”腐朽的木板难以承受$N之重，一下子断裂开来！\n\n"NOR,me);
		message_vision(HIR"$N一不小心，姿势美妙地倒栽葱摔了下来......\n“呯！”$N脑袋插进了腐朽的木板里面。\n "NOR,me);
		tell_room(room,HIR+me->query("name")+"一不小心，摔了下来。\n "NOR);
		me->move(room);
		me->receive_wound("kee",2);
		return notify_fail(HIW" “这楼梯可不太结实，下回来爬得少吃点先。。。”\n"NOR);
	}
//	if(!NATURE_D->is_day_time()){
		tell_object(me,HIM "\n
		
你刚一上来，隐约听见头顶上传来两个人断续的对话声:

“你...不到我...来？但是...却早已想到你......”
“我们...的事，...并没有错。最不幸的，...我已来了，你...来了。”
\n\n"NOR);
//	}		
	return 1;
}
