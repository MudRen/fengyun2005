// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "药店内间");
        set("long", @LONG
一股浓烈的中草药的味道扑鼻而来。墙角一座小炉，炉上一个发黑的瓷锅里墨
绿色的液体正在卟卟地冒着热气，显然在煎着药材。另一面立着一个黑色的木柜，
上面插满了四寸见方的木匣。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yao",
]));
        set("objects", ([
        __DIR__"npc/medman": 1,
        __DIR__"npc/pettrainer2" : 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_soup","煮汤");
	add_action("do_soup","cook");
}

int do_soup()
{
	object ob1,ob2,ob3,ob4,ob5,ob6;
	object me;
	me = this_player();
	ob1 = present("pilosulae",me);
	ob2 = present("dioscoreae",me);
	ob3 = present("codonopsis",me);
	ob4 = present("astragalt",me);
	ob5 = present("lycii",me);
	ob6 = present("freshfish",me);
	if( ob1 && ob2 && ob3 && ob4 && ob5 && ob6 )
	{
		message_vision("$N将一条鱼和一些中药放入瓷锅中，炖了起来．\n",me);
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		destruct(ob4);
		destruct(ob5);
		destruct(ob6);
		call_out("give_soup",random(5)+1,me);
		return 1;
	}
	tell_object(me, "你的原料不全，没法熬当归补血鱼汤。\n");
	return 1;
}

int give_soup(object me)
{
	object soup;
	if(me) 
	if( environment(me) == this_object())
	{
		soup = new(__DIR__"obj/med");
		REWARD_D->riddle_done( me, "巧熬鱼汤", 10, 1);
		if(soup->move(me))
			message_vision("$N将炖好的当归补血鱼汤放在怀里．\n",me);
		QUESTS_D->special_reward(me,"巧熬鱼汤");
	}
	return 1;
}
