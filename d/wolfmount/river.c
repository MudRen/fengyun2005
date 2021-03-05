#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小溪底");
        set("long", @LONG
这里是浣花溪的中央，河流虽浅但水流湍急。溪水中各色缤纷的花瓣随着溪水
静静地流淌。几条小鱼偶尔跃出又复落水中，圈圈水波打破了宁静和谐的溪面。
LONG
        );
	set("outdoors","wolfmount");
        set("objects", ([
                	__DIR__"npc/fish" :3,
        	]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-5);
	setup();
}

void init()
{
	if(interactive(this_player()))
		call_out("do_flush",7,this_player());
	
}

void do_flush(object me)
{
	object room;

        if(!me || environment(me) != this_object())
                return;
	message_vision(HIY"溪水比想象的深得多，$N连忙摒住呼吸，扒拉上岸。。。\n"NOR,me);
	room= load_object(__DIR__"brook2");
	me->move(room);
}