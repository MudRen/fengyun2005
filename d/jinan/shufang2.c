#include <ansi.h>
inherit ROOM;
string script();
void create()
{
        set("short", "书库");
        set("long", @LONG
这里是大学士殷正廉保存他平生收集各种文献的所在。更有他年轻时撰写的数
本武功心得。房间收拾得干净整洁，满屋的书架上堆满了书籍，当中有张不大的藤
制方桌，上面放着一叠手稿。 
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"shufang",
	]));
	set("item_desc", ([
		"script" : (: script :),
		"手稿" : (: script :),
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

string script(){
	object me;
	me = this_player();
	tell_object(me, "一叠看起来有些泛黄的手稿， 首页上书："RED"岳武穆生平大事记\n"NOR); 
	tell_object(me, "（study）\n");
	add_action("do_study", "study");
	return "";
}

int do_study(string arg){
	object me;
	me = this_player();
	if(!arg) {
		return notify_fail("你要学什么？\n");
	}
	if (me->is_busy())	{
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
	if(arg == "script" || arg == "手稿") {
		message_vision("$N好奇地翻开了方桌上的手稿。。。。\n", me); 
		me->start_busy(3);
		call_out("dream", 3, me);
	} else {
		return 0;
	}
	return 1;
}

int dream(object me){
	if(environment(me) != this_object() || !interactive(me)) {
		return 0;
	}
	if (REWARD_D->riddle_check( me, "纵横天下")>1)	{
//	if(me->query("marks/大名湖畔纵横天下") && me->query("marks/操练岳家中平枪法")) {
		if(!random(2)){
			tell_object(me, "你突然觉得眼皮发沉，忍不住闭上了眼睛。\n");
			me->set_temp("disable_inputs", 1);
			me->add_temp("block_msg/all", 1);
			me->set_temp("is_unconious", 1);
			me->set("disable_type", HIG "<梦乡中>"NOR);
			call_out("wake", 3, me);
		} else {
			message_vision("$N点了点头，自言自语道：原来如此。。。。\n", me); 
		}
	} else {
		message_vision("$N点了点头，自言自语道：原来如此。。。。\n", me); 
	}	
	return 1;
}

void wake(object me){
	object room;
	if(environment(me) != this_object() || !interactive(me)) {
		return 0;
	}	
	me->delete_temp("disable_inputs", 1);
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	me->delete_temp("is_unconious", 1);
	me->delete("disable_type");
	tell_object(me, HIY"\n你突然被远处的战马嘶鸣声惊醒了, 发现自己已经不在知府书库！\n\n"NOR);
	REWARD_D->riddle_set( me, "纵横天下",3);
//	me->set("marks/dreaming_yue", 1);
    room = find_object("/d/jinan/shanpo");
	if(!objectp(room)){
        room = load_object("/d/jinan/shanpo");
	}
	me->move(room);
}
