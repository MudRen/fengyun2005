// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "左偏院");
        set("long", @LONG
院中种满了[37m梅树[32m幼苗。每棵都在茁壮成长，显然有人精心照顾。梅苗之间还有
人工开垦的小河沟，半尺深的渠水绕树而淌，灌溉着每一棵幼苗。土壤黑而酥松，
显然是饱含营养的肥土。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "梅树": "你似乎可以砍（ｃｈｏｐ）几根下来。\n",
                "tree": "你似乎可以砍（ｃｈｏｐ）几根下来。\n",

        ]) );
		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}
void init()
{
		add_action("do_chop","chop");
}


do_chop()	{
	object vege;
	if((int) query("pulled") <= 20)
	{
		vege = new(__DIR__"obj/tree");
		if (!vege->move(this_player()))
			{
				write("太多太重了，没法拿了！！！\n");
				destruct(vege);
				return 1;
			}
		write("你砍了一棵梅树幼苗放在怀里。\n");
		add("pulled",1);
		return 1;
	}
	else
        write("都被人砍光了！！\n");
        return 1;
}



void reset()
{
	:: reset();
	delete("pulled");
}
