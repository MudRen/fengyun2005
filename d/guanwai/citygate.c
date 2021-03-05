inherit ROOM;

void create()
{
        set("short", "城门");
        set("long", @LONG
石砌的城垣横布在布达拉宫和恰克卜里山之间，城里便是著名的[33m大昭寺[32m和八角
街，城外的小路向北通向高耸的[33m山峦[32m，向南连着郁郁葱葱的[33m密林[32m。城门在一座舍利
塔下，塔里藏着历代高僧的佛骨和无数神秘美丽的传说与神话。
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"octostreet",
		"east" : __DIR__"grassland4",
		"up"   : __DIR__"topoftower",
	        "northup": "/d/resort/smallroad",
	        "south" : "/d/ghost/lroad1",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/cityguard" : 2,
        ]) );

	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir) {
	object ob;
	ob = present("city guard",this_object());
	
	if (ob)
	if ( dir == "west" && me->is_naked())   {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"皱着眉头说：小孩子光着屁股跑来跑去，像什么样子！\n\n");
			else
				return notify_fail(ob->name()+"向你喝道：赤身裸体招摇过市，成何体统！！\n");
		}

	return 1;
}