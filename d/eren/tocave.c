// Silencer@FY workgroup  恶人窟
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "洞腰");
        set("long", @LONG
你慌乱地用手狂抓，悉悉簌簌的泥土石块伴着你往下掉。忽然你碰到了几根象
绳索一样的东西，是长在洞壁上的千年古藤，这对你来说，无疑是溺水者抓到了救
命的稻草，你终于稳住了下坠的势头。头顶上有些日光，也许抓着古藤还有希望爬
上地面，脚下是黑漆漆的深洞，跳下去再也没有回头的路了，你的选择是什么呢？
LONG
        );
	set("exits", ([ 
//	    	"northdown" : __DIR__"yongdao1",  
	]));
    	set("objects", ([

    	]) );
  	set("indoors", "eren2");
	set("coor/x",0);
    	set("coor/y",0);
	set("coor/z",0);
	set("valid_startroom",1);
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_dive","jump");
	add_action("do_dive","jumpdown");
}

int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
	tell_object(me,"你静静地想了想，也许，日日夜夜的奋斗，就是为了现在这一刻，就是为了这一跃。\n");
	message_vision(YEL"$N长长吸了口气，毅然松开了古藤，向下跃去。\n"NOR,me);
	tell_object(me,YEL"你越坠越快．．．．冷风在你耳边呼呼掠过。\n"NOR);
        return 1;
}

int jump_down(object me)	{
        object room;
        if(!objectp(me)|| me->is_ghost() || environment(me)!=this_object()) return 1;
	room=find_object(AREA_EREN2"cavein");
	if(!objectp(room)) 
        	room = load_object(AREA_EREN2"cavein"); 
	me->move(room);
	tell_object(me,HIW"许久，你终于通的一声踩到了实地，周围忽然一下子亮起来，照的你睁不开眼。\n"NOR);
        return 1;
}


int do_climb(string arg)
{
        object room;
        object me;
        me = this_player();
	if (arg=="up" || !arg || arg=="古藤" || arg=="vine"){
	        call_out("climb_out",6,me);
	        me->start_busy(3);
		tell_object(me,"来日方长，你决定多做些准备，多邀些帮手再来。\n");
		message_vision(YEL"$N抓住藤条，费力地向上爬去。\n"NOR,me);
		return 1;
	}
	return notify_fail("你要爬什么？\n");
}

int climb_out(object me)	{
        object room;
        if(!objectp(me)|| me->is_ghost() || environment(me)!=this_object()) return 1;
	room=find_object(__DIR__"vroad5");
	if(!objectp(room)) 
        	room = load_object(__DIR__"vroad5"); 
	me->move(room);
	tell_object(me,HIW"许久，你终于爬出了洞口。\n"NOR);
        return 1;
}
