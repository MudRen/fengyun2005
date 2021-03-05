// Room: qigeban.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "七个半");

	set("long", @LONG
这里本是一块很大的空地，但现在却草草搭了个牛肉铺子。老板便是附近一带
大大有名的"七个半"，这人在市井中本来已很有名，后来又在这里摆了个牛肉摊子，
无论牛肉面也好，猪脚面也好，都只卖七个半大钱一碗。几十张桌子都已坐满了人，
不少还衣着整齐华贵。各式各样不同的人。空地的旁边，还停着很多车马。一大片
空地上，只有最前面吊着几个灯笼。灯笼已被油烟熏黑，根本就不太亮。 
LONG);
	//{{ --- by MapMaker
	set("exits",([
	"southdown":__DIR__"nilu3",
	//"northeast":__DIR__"nilu4",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/sevenhalf" :1,
	__DIR__"npc/haoke"  :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",50);
	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object me,room;
	me=this_player();
	if (arg != "curtain") return 0;
	if (me->query_temp("山流/七个半") 
		|| (mapp(me->query("organization")) 
		&& (string)me->query("organization/org_name")=="山流"))
	{
		message_vision("$N掀开牛肉铺子后被油烟熏得分不清颜色的帘子。一弯身，钻了进去\n",me);
		room = find_object(__DIR__"nilu4");
		if (!room)
		{
			room = load_object(__DIR__"nilu4");
		}
		me->move(room);
		return 1;
	}
	return 0;
}
