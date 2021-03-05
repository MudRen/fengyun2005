inherit ROOM;

void create()
{
	set("short", "断塔底层");

	set("long", @LONG
这是断塔第一层。除了蛛网灰尘和一阵阵阴冷的风外，四下似乎什么都没有。
四面窗户上糊著的纸已残破了，被风吹得“哗啦，哗啦”的响。越走到上面，风越
大。声音越响，你的心也跳得越快。往上走的木梯腐朽破败，似乎随时会塌落。
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"broketower2",
		"out":__DIR__"undertower",
	]) );

	set("objects", ([
		__DIR__"npc/ghost": 3,
	]));
	setup();
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",-10);
	replace_program(ROOM);
}
