#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long", @LONG
无边无际的丛林中一片黑暗，就是再烈的日光也穿不透那密密的树叶，黑暗中
充满了各式各样的危险，每一种都可以致命。若是在丛林中迷失了方向，饥渴就足
以致命。如果没人指引的话，生还的可能性是微乎其微的。
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest2",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest5",
		"west" : __DIR__"forest6",
	]));
	set("outdoors", "ghost");
        set("NONPC",1);
	set("coor/x",-90);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void init(){
	object me,c;
	me = this_player();
	if(c=present("hitch hiker's guide",me))
	{
		if (c->query("oops") == 1)
		{
			if (REWARD_D->check_m_success(me,"幽灵山庄"))
			{
				tell_object(me, HIG"眼前景色似乎有些熟悉，你翻开丛林探险指南，一瞬间恍然大悟。\n\n"NOR);
				tell_object(me, HIG"一阵怪风吹过，丛林探险指南化作片片蝴蝶随风而去。\n\n"NOR);
				me->set_temp("marks/know_ghost", 1);
				destruct(c);
			}
		}
	}
	
	if(me->query_temp("marks/know_ghost")){
		tell_object(me, HIG"眼前景色似乎有些熟悉，你依稀记得往南方的高处走有座山崖。\n\n"NOR);
		add_action("do_southup", "go");
	}

}


int do_southup(string arg){
	object room;
	object me=this_player();
	
	if (arg == "southup")
	if(me->query_temp("marks/know_ghost")) {
		message("vision", me->name()+"微一定神辨别了一下方向，身形在山林之中闪了几下就不见了。\n", 
				environment(me), me);	
		tell_object(me, HIG"\n眼前猛然一亮，一道山崖出现在眼前。\n"NOR);
		room = find_object(__DIR__"forest9");
		if(!objectp(room)){
			room = load_object(__DIR__"forest9");
		}
		me->move(room);
		message("vision", me->name()+"从丛林之中钻了出来。\n", environment(me), me);
		return 1;
	}
	return 0;
}

