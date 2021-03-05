inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "关帝庙");
        set("long", @LONG
再往前面走不多远，就是间破落的关帝庙。庙里的香火并不旺，连关帝老爷神
像上的金漆都已剥落。大门也快塌了，庙里的神案倒还是完整的，若有个人睡上去，
保证不会垮下来。院子里堆了十几具棺材，院子并不大，所以棺材只能叠起来放。
棺材本来是全新的，漆得很亮，现在却已被碰坏了很多地方，有些甚至已经被烧焦。
LONG
        );
        set("exits", ([ 
	"southeast": __DIR__"road6",
	"west":		__DIR__"cemetery0",
	]));
        set("objects", ([
        	__DIR__"obj/coffin":	1,
        	"/obj/specials/ding/ding_bc": 1,
	]) );
	set("coor/x",-60);
        set("coor/y",10);
        set("coor/z",0);
	set("map","zbwest");
	set("tuozi_out",0);

	setup();
	
}


void reset(){
	
	object coffin,tuozi;
	
	::reset();
	
	set("tuozi_out",0);
	
	tuozi=present("ding qiu",this_object());
	
	if (!tuozi) 
	if (coffin=present("coffin",this_object())){
		coffin->set("burnt",0);
		coffin->set("closed",1);
//		coffin->set("long", "棺材本来是全新的，漆得很亮，现在却已被碰坏了很多地方。\n");
	}
}


		