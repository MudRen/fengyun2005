// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小山门");
        set("long", @LONG
一扇小小的木门，无人看守，但少林寺内进去过的人绝对不超过十个，便是达
摩院的长老，在少林逾五十年的老僧，都未尝进去一览，擅入者从来没有出来过。
这扇门后究竟有什么已经成为少林后辈僧人心中最大的谜题。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"meiyuan",
  "west" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/owner" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}


int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "west" && ob=present("xie zhanggui",this_object()))
	{
		if (!me->query_temp("marks/pass_xiezhanggui")&& !REWARD_D->check_m_success(me,"入隐世楼"))
		{
			message_vision("$N对$n道：嘿！胆子真不小！想进去，没门儿！\n",ob,me);
			return notify_fail("");
		}
	}
	return 1;
}

