inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菊园门");
        set("long", @LONG
他住的地方就是座花海，一片花城．在不同的季节中，这里总有不同的花盛开。
他总是住在花开得最盛的那个地方。现在开得最艳的就是菊花，所以老伯就在菊花
园里接待他的宾客。没有人真正知道孙玉伯究竟是个怎么样的人？究竟能做什么事？
但无论谁有了困难，有了不能解决的困难时，都会去求他帮助。
LONG
        );
        set("exits", ([ 
		"south" :   	__DIR__"mroad3",
		"northwest" : 	__DIR__"garden2",
		"northeast":	__DIR__"garden4",
	]));
        set("objects", ([
		__DIR__"npc/sunjian":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",950);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


int valid_leave(object who,string dir) {
	
	object sun;
	
	sun=present("sun jian",this_object());
	if (!sun ) return 1;
	
	if (dir=="northwest" || dir=="northeast"){
		if (who->query("timer/菊园失败") + 1440 > time()) {
			message_vision("$N对$n说：你不是被赶出来了么，还有脸回来？\n", sun, who);
			return notify_fail("");
		}
		
		if (!who->query_temp("zangbei/see_lv") 
			&& REWARD_D->riddle_check(who,"菊园传奇")< 2	
			&& !REWARD_D->check_m_success(who,"菊园传奇")) {
			message_vision("$N伸手挡住了$n说：“请问找谁？”\n",sun,who);
			return notify_fail("");
		}
	}
	return 1;
}
	
		