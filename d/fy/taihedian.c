// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIY"紫金殿"NOR);
    set("long", @LONG
沿着丹埠踏阶而上，便是九重天子的金銮大殿了，又称太和殿。殿内共有七十二
根楠木柱。六根蟠龙金漆柱巍然耸立，正前方正是楠木金漆雕龙宝座。大殿宽广可容
千人，而金銮殿顶高达数丈，乃是琉璃玉瓦铺就，犹如黄金一般辉煌灿烂。
LONG
    );
    set("exits", ([ 
	"out" : __DIR__"jinshuihe",	
      ]));
    set("item_desc", ([
	"金銮殿顶" : "金銮殿顶高达数丈，乃是琉璃玉瓦铺就，十分光滑，不知是否可以跃(jump)上去！\n",  
      ]));

    set("indoors", "fengyun");
    set("coor/x",0);
    set("coor/y",270);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

void init(){
    add_action("do_jump", "jump");
}

int do_jump(string arg){
    object me, room;
    int i, j;
    string *rooms = ({"zijin_w", "zijin_e", "zijin_n", "zijin_s"});
    me = this_player();
    if(!arg || (arg != "up" && arg != "金銮殿顶")){
	return notify_fail("你要往哪里跳？\n");
    }
    j=random(4);
    message_vision("$N纵身一跃，身形轻盈的登上了金銮殿顶。\n", me);
    room = find_object(__DIR__+rooms[j]);
    if(!objectp(room)){
	room = load_object(__DIR__+rooms[j]);
	me->move(room);
    }
    return 1;
}
