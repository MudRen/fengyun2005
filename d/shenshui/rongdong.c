// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "溶洞");
        set("long", @LONG
你发现自己身在一个大溶洞内，中间是一个大水池，水池内水很清，却看不到
底，池子四周镶嵌着大大小小的珍珠和各种颜色的贝壳，映着水波发出柔和的光彩。
洞内是千姿百态各种颜色的钟乳石，石壁上嵌满了大大小小的珍珠，此景当真是只
应天上有。
LONG
        );
   set("exits", ([ 
      "north": __DIR__"rongdong1",
   ]));
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
}

void init()
{
   add_action("do_dive", "dive");
}

int do_dive()
{
   object me, room;
   me = this_player();

  message_vision("$N走到池边，深吸一口气，跳到了池子里。\n\n", me);
  room = find_object(__DIR__"gongnei");
  if(!objectp(room))  room = load_object(__DIR__"gongnei");
  me->move(room);
  message("vision", me->name()+"扑通一声从上面跳了下来。\n", environment(me), me);
  return 1;
}


