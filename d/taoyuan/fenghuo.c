#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "山峰背后");
        set("long", @LONG
峰回石转，你眼前突然一亮，山势在此蓦然开朗，身后是半壁看来不甚牢靠的
[36m青石[32m，眼前一条小路不知何时钻出，悄无声息，蜿蜒脚下；远处白云缭绕，似有人
家；而你耳边又似乎有铮铮琴声，待要驻足细听，那琴声却又无影无踪。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"valley2",
	]) );

	set("item_desc", ([
		"stone" : "青石上挂满藤蔓，却不甚坚牢，似乎轻轻一推就可以开了。\n",
		"rock" : "青石上挂满藤蔓，却不甚坚牢，似乎轻轻一推就可以开了。\n",
		"青石" : "青石上挂满藤蔓，却不甚坚牢，似乎轻轻一推就可以开了。\n",
		"north" : "小山洞中黑漆漆的，你什么也看不清楚。\n",
	]) );
	set("no_magic", 1);	
	set("no_fly", 1);	

   	set("outdoors","taoyuan");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init ()
{
	add_action("do_push", "push");

   add_action("do_listen", "listen");
   add_action("do_southeast", "go");
}

int do_southeast(string arg)
{
   object me, room;
   me = this_player();

   if (arg == "southeast")
   if(me->query_temp("marks/listen")) {
/*      if (ANNIE_D->check_buff(me,"fugitive")>0) {
   			tell_object(me,"你重案在身，还是不要去打搅那个世外桃源之地了吧。\n");
      		return 1;
      }*/
      tell_object(me, "你沿着小路，走向那白云缭绕之处。\n\n");
      message("vision", me->name(me)+"沿着蜿蜒的山路转了几转就失去了踪影。\n", environment(me),me );
      room = find_object(__DIR__"taovillage");
      if(!objectp(room)) room=load_object(__DIR__"taovillage");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_listen(string arg)
{
   object me, room;
   me = this_player();

   tell_object(me,"琴声若有若无，你仔细再听了听，好象隐隐约约从东南边传来。\n");
   message("vision",me->name(me)+"突然住足，似乎在侧耳倾听着什么。\n", environment(me),me);
   tell_object(me, HIG"\n音乐平和舒缓，一洗你久处江湖的杀伐之气，你忽然感受到生命的珍贵。\n\n"NOR);
   tell_object(me, "你再仔细看了看那个方向，似乎有一条小路从那里蜿蜒伸向白云缭绕之处。\n", me);
   me->set_temp("marks/listen", 1);	

   return 1;
}
void close_path()
{
	if( query("exits/north") ) {
    message("vision","藤蔓牵着青石慢慢地合上了。\n",this_object() );
    delete("exits/north");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="stone" || arg =="青石" || arg == "rock") {
    	message_vision("$N往青石上轻轻地一推，青石慢慢地转动起来，展现出一处山洞。\n", me);
		set("exits/north", __DIR__"treasure");
		call_out("close_path", 3);
	}
	else {
		write("你要推什么呢？\n");
	}
	return 1;	
 }
