//sinny@fengyun.com 

#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", HIB"怒海石梁"NOR);
    set("long", @LONG
这石梁上隔青天，下绝碧海，孤零零横亘在怒礁与拍浪崖之间，仿佛天地之间至
此而断，人世间所有烦扰忧愁也随风而去，随海而逝。怒海惊涛，仿佛一个巨浪就可
把这千年石梁拍为齑粉。
LONG
    );
    set("exits", 
      ([ 
	"west" : __DIR__"pailangya",
	"east" : __DIR__"nujiao",
      ]));
    set("objects", 
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-30);
    set("coor/z",0);
    setup();
}

/*
int valid_leave(object me, string dir)
{
    object room;
    object ob;

    if(userp(me))
	if (random(3)>0)
	    if (random(10)>-1)
	    {
		room = load_object(__DIR__"huangsha1");
		message_vision(HIB"\n怒海排崖，狂风劲吹，$N脚下一个踉跄，惊叫一声被巨浪卷进大海。。\n\n"NOR,me);
		me->unconcious();
		me->move(room);
		return notify_fail(" ");
	    }

    return 1;
}

*/