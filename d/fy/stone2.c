// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
    set("short", "石巷尽头");
    set("long", @LONG
石巷不深，很快到了尽头，一堵高墙挡住去路。墙上有道窄门，墙角有一[33m狗洞[32m，
一条脏稀稀的小河沟从狗洞中流出，时而不时的，一条条浸满血水的绷带从狗洞中
流出，散发出腐臭的气味。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"stone1",
	"northeast" : __DIR__"sroom",
	"east" : __DIR__"ansheng",
      ]));
	set("item_desc", ([
	"狗洞":"一个废弃已久的狗洞，早已经失去了钻(enter)狗的用途变作阴沟。\n",
	]) );
    set("objects", ([
		//__DIR__"npc/newsman" : 1,
      ]));
    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init()
{
	add_action("do_north", "enter");
}



int do_north(string arg)
{
    object room, me;
		me = this_player();
		if (!room= find_object("/d/fycycle/road6"))
			room=load_object("/d/fycycle/road6");
		tell_object(me,"\n你想起韩信他年且受胯下之辱，相较下你这堂堂大侠钻个把儿狗洞又算什么。\n");
		me->ccommand("emote 嘿嘿一笑，一低身便沿著阴沟向狗洞钻去。\n");
		me->move(room);
		me->ccommand("emote 从城墙上一个小洞中钻出，小心翼翼地跋过护城河行了过来。");
		if (!REWARD_D->check_m_success(me,"狗洞大侠"))
				REWARD_D->riddle_done(me,"狗洞大侠",1,1);
		me->set_temp("body_print", "这人身上沾满了黑泥灰水，还滴滴答答地正向下落，\n看起来好恶心啊。");

		return 1;
}


/*

// this code work only if npc cannot be arrested.
int invalid_leave(object me)
{
    object ob;
    if(  me->query_temp("answer_questions") <= 3 ) 
    {
	me->delete_temp("score");
	me->delete_temp("answer_questions");
	me->delete_temp("num_question");
	me->delete_temp("in_ask");
	if(ob=present("news man", this_object()))
	{
	    ob->set("in_test",0);
	}
    }
    return 0;
}
*/