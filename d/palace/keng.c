
inherit ROOM;

void create()
{
        set("short", "坑道边");
        set("long", @LONG
道路到了这里又有了分岔，两条黄土路左右分开，当中却有一个深坑。迷雾中
望去，坑中人兽杂乱，也不知有多深。一个虬须判官的石像，仰天立在坑边。风声
过处，坑底仿佛飘上了一阵鬼啸之声。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"woods",
  "north" : __DIR__"cliff",
  "west" : __DIR__"bladem",
]));
        set("item_desc", ([
                "虬须判官": "这是一个虬须判官的石像，他一手抚须，一手持剑，掌中之剑指向地上。。\n",
                "石像" : "这是一个虬须判官的石像，他一手抚须，一手持剑，掌中之剑指向地上。\n",
                "statue" : "这是一个虬须判官的石像，他一手抚须，一手持剑，掌中之剑指向地上。\n"
        ]) );
        set("outdoors", "palace");

	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);

	setup();
}
void init()
{
        add_action("do_down", "go");
        
}

int do_down(string arg)
{
	object me;
	object room;
	me = this_player();
        if (arg == "down") {
        	message_vision("$N纵身跳入坑中．\n", me);
		room = find_object(__DIR__"kengdi");
		if (!room) room = load_object(__DIR__"kengdi");
		me->move(room);
		return 1;
	}
	return 0;
}

