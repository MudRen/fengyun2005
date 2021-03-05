// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
又转了几个弯，秘道越来越窄了，有几处你甚至要侧着身子才可以通过，走到
这里已经没有别的出路了，地上堆满从墙壁上剥落下来的石子，可见这里已经有很
久没有人走动了。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"lmidao2",
]));
	set("coor/x",100);
	set("coor/y",50);
	set("coor/z",0);
        setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me, obj, pill;
   int llvl;

   me = this_player();
    llvl = (int)me->query_kar();
   if(!me->query_temp("marks/posion") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N在墙壁石堆中一阵搜寻。\n", me);
            tell_object(me, "你在乱石堆中找到一个小白瓷瓶。\n"); 
            message("vision", me->name()+"从乱石堆中捡起一样东西放入怀中。\n", environment(me), me);
            obj = new(__DIR__"obj/yuping");
//          pill = new(__DIR__"obj/medicine");
//                pill ->move(obj);
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         } 
         message_vision("$N在墙壁石堆中一阵搜寻。\n", me);
         tell_object(me, "你什么都没找到。\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N在墙壁石堆中一阵搜寻。\n", me);
            tell_object(me, "你在乱石堆中找到一个小白瓷瓶。\n"); 
            message("vision", me->name()+"从乱石堆中捡起一样东西放入怀中。\n", environment(me), me);
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         }
         message_vision("$N在墙壁石堆中搜寻了好一阵。\n", me);
         tell_object(me, "你什么都没有发现。\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N在墙壁石堆中一阵搜寻。\n", me);
   tell_object(me, "你什么都没发现。\n");
   return 1;
}
void reset()
{
::reset();
delete("got");
}
