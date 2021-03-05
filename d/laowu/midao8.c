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
  "west" : __DIR__"midao7",
]));
	set("coor/x",110);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_push", "push");
}


int do_push(string arg)
{
   object me;
   int flvl;

   me = this_player();
   flvl = (int)me->query_str();
   if (!arg || (arg != "stone" && arg != "石头")) return 0;
   if (me->query_temp("marks/foundstone")) {
      if(flvl >= 20) {
         tell_object(me, "你运力于双臂，使出浑身的力气向大石推去！\n");
         message_vision("黑暗中只见有一丝光透过，光束越来越大，慢慢露出个洞口！ \n",me);
         set("exits/out", __DIR__"dongkou");
         call_out("close_path", 1);
         return 1;
      } 
      else {
         tell_object(me, "你运力于双臂，使出浑身的力气向大石推去，石头只是稍稍晃动了几下。\n");
         return 1;
      }
   }
   return 0;
}

void close_path()
{
   if(!query("exits/out") ) return;
   message("vision", "只听咯吱吱，石头滑回来挡上了洞口，黑暗又笼罩了一切。\n", this_object() );
   delete("exits/out");

}

int do_search(string arg)
{
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(random(200) < llvl) {
      		message_vision("$N在黑暗中四处乱摸。\n", me);
      		tell_object(me, "你摸到了一块大石，摇了摇似乎有些松动。\n");
      		me->set_temp("marks/foundstone", 1);
      return 1;
   }
   message_vision("$N在黑暗中四处乱摸。\n", me);
   tell_object(me, "你没有任何发现。 \n");
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
         room = find_object(__DIR__"lmidao4");
         if(!objectp(room)) room=load_object(__DIR__"lmidao4");
         inv = all_inventory(this_object());
         for(j=0; j<sizeof(inv); j++) {
            inv[j]->move(room,1);
         }
      break;
   }
   return;
}
