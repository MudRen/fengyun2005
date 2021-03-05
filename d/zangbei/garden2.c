inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菊花园中");
        set("long", @LONG
菊花园很大，菊花园旁是梅花园还有牡丹，蔷薇．芍药，茶花，甚至还有竹园。
所有的花园密密相接谁也不知道究竟占了多少地，只知道一个人就走得很快也难在
一天内绕着这片地走一圈。花园里很静，没有人，没有声音。老伯的花园一向都是
这样子的，但你只要一走进去，每个角落里都可能有人忽然出现，每个人都可能要
你的命。
LONG
        );
        set("exits", ([ 
		"southeast" :   	__DIR__"garden1",
		"north" : 	__DIR__"groom4",
		"southwest":	__DIR__"garden3",
	]));
	
	set("item_desc", ([
        	"菊花":	"正当秋季，园子里的菊花有半人多高，绚烂多彩。\n",
        	"flower": "正当秋季，院子里的菊花有半人多高，绚烂多彩。\n",
    	]));
    	
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1320);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_pull","pull");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"园子里的菊花长得郁郁葱葱，恐怕搜一天都不会有结果。\n");
	return 1;
}


int do_pull(string arg) {
	object me=this_player();
//	object xiaohe;
	
	if (arg== "flower" || arg == "菊花") {
		tell_object(me,YEL"你蹲下去伸手拔起一株菊花。菊花被你一拔，就连根而起。\n\n"NOR);
		return 1;
	}
	return notify_fail("你想拔/拉什么？\n");
}