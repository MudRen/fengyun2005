// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "溶洞");
        set("long", @LONG
才走出几步你就发现自己已经迷失了方向，似乎是在原地打转，石壁上镶嵌着
大大小小的珍珠，洞内千姿百态各种颜色的钟乳石在珠光的影射下发出鳞粼般的光
彩，象有无数只的眼睛在看着你，不知几千年几万年的水珠顺着乳石涓涓滴落。
LONG
        );
   set("exits", ([ 
      "north": __DIR__"rongdong1",
      "south": __DIR__"rongdong1",
      "east": __DIR__"rongdong1",
      "west": __DIR__"rongdong1",
   ]));

   set("item_desc", ([
      "stone": "在千百个钟乳石中，你注意到其中一个似乎被人摸得光不留手。\n",
      "钟乳石": "在千百个钟乳石中，你注意到其中一个似乎被人摸得光不留手。\n",
   ]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}

void init()
{
   add_action("do_look", "look");
   add_action("do_southeast", "go");
   add_action("do_touch", "touch");
}

int do_touch(string arg)
{
   object me, room;

   me = this_player();
   if (!arg || (arg != "stone" && arg != "钟乳石")) return 0;
   if (me->is_fighting()) return notify_fail("你够不到钟乳石。\n");
   message_vision("\n\n$N伸手向一个钟乳石上按去。\n", me);
   tell_object(me, "你只觉得脚下一空，身子向下坠去，惊慌中你发出一声大叫。\n\n");
   message("vision", "只听一声大叫，啊啊.......啊..." + me->name()+"已失去了踪影。\n",environment(me), me);
   room = find_object(__DIR__"migong");
   if(!objectp(room)) room = load_object(__DIR__"migong");
   me->move(room);
   message("vision", "只听哎呀一声，"+me->name()+"从上面落了下来。\n",environment(me), me);
   return 1;
}

int do_look(string arg)
{
   object me;
   int clvl;

   me = this_player();
   if (!arg || (arg != "pearl" && arg != "珍珠")) return 0;
   clvl = (int)me->query_cps();
   if (random(80) < clvl) {
      tell_object(me, "你看到石壁上有几粒珍珠似乎组成一个小箭头，箭尖对着东南方。\n"); 
      me->set_temp("marks/southeast", 1);
   }
   else {
      tell_object(me, "珍珠在石壁上组成各样的字句和图案，你看了几眼不觉面红耳赤心神荡漾。\n");
      message("vision", me->name()+"向石壁上望了几眼，刷的一下脸红了起来。\n", environment(me),me);
      me->receive_damage("sen", random(100));
      me->set_temp("last_damage_from","在神水溶洞里糊里糊涂地死了。\n");
   }
   return 1;
}

int do_southeast(string arg)
{
   	object me, room;

   	me = this_player();
   	if (arg == "southeast")
   	if(me->query_temp("marks/southeast")) {
      		tell_object(me, "你向东南方走去。\n\n");
      		message("vision", me->name()+"向东南方走去，在钟乳石后转了几转就失去了踪影。\n", environment(me),me );
      		room = find_object(__DIR__"rongdong");
      		if(!objectp(room)) room=load_object(__DIR__"rongdong");
      		me->move(room);
      		return 1;
   	}
   	return 0;
}

