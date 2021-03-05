inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西寨墙");
        set("long", @LONG
寨墙是照箭楼的格式修筑的，一、二两层都有箭眼，三层只有一半墙壁，从上
半段也可露出头来向外射箭。若是有人来攻，寨里的人站在墙上向下射箭。居高临
下，十分得手。寨墙外面是茂密的森林，寨墙里面可以看到一个大院，院子的四周
有几间瓦房，竖着半人高的烟囱。
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"w_wall2",
		
	]));
        set("item_desc", ([
        	"chimney": "这烟囱显然已经废弃多时了，看上去勉强可以钻进一个人（squeeze through）。\n",
        	"烟囱":	 "这烟囱显然已经废弃多时了，看上去勉强可以钻进一个人（squeeze through）。\n",
        ]));
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",580);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}

void init() {
	add_action("do_squeeze","squeeze");
}


int do_squeeze(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="through" || arg == "烟囱" || arg== "chimney" || arg =="through chimney") {
		if (me->query_temp("zangbei/chimney_1"))
			return notify_fail("你已经在烟囱里了。\n");
		message_vision("$N一猫腰挤进烟囱，小心翼翼地向下爬去。\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/chimney_1",1);
		return 1;
	}
	tell_object(me,"你要爬什么？\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"v_barn");
	if (!objectp(room)) room=load_object(__DIR__"v_barn");
	tell_object(me,"你轻巧地下到屋子里。\n");
	message("vision",me->name()+"从屋顶上掉了下来。\n",room);
	me->move(room);
	me->delete_temp("zangbei/chimney_1");
	return 1;
}