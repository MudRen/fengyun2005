// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "清心寡欲楼");
    set("long", @LONG
说来是楼，其实空荡如也，只是比较高大，所以远看好似楼阁，前额一块牌匾，
上书－清心寡欲四字，楼中除了一蒲团以外一无所有，在这里唯一能做的似乎就是
在蒲团之上闭目养神。
LONG
        );
   	set("exits", ([ 
      "south" : __DIR__"huayuan",
      "north" : __DIR__"shenshui",
   ]));

/*   set("item_desc", ([
      "putuan" : "一个素白缎子做成的蒲团，用来打坐用的。\n",
      "蒲团" : "一个素白缎子做成的蒲团，用来打坐用的。\n",
   ]) );	*/
   
	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}

/*
void init()
{
   add_action("do_sit", "sit");
}

int do_sit(string arg)
{
   object me, obj;

   me = this_player();
   obj = this_object();
   if(obj->query_temp("marks/taken")) return notify_fail("蒲团上有人。\n");
   if((int) me->query("sen") <=50) return notify_fail("你的神不够。\n");
   message_vision("$N走到蒲团之上坐了下来闭上了眼睛。\n", me);
   me->start_busy(2);
   obj->set_temp("marks/taken", 1);
      me->set_temp("disable_inputs",1);
      me->add_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<打坐中>"NOR);
   call_out("ling", 5, me);
   return 1;   
}

void ling(object me)
{
   int llvl;
   if(!me || me->is_ghost()) return;
   	
   llvl = (int)me->query_kar();
   me->receive_damage("sen",20+random(30));
   if( (int)me->query("bellicosity") > 0)
   me->add("bellicosity", - (random((int)me->query_kar()) + 7 ) );
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   me->delete_temp("is_unconcious");
   tell_object(me, "慢慢地你到了忘我的境界，只觉得心灵中一片澄清。\n");
   this_object()->set_temp("marks/taken", 0);
   return;
}
*/