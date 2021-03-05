//XXDER
inherit ROOM;
void create()
{
        set("short", "池塘");
        set("long", @LONG
一棵[33m垂柳[32m半横在池塘上，柳条几乎碰到了水面。偌大的一棵树却只在岸边留下
很小一块阴凉，大部分的阴影都投在了池塘上，树旁散落地放着几块形状奇特的太
湖石。一条小路从树后绕到了池塘的另一面。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "southeast" : __DIR__"backdoor",
   "southwest" : __DIR__"pond",
   ]));

   set("item_desc", ([
      "tree" : "柳树几乎横卧在水面上，由于离水太近，树干上长满了青苔。\n",
      "垂柳" : "柳树几乎横卧在水面上，由于离水太近，树干上长满了青苔。\n",
   ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
   set("outdoors", "qingping");
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int llvl;
   
   me = this_player();
   if(!arg || arg != "垂柳" && arg != "tree") 
      return notify_fail("你要爬什么 ? \n");
   llvl = (int)me->query("kar");
   if(random(100)<llvl) {
      	message_vision("\n\n$N沿着树干慢慢爬了上去，坐到了横在湖面的柳树干上。\n", me);
      	room = find_object(__DIR__"liutree"); 
      	if(!objectp(room)) room=load_object(__DIR__"liutree");
      	me->move(room);
      	message("vision", me->name()+"沿着树干慢慢爬了上来，坐到了柳树干上。\n", environment(me),me);
   }
   else{
      message_vision("\n\n$N沿着树干小心翼翼地往前爬，．．．


突然脚下一滑，扑通一声掉进了水里。\n\n", me);
      room = find_object(__DIR__"pond1"); 
      if(!objectp(room)) room=load_object(__DIR__"pond1");
      me->move(room);
      message("vision",me->name()+"扑通一声从上面掉了下来。\n",environment(me), me);
   }
   return 1;
}
