// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "金水玉带河");
    set("long", @LONG
一条宛如玉带般的金水河，清风徐来，鳞鳞水光仿佛玉带临风，栩栩如生，河
上五座白玉大理石石桥通向对岸。正中所谓“御路桥”，乃当今天子之路；其左右
称“王公桥”，是宗室亲王们走的；最外两桥方为“品级桥”，供一般官员行走。
LONG
    );
    set("exits", ([ 
	"south" : __DIR__"hall",
	"enter" : __DIR__"taihedian",
      ]));
    set("objects", ([
	__DIR__"npc/jindian_guard" : 2,
      ]));

    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",260);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

int valid_leave(object me, string dir){
    object silk;

    if (dir=="enter") {

	return notify_fail("紫金殿整修，暂不开放。\n");

	if( sizeof(me->query_all_condition()) != 0 )
	    return notify_fail("你身带异状，紫金殿不是你的坟场。\n");

	if(me->query("eff_sen")<me->query("max_sen")*9/10
	  ||me->query("eff_kee")<me->query("max_kee")*9/10
	  ||me->query("eff_gin")<me->query("max_gin")*9/10)
	    return notify_fail("你体弱多病，紫金殿不是你的坟场。\n");

	/*      if(dir == "enter" && present("palace guard")) {
		silk = present("silk", obj);
		if(obj->is_naked()){
				return notify_fail("金殿武士喝道：“站住，赤身裸体成何体统。”\n");
			} 
		if(obj->query("bellicosity") > 100 || obj->query_temp("weapon") || obj->query("vendetta/authority") || !objectp(silk)) {
				return notify_fail("金殿武士神色一紧，怒喝道：“止步！”\n");
			}
		if(objectp(silk) && silk->query("equipped") != "worn")
				return notify_fail("金殿武士神色缓和地道：“请着装好！”\n");
			if(objectp(silk) && silk->query("equipped") == "worn"){
				message_vision("金殿武士一抱拳，躬身道：这位"+RANK_D->query_respect(obj) +"，总管吩咐，凡配有七彩丝缎带的请往里走！\n\n",
						obj); 
				return 1;
			}
		}	*/
    }
    return 1;
}
