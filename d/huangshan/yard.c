// mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小院");
    	set("long", @LONG
青砖铺地的院落当中是一棵巨大的松树，松树巨大的树冠覆盖了大半的庭院，
没有人知道树有多老，似乎当初建松谷庵的时候就已有了，而松谷庵则因它起名。
院落中松树的四周开辟着几个花坛，里面种植着一些花草，整个院落干净整洁。院
子两侧各有几间禅房，当中是一个佛堂。(上树抓鸟技能move需大于80)        
LONG
        );
	set("exits", ([ 
    	"south" : __DIR__"antang",  
		"north" : __DIR__"songgu",
	]));
	set("item_desc",	([
		"pine":		"一颗巨大的松树，没有点轻功是爬不上去的。\n",
		"松树":		"一颗巨大的松树，没有点轻功是爬不上去的。\n",
	]));	 
    	set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "往树下走了过来。\n");
        }
}
int do_climb(string arg)
{
	object me;
	
	me=this_player();
	if( arg!="tree" ) return 0;
	if( me->query_skill("move",1)< 80 + random(30))
	{
		message_vision(HIG"$N笨手笨脚的爬着大松树，结果一失手就掉了下来。\n"NOR,me);
		me->start_busy(2);
		return 1;
	}
	else
        message_vision("$N手脚并用，敏捷地爬上了大松树。\n",me);

        tell_room(__DIR__"tree1", this_player()->name() + "从树下爬了上来。\n");
        me->move(__DIR__"pinetree");

        return 1;
}
	
int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree1",
                "树下的" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
        return 1;
}

