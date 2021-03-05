// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
转了几个弯，入洞已深，面前伸手不见五指，周围不时传来小动物掠过的沙沙
声，令人生畏。你想回头却已不知来时的道路。在这里你也分不清东西南北，只好
揣测着方向，壮着胆子摸索着往前走。

LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"midao7",
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
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(!me->query_temp("marks/posion") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N在黑暗中一阵搜寻。\n", me);
            tell_object(me, "你在乱石堆中找到一个小瓶子。\n"); 
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         } 
         message_vision("$N在黑暗中一阵搜寻。\n", me);
         tell_object(me, "你什么都没找到。\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N在黑暗中一阵搜寻。\n", me);
            tell_object(me, "你在乱石堆中找到一个小瓶。\n"); 
            obj = new(__DIR__"obj/yuping");
            obj->move(me);
            me->set_temp("marks/posion", 1);
            return 1;
         }
         message_vision("$N在黑暗中搜寻了好一阵。\n", me);
         tell_object(me, "你什么都没有发现。\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N在黑暗中一阵搜寻。\n", me);
   tell_object(me, "你什么都没发现。\n");
   return 1;
}


void light_notify(object obj, int i)
{
   object *inv, me, room;
   int j;
	
   me = this_player();
   switch(i){
      case 1:
         message_vision(obj->name() + "发出的光照亮了秘道。\n\n" , me);
         room = find_object(__DIR__"lmidao3");
         if(!objectp(room)) room=load_object(__DIR__"lmidao3");
         inv = all_inventory(this_object());
         for(j=0; j<sizeof(inv); j++) {
            inv[j]->move(room,1);
         }
      break;
   }
   return;
}


void reset()
{
::reset();
delete("got");
}
