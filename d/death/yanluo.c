// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "阎罗殿");
        set("long", @LONG
经过一路走来的黑暗，乍进门来，牛油巨烛耀眼的光芒让你一阵晕眩，定下神
来，鎏金镶玉的王座上端坐着一位黑面君王，正是掌握六道轮回，万物来世的阎罗
王。两侧四名判官，各捧生死簿册，牛头，马面，各拿武器，横眉怒目，当堂责罚
人犯。世上一切蠃虫，羽虫，毛虫，鳞介无不在此受判。
LONG
        );
        set("objects", ([
                __DIR__"npc/yanwang":1,
		__DIR__"npc/panguan2" : 4,
		__DIR__"npc/niutou" : 3,
		__DIR__"npc/mamian" : 3,
        ]) );
		set("no_revive",1);
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		set("no_fight",1);
		setup();
}
void init()
{	
	object me=this_player();
	if (userp(me)){
		call_out("letgo",15,this_player());	
		me->start_busy(10);
	}
		
}

void letgo(object me)
{
	object room;
	if(!me || environment(me) != this_object()) return;
	message_vision("\n\n\n阎王爷长叹一口气：＂算了，算了，让$N四处逛逛，
知道这里是赏罚分明，只要$N来世再也不敢胡作非为就可以了！＂\n\n",me);
	message_vision("\n\n一阵冷风吹散了$N的阴魂．．．\n\n",me);
	room = load_object(__DIR__"dizang");
	if(objectp(room))  me->move(room);	
	me->stop_busy();
} 
