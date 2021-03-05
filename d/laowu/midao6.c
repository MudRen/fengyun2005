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
      "south" : __DIR__"midao5",
   ]));
	set("coor/x",90);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_look", "look");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if (!arg || (arg != "铜灯" && arg != "light" && arg != "lamp"))
      return 0;
   if(me->query_temp("marks/foundlight"))
      tell_object(me, "铜灯内似乎还注满了油。\n");
   return 1;
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if (!arg) {
      if(random(100) < llvl) {
         tell_object(me, "你在墙壁上摸到了一个象铜灯的东西。\n");
         me->set_temp("marks/foundlight", 1);
         return 1;
      }
      message_vision("$N在黑暗中搜索了一阵。\n", me);
      tell_object(me, "你没有任何发现。\n");
      return 1;
   }
   return 0;
}

void light_notify(object obj, int i)
{
   object *inv, me, room;
   int j;
	
   me = this_player();
   if(me->query_temp("marks/foundlight")){
      switch (i) { 
	      case 0:
	         message_vision("$N用" + obj->name() + "点燃了墙壁上的灯。\n\n" , me);
	         room = find_object(__DIR__"lmidao1");
	         if(!objectp(room)) room=load_object(__DIR__"lmidao1");
	         inv = all_inventory(this_object());
	         for(j=0; j<sizeof(inv); j++) {
	            inv[j]->move(room,1);
	         }
	      break;
	      case 1:
	         message_vision(obj->name() + "发出的光照亮了秘道。\n\n" , me);
	        room = find_object(__DIR__"lmidao1");
	         if(!objectp(room)) room=load_object(__DIR__"lmidao1");
	         inv = all_inventory(this_object());
	         for(j=0; j<sizeof(inv); j++) {
	            inv[j]->move(room,1);
	         }
	      break;
	      }
   }
   return;
}
