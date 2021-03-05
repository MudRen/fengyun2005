#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断塔四层");

	set("long", @LONG
这是断塔第四层。除了蛛网灰尘和一阵阵阴冷的风外，四下似乎什么都没有。
四面窗户上糊著的纸已残破了，被风吹得“哗啦，哗啦”的响。越走到上面，风越
大。声音越响，你的心也跳得越快。往上走的木梯腐朽破败，似乎随时会塌落。
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"broketower5",
		"down":__DIR__"broketower3",
	]) );
	set("objects", ([
		__DIR__"npc/ghost": 2,
	]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string dir)
{	object *inv;
	int t_weight;
	int i;
	mapping exits;
	object room;
	exits=query("exits");
	room=load_object(exits["down"]);
	inv = all_inventory(me);
	t_weight = 0;
	for(i=0; i<sizeof(inv); i++)
	{
		t_weight = t_weight + inv[i]->weight();
	}
	if( dir == "up" && t_weight > 140000)
	{
		message_vision(HIR"“喀吧！”腐朽的木板难以承受$N之重，一下子断裂开来！\n\n"NOR,me);
		message_vision(HIR"$N一不小心，姿势美妙地倒栽葱摔了下来......\n“呯！”$N脑袋插进了腐朽的木板里面。\n "NOR,me);
		tell_room(room,HIR+me->query("name")+"一不小心，摔了下来。\n "NOR);
		me->move(room);
		me->receive_wound("kee",2);
		return notify_fail(HIW" “这楼梯可不太结实，看来得放下些东西再爬......”\n"NOR);
	}
//	if(!NATURE_D->is_day_time()){
		tell_object(me,HIM "\n
		
进到这里，头顶上的对话声越来越清晰：

“你认为我不该来？”
“我们两个人之中，总有一个是不该来的。”
“现在我们两个人之中，已势必只有一个能活着回去。”
\n\n"NOR);
//	}
	return 1;
}

/*void init() {
	if(NATURE_D->is_day_time()){
		return;
	} else {
		call_out("greeting", 1, this_player());
	}
}

void greeting(object me){

}
*/