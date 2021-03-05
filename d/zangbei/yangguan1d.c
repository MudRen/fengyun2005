inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大沙漠");
        set("long", @LONG
虽然是同一个太阳，但这太阳到了沙漠上，就忽然变得又狠又毒，像是要将整
个沙漠都晒得燃烧起来似的。没有风，一丝风都没有，也没有丝毫声音，在烈日下，
沙漠上所有的生命，都已进入了一种晕死状态，热气从沙漠里蒸发出来，热得令人
恨不得把身上衣裳都脱光。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"yangguan1d",
		"west" :__DIR__"yangguan1d",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",-80);
        set("coor/y",300);
        set("coor/z",0);
        set("map","zbeast");
	setup();
}


void 	init(){
	add_action("do_smell","smell");
	add_action("do_dig","digdown");
	add_action("do_go", "go");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(), "你在沙地上找了半天，结果什么也没有发现，看来此法不通。\n");
	return 1;
}

int do_smell(string arg){
	if (this_player()->is_busy())
		return notify_fail("你现在正忙。\n");
	message_vision(YEL"$N伏下来，用鼻子嗅着地上的沙，像狐狸般爬行着。\n"NOR,this_player());
	if (!random(5)){
		tell_object(this_player(),WHT"忽然，你似乎闻到了沙底下的一丝湿气，也许可以挖（digdown）下去看看。\n"NOR);
		this_player()->set_temp("zangbei/desert_smell",1);
	}
	this_player()->start_busy(1);
	return 1;
}


int do_dig(string arg){
	object weapon, me;
	me = this_player();
	if (!weapon=me->query_temp("weapon"))
		return notify_fail("你手里没工具，用什么挖？\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
	message_vision(YEL"$N拿起手中的"+weapon->name()+YEL"，发狂般地用力挖着沙子。\n"NOR,me);
	if (!random(2) && me->query_temp("zangbei/desert_smell")) {
		tell_object(me,HIG"顺着湿气的所在挖下去，你发现数尺下的沙地有一条水脉，确切地说，
只是一条湿迹，弯弯曲曲地通向东北方向。\n"NOR);
		me->set_temp("zangbei/desert_oasis",1);
		return 1;
	}
	tell_object(me,"忙活了半天，沙子下面仍然是沙子，这茫茫沙海，到处乱挖可没什么用。\n");
	me->start_busy(1);
	return 1;
}


int do_go(string arg) {
	object room;
	object me = this_player();
	if (arg == "west")
	if(me->query_temp("zangbei/龟兹_龟兹送宝") || !random(30)) {
		room = find_object(__DIR__"yangguan1");
   		if(!objectp(room)) room=load_object(__DIR__"yangguan1");
      		message("vision", me->name()+"向西离开。\n", environment(me),me );
   		me->move(room);
   		message("vision", me->name()+"走了过来。\n", environment(me),me );
   		return 1;
   	}	
	if (arg == "east") {
		tell_object(me,YEL"你走来走去，似乎又回到了原地，再找不到水源，迟早会饥渴而死的。\n"NOR);
		return 0;
	}
	if (arg!="northeast")	return 0;
	if (!this_player()->query_temp("zangbei/desert_oasis")) {
		tell_object(this_player(),"你狂跑了几圈，发现自己又回到了原地。\n");
		return 1;
	}
	message("vision",this_player()->name()+"向前走去，消失在沙丘后不见了。\n",this_object(),this_player());
	tell_object(this_player(),"你沿着湿迹的走向向东北方向寻去。\n");
	tell_object(this_player(),HIG"走了数里，你的眼前竟然出现了一片绿色！\n"NOR);
	room = find_object(__DIR__"d_oasis");
	if (!room) room = load_object(__DIR__"d_oasis");
	this_player()->move(room);
	return 1;
}
