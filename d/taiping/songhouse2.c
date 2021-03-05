#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "神幔后");
        set("long", @LONG
拉开神幔，祭坛中，供奉着的，赫然是一个“发子鬼母”。漆黑的木身在灯光
下闪着乌光，九个形状各异，面目狰狞的鬼子，环抱着獠牙裂目的鬼母，有的在哭，
有的在笑，有的仿佛要择人而噬，有两个竟左右吸吮着鬼母的两个乳房。雕刻的手
工栩栩如生，活灵活现。
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"songhouse",
	]));
        set("objects", ([
        	__DIR__"npc/songson": 1,
        	__DIR__"npc/ghost1": 1,
        ]));
        
        set("item_desc", ([
	
	 ]));
	set("guizi",5);
	set("coor/x",-60);
	set("coor/y",-65);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init(){
	add_action("do_kneel","kneel");
	add_action("do_kneel","ketou");
}




int do_kneel(){
	object song,guizi;
	if (this_player()->query_busy() || this_player()->is_fighting())
		return notify_fail("你现在正忙。\n");
	message_vision("$N跪倒在发子鬼母像前，恭恭敬敬地磕了三个响头。\n",this_player());
	this_player()->start_busy(1);
	if (song=present("song saiyu",this_object()))
		song->ccommand("pat "+this_player()->get_id());
	if (query("guizi") && !present("guizi",this_object())) {
		tell_object(this_player(),BLU"一阵阴风吹过，耳边似乎有些笑声，你不禁浑身起了鸡皮疙瘩。\n"NOR);
		guizi=new(__DIR__"npc/ghost2");
		guizi->move(this_object());
		add("guizi",-1);
	}
	return 1;
}


void reset(){
	::reset();
	set("guizi",5);
}