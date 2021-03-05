//road1.c
inherit ROOM;
void create()
{
        set("short", "山坳");
        set("long", @LONG
转过一道山坳，这里郁郁苍苍，满山树木。北面山峰环抱，仿佛是条绝路。四
周极静，除了偶尔一两声鸟鸣和时续时断的水声，似乎什么也听不见。
LONG
        );
        set("exits", ([ 
  			"westdown" : __DIR__"road0",
  			"northup" : __DIR__"outroom",
		]));
        set("outdoors", "qianfo");
		set("coor/x",40);
		set("coor/y",-100);
		set("coor/z",-10);
		setup();
}

void init()
{
	add_action("do_listen","listen");
}


int do_listen(string arg)
{
	object bird;
	if(!query("already") && !present("bird"))
	{
		tell_object(this_player(),"你侧耳细听：＂扑楞楞楞＂，一只小山雀从树丛中飞了出来．．\n");
		bird = new(AREA_TIEFLAG"npc/littlebird");
		bird->move(this_object());
		set("already",1);
		return 1;	
	}
	else
		tell_object(this_player(),"你侧耳细听，但什么动静也没有。\n");
	return 1;
}


void reset()
{
	::reset();
	delete("already");
}
