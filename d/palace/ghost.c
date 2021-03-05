
inherit ROOM;

void create()
{
        set("short", "鬼域");
        set("long", @LONG
走过＂奈何桥＂，四下寒气森森，飘渺著淡淡的白雾。迷蒙的白雾中，不时的
会出现一两具石塑的鬼像，有的牛首，有的马面，神情狰狞，在雾中看来，更是令
人心惊。越往前走雾气越浓。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"naibridge",
]));
        set("objects", ([
        __DIR__"obj/judge" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",10);
	setup();
}
void init()
{
        add_action("do_east", "go");
        
}
int do_east(string arg)
{
	object me;
	object room;
	me = this_player();
        
        if (arg == "east") {
	        message_vision("$N从东面的一处山窟钻了进去。\n", me);
		room = load_object(__DIR__"windhole");
		if(room) me->move(room);
		return 1;
	}
	
	return 0;
}
