inherit ROOM;

void create()
{
        set("short", "银杉树上");
        set("long", @LONG
你现在正攀附在一株银杉树上，树叶很密，在这里阳光也透不过茂密的树冠。
从这里可以很清楚地望见树下的一切动静，而不被人发觉，似乎是个干偷鸡摸狗
勾当的好地方。树冠很大，一部分树枝甚至垂到了附近的院子里。
LONG
        );
        set("objects", ([
                __DIR__"npc/banditspy" : 1,
		]) );

		set("item_desc", ([
			"树冠":		"树冠很大，一部分树枝甚至垂到了附近的院子里。\n",
			"树枝":		"一部分树枝甚至垂到了附近的院子里。\n",
			"院子":		"银杉树的东南角有个院子，从树枝上可以跳进去。\n",
			"branch":	"一部分树枝甚至垂到了附近的院子里。\n",
		]));
				
        set("exits", ([ /* sizeof() == 2 */
  			"down" : __DIR__"groad3",
		]));

        set("coor/x",80);
	set("coor/y",90);
	set("coor/z",10);
	set("map","eren");
	setup();

}

void init()
{
	add_action("do_jump", "jump");
}


int do_jump(string arg)
{
   	object me, room;
   	me = this_player();
   	
   	if(!arg || (arg != "down" && arg!="院子" && arg!="树枝" && arg!="branch")) {
   		tell_object(me,"你要往哪儿跳？\n");
   		return 1;
   	}
   	
   	if (me->is_busy()|| me->is_fighting()) {
   		tell_object(me,"你现在正忙。\n");
   		return 1;
   	}
   		
   	message_vision("$N从树上拔身而起，顺着树枝呼拉一下滑到了院子里。\n\n", me);
   	room = find_object(__DIR__"backyard"); 
   	if(!objectp(room)) room=load_object(__DIR__"backyard");
    me->move(room);
    message("vision",me->name()+"轻飘飘地落到了院内。\n", environment(me), me); 
   	return 1;
}