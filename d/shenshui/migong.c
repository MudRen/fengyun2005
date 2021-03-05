// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "艳洞");
        set("long", @LONG
刚才好似天堂，现在你却似身在地狱，四周是昏黄发红的光线，你不由觉得
好热，而且越来越热，似乎有火在煎熬着你，走了几步四周景色没有改变，耳边
不时传来少女低声的呻吟，和着周围火热的岩石，你不禁越来越烦燥。
LONG
        );
   set("exits", ([ 
      "north": __DIR__"migong1", 
   ]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",-20);
	setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query_kar();
   message_vision("$N伸手在火热的石壁上摸索着。\n",me);
   if (random(100) < llvl) { 
      tell_object(me, "你的手在石壁上摸到了一个突出物，你顺手往上一按。 \n");
      message_vision("只听一阵绞索的声音，你头上裂开了一个洞口。 \n", me);
      if( !query("exits/up") ) {
         set("exits/up", __DIR__"rongdong1");
         call_out("close_path", 1);
      }
   }
   else
      tell_object(me, "你什么都没找到。\n");
   return 1;   
}

void close_path()
{
   if( !query("exits/up") ) return;
   message("vision", "轰隆一声，头顶上的出口又被挡住了。\n", this_object() );
   delete("exits/up");
}

