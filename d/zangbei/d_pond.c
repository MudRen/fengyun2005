#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小池塘");
        set("long", @LONG
从茂密的木叶间望出去，这儿是一幅令人动心，令人迷惑，令人简直无法置信
的景象。小池塘旁，此刻围着几重纱幔，隔断了那边的视线，一个美丽的长发少女，
正在池塘裸浴。还有叁四个垂髫少女，有的手里拿着浴巾，有的拿着纱衣，有的拿
着浴纱，站在池塘边娇笑着。她们互相泼着水，水花也闪着金光。
LONG
        );
        set("exits", ([ 
	  	
	  	"south": __DIR__"d_bush",
			]));
	set("objects", ([
		__DIR__"npc/princess":	1,
	]));
	set("item_desc",([
		
	]));
	set("resource/water",1);
        set("liquid", ([
        "container": "小池塘",
        "name":		"小池塘水",
     ]));
        	
    set("outdoors", "zangbei");
    set("coor/x",-70);
	set("coor/y",330);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

string *event2_msg=	({
	
	"少女上上下下朝你瞧了几眼，本已充满愤怒的眼眸，似乎变得稍微和缓了一些。",
	
	"少女瞪着你道：你胆子倒不小，居然没有逃。",
	
	"你苦笑道：在下虽非有意，已觉甚是惭愧，若要逃走，岂非更丢人了？",

	"少女眼波闪动，道：那麽，你是认罪来的？",

	"你道：正是。",

	"那少女目中有了笑意，缓缓道：你能勇於认错，倒还不愧是个有胆识的人。",
	
	"少女一瞪眼：谅你也不敢故意来偷看！",

});


void init(){
	add_action("do_answer","answer");
}

void event2(object me, int count)
{
	object room;
	
	if (environment(me)!=this_object() || me->is_fighting()) {
		return;
	}
	tell_object(me,CYN"\n"+event2_msg[count]+"\n"NOR);
	if(++count==sizeof(event2_msg))
	{
		tell_object(me,WHT"\n你暗自思量：如果早知道，还会上树看么？（answer yes/no）？\n"NOR);
		me->set_temp("zangbei/pond_talk",1);	
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

		


int do_answer(string arg){
	object me,room;
	me = this_player();
	room = find_object(__DIR__"d_tent");
	if (!room) room = load_object(__DIR__"d_tent");
	
	if (!me->query_temp("zangbei/pond_talk")) return 0;
	if (!arg || (arg!= "yes" && arg!="no")){
		return notify_fail("answer yes or no\n");
	}
	
	if (arg == "no") {
		tell_object(me,YEL"\n你正色道：在下万万不敢！\n\n"NOR);
		me->set("zangbei/龟兹_偷窥失败",time());
		tell_object(me,CYN"少女微微冷笑，一挥手，你只觉得一股大力袭来，腾云驾雾地飞了出来。。\n\n"NOR);
	}
	else {
		tell_object(me,YEL"
你沉吟了羊晌，道：“在下若早已知道这里有像姑娘这样的佳人出浴，又知道
这里有一面没有用纱幔隔起……在下纵然双腿俱断，说不定爬也要爬来的。”\n"NOR);

	tell_object(me,CYN"\n
少女凝视着你，良久良久，面上忽又露出春花般的笑容，道：“想不到也有敢
说真话的人呢，也许我不但恕你的罪，还要将你视为上宾，但这却要着你除了
胆子大之外，是不是还有别的本事了。”

她以纤美的手揽起了头发，转身道：“你方才既未逃走，现在可敢到帐中来见
我么？”

少女微微冷笑，一挥手，你只觉得一股大力袭来，腾云驾雾地飞了出来。。\n\n"NOR);

		me->set("zangbei/龟兹_偷窥成功",1);
	}
	message("vision",HIG"只听树叶刷拉拉一阵乱抖，一个人影飞了出来。\n\n"NOR,room);
	me->move(__DIR__"d_tent");
	me->delete_temp("zangbei/pond_talk");
	me->stop_busy();
	return 1;
}

