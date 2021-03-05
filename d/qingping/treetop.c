// XXDER@FY
inherit ROOM;
void create()
{
        set("short", "槐树上");
        set("long", @LONG
树很高，你爬到了树顶后发现院墙只到树的一半多一点，在这里你终于看到了
天空。四周都是槐树茂密的枝叶，看不到树下面的情况，但在这里可以清楚地看到
前院的练武场，还有大厅的一切。
LONG
        );

   set("item_desc", ([
   		"树冠":	"近了才发现，这树冠里原来是个鸟窝（nest）\n",
   ]) );

   set("objects", ([
      	__DIR__"obj/nest": 1,
      	AREA_WUDANG"npc/bird.c":1,
   ]) );

   set("outdoors", "qingping");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",20);
   setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;

   me = this_player();
   if (!arg || arg!= "down") {
   	tell_object(me,"你只能往下跳（jump down）\n");
   	return 1;
   }
   message_vision("$N从树上拔身而起，轻飘飘地落到了院墙上。\n\n", me);
   room = find_object(__DIR__"wall"); 
   if(!objectp(room)) room=load_object(__DIR__"wall");
      me->move(room);
      message("vision",me->name()+"轻飘飘地落到了院墙上。\n", environment(me), me); 
   return 1;
}

void reset()
{
   object *inv;
   object item1, item2, nest;
   ::reset();

   nest = present("nest", this_object());
   
   if (!present("bird egg", nest)) {
      item1 = new(__DIR__"obj/egg");
      item1->move(nest);
	}
	if (!present("key", nest)) {
      item2 = new(__DIR__"obj/key");
      item2->move(nest);
   }
}
