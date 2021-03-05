// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火沼深处");
	set("long", @LONG
这里密布的荆棘挂满倒刺，挡在通往沼泽深处的方向。低矮的小树丛挡住视线，
使人辨不清方向。地下布满腐烂的枯叶，松松软软的。偶尔有一两个气泡从地上的
积水下涌出，带出令人作呕的刺鼻气味。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze6",
]));

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
		"woods" : "这里小树丛(woods)密布，但你似乎可以砍开(chop)它们。\n",
		"小树丛" : "这里小树丛(woods)密布，但你似乎可以砍开(chop)它们。\n"
        ]) );
        set("objects", ([
                __DIR__"npc/monster2" : 1,
                __DIR__"npc/monster3" : 1,
       ]) );
       set("outdoors", "zhaoze");
       set("no_fly",1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	object ob,room;
	if( interactive( ob = this_player())) {
    		if(ob->query_skill("force",1) < 150) {
			if (!room=find_object(__DIR__"edge.c"))
				room = load_object(__DIR__"edge.c");
			ob->move(room);
			message_vision(HIR"$N被丛林里的灼热气焰冲了回来。\n\n"NOR, ob);
		}else if (userp(ob) || userp(ob->query("possessed")))
				ob->apply_condition("zhaoze",10);			
	}
	add_action("do_chop","chop");
}

int blowing(object ob, object room)
{
	int i;
	int damage;
        if(  ob && environment(ob) == room )
	{
		tell_object( ob , HIR "\n\n地下的泥土突然裂开，一团炽热的地火象喷泉般射出！！\n\n"NOR);
		ob->receive_wound("kee", random(100)+10);
		ob->set_temp("last_damage_from","在火沼泽烈火焚身而死。\n");
		COMBAT_D->report_status(ob,1);
		if( environment(ob) == room )
			call_out("blowing",random(10)+1, ob);	
	}
	else
		return 1;
}

void reset()
{
	::reset();
        remove_call_out("blowing");
        delete("exits/south");
        delete("exits/west");

}

int valid_leave(object me, string dir)
{
        if ((query("exits/west") && dir == "west") 
        	|| (query("exits/south") && dir=="south"))
        if (present("fire giant", this_object()))
        	return notify_fail("火巨灵挡住了你的去路。\n");
        remove_call_out("blowing");
	return 1;
}

int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要砍开什么？\n");
                return 1;
        }
        if( arg == "bush" || arg == "荆棘" || arg == "woods" || arg == "小树丛")
        {
        	me = this_player();
        	obj = me->query_temp("weapon");
        	if( !obj )
        	{
        		write("你空着手，怎么砍？\n");
        		return 1;
        	}
	        if( obj->query("jungle"))
	        {
			if( arg == "bush" || arg == "荆棘")
			{
		        if( !query("exits/south") ) {
			        set("exits/south", __DIR__"zhaoze3");
			        message_vision(sprintf("$N用手中的%s砍出一条向南的路．\n",obj->name()),
			                me);
								}
			        else
			        message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),
			                me);
			}
			else
		        {
			        if( !query("exits/west") ) {
			        set("exits/west", __DIR__"center");
			        message_vision(sprintf("$N用手中的%s砍出一条向西的路．\n",obj->name()),
			                me);
							        }
			        else
			        message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),
			                me);
			}
			me->start_busy(1);
		}
	        else
	        	message_vision(sprintf("$N用手中的%s向丛生的荆棘一顿乱砍．\n",obj->name()),
	                me);
        }
        else
         	write("你要砍开什么？\n");
        return 1;
}

