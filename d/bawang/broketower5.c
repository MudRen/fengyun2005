#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断塔五层");

	set("long", @LONG
这是断塔第五层。除了蛛网灰尘和一阵阵阴冷的风外，四下似乎什么都没有。
四面窗户上糊著的纸已残破了，被风吹得“哗啦，哗啦”的响。越走到上面，风越
大。声音越响，你的心也跳得越快。往上走的木梯腐朽破败，似乎随时都会塌落
下来。
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"toptower",
		"down":__DIR__"broketower4",
	]) );
	set("objects", ([
		__DIR__"npc/ghost": 2,
	]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",30);
	setup();
}

/*int valid_enter(object me)
{
	tell_object(me,HIM "\n
		
进到这里，头顶上的对话声越来越清晰：

“你认为我不该来？”
“我们两个人之中，总有一个是不该来的。”
“现在我们两个人之中，已势必只有一个能活着回去。”
\n\n"NOR);
	return 1;
}*/
