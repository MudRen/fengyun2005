// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "危桥一线");
    set("long", @LONG
刚刚踏上此桥，你的心就提到了嗓子眼。这座天成的石桥两侧没有护栏，
仅宽一肩，又立于风头之上，下临深渊，周围层层雾裹，难辨远近，若大风起
时一不小心掉了下去，只怕立时就要尸骨无存，摔成又酥又软，香甜可口的一
滩。
LONG
        );
	set("objects", ([

	]));
	set("item_desc", ([
		"west":"重重的大雾阻挡住你的视线。\n",
		"east":"重重的大雾阻挡住你的视线。\n"

	]) );
	set("exits",([
  		"west" : "hotel5",
  		"east" : "rock",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}

void init()
{
	object me = this_player();
	// not 
	::init();
	if (random(me->query_skill("move")) < 2)	// well.. 
	{
		message_vision(CYN"\n骤然一阵狂风袭卷而过，将$N吹得摇摇晃晃．．．\n"NOR,me);
		if (random(me->query_skill("move")) < 2)	// again? sorry then, you are really bad bad luck.
		{
			message_vision(HIY"\n只听得一声尖叫，$N身形一个不稳，自石桥上直直坠了下去！\n\n"NOR,me);
			me->die();	
		}
	}
}

int valid_leave(object obj, string dir){
	if (userp(obj) && random(5)) {
		obj->move(this_object());
		message_vision(CYN"$N伏在石桥上，小心翼翼地向前匍匐而去。\n"NOR,obj);
		obj->perform_busy(1);
		return notify_fail("");
		}
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


