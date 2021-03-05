#include <ansi.h>

inherit ROOM;

string *user_channel;

void create()
{
        set("short", "小树丛");
        set("long", @LONG
青葱的树叶间，不时有银铃般的笑声传出来。这本是欢乐的笑声，但在这残酷
无情的大沙漠中，一个快被渴死的人耳朵里，这笑声却比什麽都要诡秘可怖。这难
道真是神话中的幻境，魔境？隐藏在这青葱树叶里，难道就是神话中那些专门诱惑
孤独的旅人去吞噬的吃人女妖？
LONG
        );
        set("exits", ([ 
	  	"south": __DIR__"d_oasis",
		]));
	set("objects", ([
		
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_listen","listen");
	add_action("do_look","look");
	add_action("do_jump","jump");	
}

int do_listen(){
	tell_object(this_player(),"不时有银铃般的笑声从树叶那头传出来，使人忍不住想去看上一看。\n");
	return 1;
}

string *event1_msg=	({
	
	"从茂密的木叶间望出去，你立刻瞧见一幅令人动心，令人迷惑，
令人简直无法置信的景象。",
	
	"小池塘旁，此刻围着几重纱幔，隔断了那边的视线。。。。",
	
	"一个美丽的长发少女，正在池塘裸浴。",
	
	"还有叁四个垂髫少女，有的手里拿着浴巾，有的拿着纱衣，有的拿着浴纱。",

	"少女们站在池塘边娇笑着，互相泼着水，水花也闪着金光。",
	
	"		突然",
	
	"那少女明媚的眼波，忽然向你这边一转，",

});


void event1(object me, int count)
{
	if (environment(me)!=this_object() || me->is_fighting()) {
		return;
	}
	
	tell_object(me,CYN"\n"+event1_msg[count]+"\n"NOR);
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,HIR"\n坏了，你被发现了！！！\n\n"NOR);
		tell_object(me,WHT"你是溜走（jump away）呢，还是跳下树走过去（jump down）？\n"NOR);
		me->stop_busy();
		me->set_temp("zanbei/龟兹_jump",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int do_look(string arg){
	object me;
	if (arg == "tree" || arg == "树" || arg == "树木" || arg== "树叶" || arg=="leaves" || arg == "leaf") {
		me = this_player();
		if (me->query("zangbei/龟兹_偷窥失败")+ 3600 > time()
			|| me->query("zangbei/龟兹_入帐失败")+ 3600 > time()) {
			tell_object(me,"你不是刚刚认过错出来？怎么又要做这等事了？\n");
			return 1;
		}
		message_vision("$N轻轻掠上树枝，向树丛那边望去。\n",me);
		me->start_busy(8);
		call_out("event1",1,me,0);
		return 1;
	}
	return 0;
}

int do_jump(string arg) {
	object me, room;
	me = this_player();

	if (!me->query_temp("zanbei/龟兹_jump"))
		return 0;
	
	if (!arg || (arg!= "away" && arg!="down")){
		return notify_fail("你想怎么跳？\n");
	}
	
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	
	if (arg == "away") {
		tell_object(me,YEL"你暗叫一声大事不妙，赶紧一溜烟地跳下树躲开了。\n"NOR);
		me->delete_temp("zanbei/龟兹_jump");
		return 1;
	}
	if (arg == "down") {
		tell_object(me,YEL"
你叹了口气，苦笑着跃下树来，这一辈子，简直没有比此刻更觉得尴尬的
时侯了。但你不能逃，只有硬着头皮走过去。\n"NOR);
		if (!room = find_object(__DIR__"d_pond")) room = load_object(__DIR__"d_pond");
		me->move(__DIR__"d_pond");
		me->start_busy(8);
		me->delete_temp("zanbei/龟兹_jump");
		room->event2(me,0);
	}
	return 1;
}
	
	
