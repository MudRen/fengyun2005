// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
int ceiling();
void create()
{
        set("short", "小仓房");
        set("long", @LONG
在昏暗的烛光下，你隐约可以看到这里堆满了东西，一麻袋一麻袋的无谷杂粮
占据了小半个房间，一袋袋一直堆积到房顶，一些残破的桌椅板凳散放在另一个角
落，旁边的几个大竹筐里堆放着一些新鲜蔬菜。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"cavehotel",
	]));
    set("objects", ([
        __DIR__"obj/bigbasket": 1,
    ]) );
	set("item_desc", ([
		"房顶" : "隐约有一丝微光从上面透下来。\n",
		"ceiling" : "隐约有一丝微光从上面透下来。\n",
		"麻袋" : "麻袋包整齐的叠放着，你似乎可以爬上去。（ｃｌｉｍｂ）\n",
		"madai" : "麻袋包整齐的叠放着，你似乎可以爬上去。（ｃｌｉｍｂ）\n",
		"bag" : "麻袋包整齐的叠放着，你似乎可以爬上去。（ｃｌｉｍｂ）\n",
	]));
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_climb", "climb");
}

int do_climb(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "madai" && arg != "bag" && arg != "麻袋")){
		return notify_fail("你要爬什么？\n");
	}
	message_vision("$N顺着麻袋爬了上去，顺手推开木板翻了出去。\n", me);
	room = find_object(AREA_FY"ansheng");
	if(!objectp(room)){
		room = load_object(AREA_FY"ansheng");
	}
	me->move(room);
	message_vision("$N从红木棺中爬了出来。\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
 	REWARD_D->riddle_done(me,"勇探地牢",10,1);
	if (QUESTS_D->verify_quest(me,"勇探地牢"))
		QUESTS_D->special_reward(me,"勇探地牢");  
	return 1;
}
