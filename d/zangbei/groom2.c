inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "卧室");
        set("long", @LONG
卧室里的陈设及其简单，西墙有张床，在关外长大的人都习惯睡硬炕，老伯也
不例外，所以这是张很硬的木板床，也是张很普通的木板床。正中是把宽大而舒服
的藤椅，老伯喜欢坐在这把藤椅上接见他的朋友的属下，听他们的意见和消息，然
后再下决定。有很多改变了无数人命运的大事都是老伯坐在这藤椅上决定的。
LONG
        );
        set("exits", ([ 
		"south":	__DIR__"groom1",
	]));
        set("objects", ([
        	__DIR__"npc/laobo":	1,
	]) );
		set("item_desc",	([
			"藤椅":		"一把宽大而舒服的藤椅。\n",
		]));
		
        set("coor/x",-1260);
        set("coor/y",990);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
	create_door("south","door","纱门","north",DOOR_CLOSED);
}

void init(){
	add_action("do_look","look");
}


int do_look(string arg){
	if (!arg || (arg!="bed" && arg!="木板床" && arg!="床"))
		return 0;
	if (!query("escaped")){
		tell_object(this_player(),"
在关外长大的人都习惯睡硬炕老伯也不例外，所以这是张很硬的木板床，也是
张很普通的木板床。\n");
		return 1;
	}
	tell_object(this_player(),"
床下竟然有秘道，地道下黑漆漆的伸手不见五指。
一种很奇怪的声音，是流水声，老伯寝室的地下竞有条秘密的河流。
两旁是坚固的石壁，左边的石壁上，有个巨大的铁环，挂着很粗的铁链，石壁
上长着青苔铁环也已生锈，显见老伯在建造这屋子之前，己先掘好了这河流，
这下面本来一定有条船，船上一定有人．
不但有人，且终年都有人，时时刻刻都有人。
这人随时随刻都在守候着，等待着老伯的消息。。\n");
	return 1;
}


void reset(){
	set("escaped",0);
	::reset();
}



