#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山间小道");
        set("long", @LONG
这一段路地势平缓，四周山峦拔地而起，小路在山间谷地盘环而行，小路两侧
草木茂密，你不时听到树上黄雀悦耳的叫声，一条小溪流伴在小路的一侧缓缓向东
流去，溪水清澈见底。北方是一片茂密的树林。
LONG
        );
    	set("exits", ([ 
  		"westup" : __DIR__"canglong",
	    "eastup" : __DIR__"xiaodao1",
		"north" : __DIR__"milin",
	]));
    	set("objects", ([
		__DIR__"npc/woodcutter2" : 1,
    		__DIR__"npc/yellowbird" : 1,
    	]));
    	set("outdoors", "huashan");

	set("coor/x",-8);
	set("coor/y",-50);
	set("coor/z",27);
	setup();
}

void init(){
	if (REWARD_D->riddle_check( this_player(),"黄雀传奇") == 1
		 && NATURE_D->is_day_time() 
		 && NATURE_D->get_weather() == "晴") {
		tell_object(this_player(),YEL"空中忽然有清脆的鸟鸣之声。。。。\n\n"NOR);
		call_out("bird_come", 2, this_player());
	}
}


void bird_come(object me){
	object obj;
	int i;
	
	if(!interactive(me) || environment(me) != this_object()){
		return;
	}
	obj = new("/obj/medicine/pill_zhuguo");
	i = NATURE_D->get_season();
	if(objectp(obj) && (i == 3 || i == 4)){
		message_vision("\n一只小黄雀飞落在$N肩膀，嘴里叼着一棵朱红色的果子。\n", me);
		message_vision("朱红色的果子落下，刚好落入$N怀中。小黄雀展翅高飞冲入云霄。\n", me);
		if (!obj->move(me))
			obj->move(environment(me));
	} else {
		obj = new("obj/medicine/pill_yihua");
		message_vision("\n一只小黄雀围绕着$N头顶飞了几圈，最后落到$N肩膀。\n", me);
		message_vision("一朵小花从小黄雀口中落下，掉入$N怀中。小黄雀叫了两声展翅飞去。\n", me);
		if (!obj->move(me))
			obj->move(environment(me));
	}
	REWARD_D->riddle_done( me, "黄雀传奇", 10, 1);
}
