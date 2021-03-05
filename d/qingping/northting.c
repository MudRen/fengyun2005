inherit ROOM;
void create()
{
        set("short", "偏厅");
        set("long", @LONG
厅中整洁异常，墙上一幅画，画的是一位少年剑客和一位女子并辔而行，看姿
态似乎是对夫妻，画中神态自若，显然作画之人手笔不凡，你不由仔细端详起来。
一张红木书桌上放着一把琴，尾部焦黑，乃是上好的梧桐木制成，看来这里的主人
文武皆通，才艺俱佳。
LONG
        );
   		set("exits", ([ /* sizeof() == 4 */
      		"south" : __DIR__"ting",
   		]));

	   set("objects", ([
	      __DIR__"npc/mo": 1,
	   ]) );
 
   	set("item_desc", ([
      "picture": "你的目光不由的被画旁的一首词吸引了过去：\n
      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳絮，随春且看归何处。

      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送春春不语，黄昏却下潇潇雨。 


．．．
好词啊，好词！！


\n",

      "画": "你的目光不由的被画旁的一首词吸引了过去： \n
      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳絮，随春且看归何处。

      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送春春不语，黄昏却下潇潇雨。 


．．．
好词啊，好词！！

\n",

		"琴":	"一把梧桐木做成的琴，不知道你会弹么？\n",
		"qin":	"一把梧桐木做成的琴，不知道你会弹么？\n",	
   ]) );

	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_play", "play");
}


int do_play(string arg)
{
   object me;
  
   me = this_player();
   
   if (!arg || (arg != "qin" && arg != "琴")) return 0;
   if(me->is_fighting()) 
   		return notify_fail("你正在跟人拼命耶．．\n");
   if(me->is_busy()) 
   		return notify_fail("你正在忙。\n");
   me->start_busy(2);
   
   message_vision("悦耳的琴声从$N灵巧的手下流出。\n",me);
   tell_object(me,"一阵风吹过，墙上的画飘了起来，后面竟然还有一首词。\n\n");
  		tell_object(me, "		浩浩愁，茫茫劫，\n");
		tell_object(me, "		短歌终，明月缺。\n");
		tell_object(me, "		郁郁佳城，中有碧血。\n\n");
		tell_object(me, "		碧亦有时尽，血亦有时灭，\n");
		tell_object(me, "		一缕香魂无断绝！\n");
		tell_object(me, "		是耶非耶，化为蝴蝶。\n\n"); 
  		tell_object(me,"
．．．

风止，画儿又恢复了原状，似乎什么也没有发生过。\n");
  return 1;
}
