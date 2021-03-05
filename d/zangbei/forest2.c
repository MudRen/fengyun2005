inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "密林");
        set("long", @LONG
再往东南走，是一座高大茂密的森林，被秋天的有所等待的寂静笼罩着，满目
尽是金叶和枯草。野兽从早便吼叫着，叫得人心慌，又热情得令人无法忍受；仿佛
在森林的金黄色的萧瑟中，有一个永世长存的庞然巨物在大声呼吸。 
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("item_desc",([
		"grass": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
		"枯草": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
		"金叶": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",660);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init() {
	add_action("do_listen","listen");
	add_action("do_look","look");
	add_action("do_south","go");
}

int do_listen() {
	object me;
	me=this_player();
	tell_object(me,"啊啊啊啊。。。呜呜呜呜。。。。\n");
	tell_object(me,"几只不知名的动物忽然从你身后穿过，钻到南面的密林里不见了。\n");
	me->set_temp("marks/listen_milin",1);
	return 1;
}


int do_look(string arg) {
	object me;
	me=this_player();
	if (me->query_temp("marks/listen_milin"))
	if (arg=="south" || arg =="南面" || arg =="南" || arg =="南面的密林") {
		tell_object(me,"仔细沿着野兽消失的方向看去，你发现南面的树木比较稀疏，似乎有人经常走过。\n");
		me->set_temp("marks/enter_milin",1);
		return 1;
	}
	return 0;
}


int do_south (string arg)
{
   	object me, room;
   	me = this_player();
	
	if (arg == "south")
   	if(me->query_temp("marks/enter_milin")) {
   		tell_object(me, "你拨开乱枝，向南面的密林深处走去。\n\n");
   		message("vision", me->name(me)+"在密林里转了几转就失去了踪影。\n", environment(me),me );
   		room = find_object(__DIR__"forest3");
   		if(!objectp(room)) room=load_object(__DIR__"forest3");
      		me->move(room);
      		return 1;
   	}
   	return 0;
}