//XXDER
inherit ROOM;
void create()
{
   set("short", "池塘");
   set("long", @LONG
后花园有一小小的池塘，一座玲珑精致的小拱桥横跨在池塘上。塘水碧绿，上
面有几朵盛开的睡莲，粉红，洁白，鹅黄，衬托着碧绿的叶子，漂浮在小池塘上，
煞是惹人喜爱。一棵垂柳半横在塘边，柳丝随风飘舞。几块太湖石散落地布在池
塘边。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "eastup" : __DIR__"bridge",
      "west" : __DIR__"garden",
      "northeast" : __DIR__"northpond",
      "southeast" : __DIR__"southpond",
   ]));
   
   set("item_desc", ([
      "太湖石": "几块玲珑的太湖石，散落地放在池塘边，石头的一部分被埋在了土下（ｐｕｓｈ）。\n",
      "stone": "几块玲珑的太湖石，散落地放在池塘边，石头的一部分被埋在了土下（ｐｕｓｈ）。\n",
      "垂柳": "垂柳在不远处的池塘边，整个柳树横在池塘上。\n",
      "tree": "垂柳在不远处的池塘边，整个柳树横在池塘上。\n",
      "睡莲": "半开的睡莲象睡梦之中的美人，漂浮在碧绿的池塘上。\n",
      "flower": "半开的睡莲象睡梦之中的美人，漂浮在碧绿的池塘上。\n",
   ]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
   set("outdoors", "qingping");
}

void init()
{
   add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, qiuyin, obj ;
  
   	me = this_player();
   	obj = this_object();
   if (!arg || arg != "stone" && arg != "石头") 
      return notify_fail("你要推什么 ? \n");
      
   if(obj->query("marks/moved")>5) 
   		return notify_fail("石头似乎被人推过，已经松动了。\n");
   
   if (me->query("force") < 400)
      return notify_fail("你的真气不够了。 \n");

   message_vision("$N用力地推动太湖石，石边的土松动了，露出了两条胖胖的蚯蚓。\n$N累得满头大汗，又饿又渴。\n", me);
   me->add("force",-400);
   me->set("food",0);
   me->set("water",0);

   qiuyin = new(__DIR__"obj/qiuyin");
   qiuyin->move(obj);
   qiuyin = new(__DIR__"obj/qiuyin");
   qiuyin->move(obj);
   obj->add("marks/moved", 1); 
   return 1;

}

void reset(){
	::reset();
	delete("marks/moved");
}

