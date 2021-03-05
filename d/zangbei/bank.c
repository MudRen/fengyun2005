inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "河滩");
        set("long", @LONG
边城南面是一条湍急的小河，两岸的泥土为深褐色，当地人称之为赤土河，上
游是著名的贡嘎银河，也就是传说中的神河，所以赤土河也沾上了神气，每到节日
就有许多虔诚的信徒来转山。不过平时就只有几个妇人在浆洗衣裳。河的南岸有许
多堆的整整齐齐的石头，一条小路通向山林深处。
LONG
        );
        set("exits", ([ 
		"northwest":  AREA_BIANCHENG"sstreet4",
	]));
	set("item_desc", ([
		"river":	"水流湍急，但是不深，你可以试着涉过去(wade)。\n",
		"赤土河":	"水流湍急，但是不深，你可以试着涉过去(wade)。\n",
	]) );
        set("objects", ([
        
        	__DIR__"npc/woman":	1,
        	__DIR__"npc/girl":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2020);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init() {
	add_action("do_wade","wade");
}


int do_wade(string arg) {
	
	object me;
	
	me=this_player();
	if (!arg || arg == "小河" || arg== "river") {
		if (me->query_temp("zangbei/wade_1"))
			return notify_fail("你已经在河水中央了。\n");
		message_vision("$N脱下靴子走入河水中，艰难地向对岸涉去。\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/wade_1",1);
		return 1;
	}
	tell_object(me,"你要做什么？\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"zhihuo");
	if (!objectp(room)) room=load_object(__DIR__"zhihuo");
	tell_object(me,HIG"你终于走到了赤土河的对岸。\n"NOR);
	message("vision",HIG""+me->name()+"水淋淋地从河里走了上来。\n"NOR,room);
	me->move(room);
	me->delete_temp("zangbei/wade_1");
	return 1;
}