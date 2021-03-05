// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
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
      "north": __DIR__"migong3",
      "south":  __DIR__"migong1",
   ]));
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-20);
	setup();
}

void init()
{
   add_action("do_faint", "faint");
   add_action("do_jump", "jump");
   tell_object(this_player(),RED"\n你左摇右晃，但是还是坚持着没有晕倒。\n\n"NOR);
}

int do_faint()
{
   object me;

   me = this_player();
   if (me->is_fighting() ) return 0;
   if (me->is_busy() ) return 0;
   message_vision("$N脚下一个踉跄昏倒在地上。\n", me);
	me->unconcious();
   call_out("wake", 5 ,me);
   return 1;
}

void wake(object me)
{
   if (me && environment(me) == this_object()) {
	me->revive();
      tell_object(me, "\n\n\n忽然头顶滴下几滴水滴 ....... 虽然只有几滴，却已把你从无比的
烦燥与昏热中解救出来 ，仔细一看，原来上边有一洞口。一个完全赤裸的
女孩正拿着水壶往下滴水。嘴边因微笑而荡起的梨涡使你心中不由一震。你
暗中已经记住了洞口的方位。\n\n");
      me->set_temp("marks/up", 1);
   }
}


int do_jump(string arg)
{
   object me, room;
   int ml;

   me = this_player();
   ml = (int)me->query_skill("move");
   if (!me->query_temp("marks/up")) return 0;
      if(!arg || (arg != "up" && arg != "上")) return 0;
      if (ml >= 30) {
         tell_object(me, "你纵身轻盈地跳到了上面一层，眼前人影一晃，失去了女孩的踪影。\n");
         message("vision", "昏热中你只觉得眼前一花，"+me->name()+"已失去了踪影。\n", environment(me),me);
         room = find_object(__DIR__"huoyan");
         if(!objectp(room)) room = load_object(__DIR__"huoyan");
         me->move(room);
//       me->set("marks/enter_ss/风筝",1);  
         message("vision", me->name()+"身法美妙地跳了上来。\n", environment(me), me);
         return 1;
      }
      else {
         tell_object(me, "你纵身往上一跳，却没办法跳到第二层上，只好慢慢爬了上去。\n");
         message("vision", "昏热中你一没留神，"+me->name()+"已失去了踪影。\n", environment(me), me);
         room = find_object(__DIR__"huoyan");
         if(!objectp(room)) room = load_object(__DIR__"huoyan");
         me->move(room);
         message("vision", me->name()+"慢慢地爬了上来。\n", environment(me), me);
         return 1;
      }
}

