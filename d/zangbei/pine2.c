inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大松树顶");
        set("long", @LONG
终于爬到大松树的树顶了，离地有七、八丈，盘曲的丫枝，扇形的簇叶，遮住
了半个天空。可以闻到阵阵松果的清香，可是周围昏沉沉的，什么也看不清，只听
到叽叽喳喳的鸟叫声。
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"pine1",
	]));

        set("item_desc", ([
    	]));
        set("in_tree",1);
        set("nest",1);
        set("coor/x",-1900);
		set("coor/y",720);
		set("coor/z",25);
		set("map","zbeast");
		setup();
        
}

void init() {
	add_action("do_jump","jump");
	add_action("do_look","look");
	add_action("do_smell","smell");
	add_action("do_listen","listen");
}

int do_smell(){
	tell_object(this_player(),"哇，好一股松叶的清香。\n");
	return 1;
}

int do_listen(){
	tell_object(this_player(),"叽叽喳喳的鸟叫声好不热闹。\n");
	return 1;
}

int do_look(string arg) {
	
	object me = this_player();
	
	if (arg == "丫枝" || arg == "簇叶" || arg == "树叶" || arg == "树冠") {
		if (me->query_temp("marks/zangbei/树顶")) {
			tell_object(me,"树叶密密的，遮住了整个天空，不过，喇嘛指的那个方向，
果真有几个鸟窝，叽叽喳喳的好不热闹，你可以试着跳过去看看。\n");
			me->set_temp("marks/zangbei/鸟窝",1);
		} else
			tell_object(me,"树叶密密的，遮住了整个天空。\n");
		return 1;
	}
	return 0;
}		



int do_jump(string arg){
	object me, room,item;
	
	me=this_player();
	
	if (!arg || (arg != "nest" && arg!="鸟窝") ) {
		tell_object(me,"你要向哪儿跳？\n");
		return 1;
	}
		
	if (!me->query_temp("marks/zangbei/鸟窝")) {
		tell_object(me,"光听到鸟叫，鸟窝在哪儿？\n");
		return 1;
	}
			
	message_vision("\n$N提一口真气，朝着鸟窝的方向纵身一跃。\n\n",me);
	
	room = find_object(__DIR__"temple5");
	if (!objectp(room)) room= load_object(__DIR__"temple5");
	
	if (me->query_skill("move",1)<100) {
		message_vision("$N一脚踩空，双手向空中胡乱抓了几下，一个跟斗栽了下去。\n\n",me);
		message("vision","只听扑通一声，树上掉下一个人来。\n",room);
		me->move(room);
		me->unconcious();
		return 1;
	}
		
	tell_object(me,YEL"你单足在树枝上一点一跃，卡啪一声，树枝断了，
你百忙之中往鸟窝里伸手一摸，\n"NOR);
	
	if (query("nest")) {
		tell_object(me,YEL"抓到一个硬硬的东西，\n\n"NOR);
		item = new(__DIR__"obj/t_item5");
        set("nest",0);
         	if (!item->move(me))
         		destruct(item);
         	else	{
         		tell_object(me,YEL"你也不管是什么，赶紧揣到怀里。\n\n"NOR);
         	}         		
	} else 
		tell_object(me,YEL"结果抓了一手鸟粪。。。。\n");
	
	message_vision("$N脚下再无着力之处，直通通地往树下落去。\n\n",me);
	message("vision","只听扑通一声，树上跳下一个人来。\n",room);
	me->move(room);
	return 1;
}

void reset(){
	set("nest",1);
	::reset();
}