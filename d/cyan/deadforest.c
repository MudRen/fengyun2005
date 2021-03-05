// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "死树林"NOR);
    set("long", @LONG
这里的空气里浸透着浓浓的腥潮之气，周遭的树木不知何故已经死得干净：它
们犹然挺立在淤泥之上，并未干枯，却是一层一层的腐烂，有一种浓黑色的汁液自
树心里渗出，地面上铺满的不再是乾香的枝叶，而代以厚厚的败坏的沼泥。
LONG
        );
	set("objects", ([
		__DIR__"obj/swamp":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : __DIR__"forest2",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",30);
	setup();
}


void init()
{
	add_action("do_west","go");
}


int do_west(string arg)
{
	object me = this_player();
		object room;

	int i;
	if (arg != "east")
		return 0;
	if (!REWARD_D->check_m_success(me,"明霞之阴"))
		return 0;

	room=find_object(__DIR__"deadforest2");
	if(!objectp(room)) 
        room = load_object(__DIR__"deadforest2"); 
	me->move(room);
	return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


