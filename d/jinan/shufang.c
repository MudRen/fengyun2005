inherit ROOM;
void create()
{
        set("short", "知府书房");
        set("long", @LONG
这书室庭户虚敞，正中挂一幅名人山水。供一个古铜香炉，炉里香烟飘渺。左
边设一张湘妃竹榻，右边架上堆满若干图书。沿窗一只几上，摆列文房四宝。窗外
庭中种植许多花木，铺设得十分清雅。东面似乎还有一个房间，房间的门紧闭着。
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"govern",
		"east" : __DIR__"shufang2",
	]));
    set("objects", ([
        __DIR__"npc/governor" : 1,
    ]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object obj, string dir){
	object gov;
	if(dir == "east"){
		
			if (REWARD_D->riddle_check( obj, "纵横天下")){
				message_vision("$N推门向东离去。\n", obj);
				return 1;
			}else {
				if(gov = present("master yin", this_object())){
					message_vision("$N道：“那是本官书库，闲杂人等莫入。”\n", gov);
					return notify_fail("");
				} else {
					message_vision("$N推门向东离去。\n", obj);
					return 1;
				} 
			}
	}	
	return :: valid_leave(obj, dir);
}
	
/*		
		if(NATURE_D->is_day_time()){
				if(obj->query("marks/操练岳家中平枪法")){
				message_vision("$N推门向东离去。\n", obj);
				return 1;
			} else {
				return notify_fail("房间的门打不开。\n");
			}
		} 
		if(obj->query("marks/大名湖畔纵横天下") || obj->query("marks/操练岳家中平枪法")){
			message_vision("$N推门向东离去。\n", obj);
			return 1;
		} else {
			if(gov = present("master yin", this_object())){
				message_vision("$N道：“那是本官书库，闲杂人等莫入。”\n", gov);
				return notify_fail("");
			} else {
				message_vision("$N推门向东离去。\n", obj);
				return 1;
			}
		}
	}
	return 1;
}*/