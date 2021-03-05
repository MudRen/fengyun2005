inherit ROOM;
void create()
{
        set("short", "海湾");
        set("long", @LONG
黑色的岸礁向海面延伸数十丈，尽头呈半月形，如情人般轻轻拥抱，形成一个天
然的海湾。即使在大风大浪的日子里，这儿仍然似世外桃源般平静。正值汛季，大部
分渔船都出海了，引人注目的是湾里停着一艘大船，船尾一面黑旗在风中猎猎作响，
船头站着数个彪悍的汉子，手里的钢刀闪闪发光。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"village",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	    "boat" : "用上好的红杉木造的三桅快船，船舱里传来弦乐之声，船头有一块跳板。\n",
	    "ship" : "用上好的红杉木造的三桅快船，船舱里传来弦乐之声，船头有一块跳板。\n",
	    "船" : "用上好的红杉木造的三桅快船，船舱里传来弦乐之声，船头有一块跳板。\n",
	    "大船" : "用上好的红杉木造的三桅快船，船舱里传来弦乐之声，船头有一块跳板。\n",
	    "跳板" : "木板很结实，顺着它可以走到(walkto)船头(bow)。\n"
	 ]));
	set("coor/x",1020);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void init()
{
    add_action("do_walk", "walkto");
}

int do_walk( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || (arg != "bow" && arg != "船头"))
	  	return notify_fail("你要往哪儿走？\n");
	 if (this_player()->is_busy())
	 	return notify_fail("你现在正忙。\n");
	 room = find_object(__DIR__"boatbow");
         if(!objectp(room))
                 room = load_object(__DIR__"boatbow");
	 message_vision("$N沿着跳板走向船头，木板很结实，像是走在平路上。\n",me);
	 me->move(room); 
	 return 1;
}
