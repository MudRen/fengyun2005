inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "右边小洞");
        set("long", @LONG
这间小洞的空间却很大，好象也因此明亮一些。仔细看时，里面长满了大大
小小，高高低低的石笋，有一些显然是从上面吊下来的。石笋发出的幽幽的光使
这里显得格外阴森恐怖。
LONG
        );
	set("frozen",3);
        set("item_desc", ([
                "寒冰": "除非把寒冰化开（ｐｏｕｒ），根本没办法走出山腹中。\n",
        ]) );
        set("objects", ([
                __DIR__"npc/luxiaofeng" :1,
                        ]) );
	set("coor/x",40);
	set("coor/y",110);
	set("coor/z",10);
	set("lu_cave",1);
	setup();
}

void init()
{
	add_action("do_pour", "pour");
}
int do_pour(string arg)
{
	object me;
	object con;
	me = this_player();
	if(!arg) return 0;
	if(!objectp(con=present(arg, me)))
	return 0;
	if(!con->query("liquid"))
	return 0;
	if(!con->query("liquid/remaining"))
	return notify_fail( con->name() + "是空的。\n");
	con->add("liquid/remaining", -1);
	message_vision("$N拿起" + con->name() + "倒了一些" +
	con->query("liquid/name")  + "在寒冰上。\n",me);
	if(con->query("liquid/name") == "热水")
	{
	tell_object(me,"寒冰化开了一点！！\n");
	add("frozen",-1);
	}
	if( query("frozen") <= 0 )
	{
	tell_object(me,"寒冰终于化开了一个小洞．．．\n");
	if(!query("exits/south"))
		set("exits/south",__DIR__"outcave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"飘过来的水滴眨眼间冻成冰珠，渐渐地封住了洞口．．\n",
                this_object() );
                delete("exits/south");
		set("frozen",10+random(5));
}

