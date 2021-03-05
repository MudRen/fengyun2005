inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "梅林小路");
        set("long", @LONG
一条踏出的小路盘旋曲折。路边的梅树下一朵朵无名小花份外妖窈。花有兰有
紫，有些还有浇灌过的痕迹。繁密的梅枝间透下点点日光，枝条摇摆，忽明忽暗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : AREA_MANGLIN"edge3",
  "east" : __DIR__"road2",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
            "无名小花": "
                        路边的野花好美呀．．．采（ｐｉｃｋ）一朵吧！\n",
            "小花": "
                        路边的野花好美呀．．．采（ｐｉｃｋ）一朵吧！\n",
			"flower" : "路边的野花好美呀．．．采（ｐｉｃｋ）一朵吧！\n"
        ]) );
    set("flower_amount", 4);
	set("coor/x",-70);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
add_action("do_pick","pick");
}

int do_pick()
{
	object flower;
	if(query("flower_amount")) {
		message_vision("$N弯下腰，采了一朵路边的野花。\n",this_player());
		flower = new(__DIR__"obj/flower");
		flower->move(this_player());
		add("flower_amount", -1);
	} else {
		return notify_fail("野花已经没有了。\n");
	}
return 1;
}

void reset(){
	set("flower_amount", 4);
}