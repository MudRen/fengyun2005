inherit ROOM;

void create()
{
        set("short", "营帐");
        set("long", @LONG
帐篷约有十丈见方，用破箱子堆起几个桌椅。两三个彪悍的马贼坐在一侧喝酒，
斜着眼打量着你。另一侧端坐着一个头戴蓝巾，身穿蓝衣的毛脸汉子，一手执着酒
杯，一手把玩着三个卵石般大的黑黝黝的铁蛋，眼光扫过，不怒自威。
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"banditcamp1",
	  	"north" : __DIR__"innercamp",
			]));
	set("objects", ([
		__DIR__"npc/banditleader" : 1,
	]));

        set("coor/x",-440);
	set("coor/y",620);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

int valid_leave(object obj, string dir){
//	int i;
	object bandit;
	if(dir == "north"){
		if (objectp(bandit=present("bandit leader")))
				return notify_fail(bandit->name()+"挡住了你的路。\n");
		
	}	
	return 1;
}

void init(){
	add_action("do_look","look");
}


int do_look(string arg){
	if (arg=="north"){
		tell_object(this_player(),"帐内黑咕隆咚地，什么也看不清楚。\n");
		return 1;
	}
	return 0;
}