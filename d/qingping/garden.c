inherit ROOM;
#include <command.h>
#include <ansi.h>

void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是清平山庄的后花园，花园不大，可是此时正当百花盛开之际，园中一片
烂漫，蝴蝶翩翩。靠近院墙处长了一棵[37m老槐树[32m，即使是在炎热的夏季，树阴下也凉
风爽爽。春天的时候，老槐树更是开满了一串串洁白的花朵，微风拂过那醉人的花
香就飘满了整个清平山庄。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"studyroom",
  "south" : __DIR__"xting",
  "east" : __DIR__"pond",
  "west" : __DIR__"neiyuan",
   ]));

   set("item_desc", ([
      "tree" : "浓密的老槐树紧靠着院墙，一只粗粗的枝干已伸到了墙外。\n",
      "老槐树" : "浓密的老槐树紧靠着院墙，一只粗粗的枝干已伸到了墙外。\n",
   ]) );

   set("objects", ([
      __DIR__"npc/yan" : 1,
   ]) );
   	set("outdoors","qingping");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "老槐树" && arg != "tree") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 50)
      message_vision("$N试了试老槐树，看来没希望爬上去。\n", me);
   else{
      message_vision("$N身手矫健地爬上了老槐树。\n", me);
      room = find_object(__DIR__"midtree");
      if(!objectp(room)) room=load_object(__DIR__"midtree");
      me->move(room);
   }
   return 1;
}