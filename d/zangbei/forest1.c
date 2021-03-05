inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "密林");
        set("long", @LONG
再往东南走，是一座高大茂密的森林，被秋天的有所等待的寂静笼罩着，满目
尽是金叶和枯草。野兽从早便吼叫着，叫得人心慌，又热情得令人无法忍受；仿佛
在森林的金黄色的萧瑟中，有一个永世长存的庞然巨物在大声呼吸。密林深处，有
一个黑暗的洞穴，弥漫着野兽的腥味。 
LONG
        );
        set("exits", ([ 
		"north": __DIR__"woods1",
		"west" : __DIR__"woods2",
		"east": __DIR__"cave",
		"southeast": __DIR__"forest2",
	]));
        set("objects", ([
	]) );
	set("item_desc",([
		"洞穴":	 "林子的东面有一个黑黑的洞穴，看不清里面是什么。\n",
		"cave":	 "林子的东面有一个黑黑的洞穴，看不清里面是什么。\n",
		"grass": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
		"枯草": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
		"金叶": "地上的枯叶足有三寸厚，也不知已经积了多少年了。\n",
	
	]) );
	set("outdoors", "zangbei");
    set("coor/x",-1600);
    set("coor/y",680);
    set("coor/z",0);
	set("map","zbwest");
    create_door("east","rock","巨石","west",DOOR_CLOSED);
	setup();
}


void init() {
	add_action("do_listen","listen");
}


int do_listen() {
	object me;
	me=this_player();
	tell_object(me,"啊啊啊啊。。。呜呜呜呜。。。。\n");
	tell_object(me,"几只不知名的动物忽然从你身后穿过，钻到东南面的密林里不见了。\n");
	return 1;
}