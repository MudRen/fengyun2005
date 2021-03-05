//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "甬道");
    set("long", @LONG
一条极其阴暗的甬道，两侧的长明灯竟然都已经熄灭，只有尽头处剩下一盏
还闪动着幽幽的光芒，一个人影正靠着灯下的石壁，状若沉思，又似在掩盖着什
么秘密。
LONG
    );
    set("exits", 
      ([ 
	"east" : __DIR__"changlang2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/jianchi" : 1,
      ]));
    set("item_desc", ([
		"lamp": "一盏摇曳不定的长明灯，灯台似乎有些松动，有人为挪动（move）的迹象。\n",
		"长明灯": "一盏摇曳不定的长明灯，灯台似乎有些松动，有人为挪动（move）的迹象。\n",
      ]) );

    set("indoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-260);
    set("coor/z",30);
    set("no_fly",1);
    setup();
}

void init()
{
    add_action("do_move", "move");
}


int do_move(string arg)
{
    object me;
    me = this_player();
    
    if(arg != "长明灯" && arg != "lamp")
		return notify_fail("你要移什么？\n");
    
    if (REWARD_D->check_m_success(me,"王图一梦"))
		return notify_fail("叶孤城叛乱之事已定，没必要再下去了。\n");
	    
    if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙。\n");
		
    if (present("jian chi",this_object()))
    {
		present("jian chi",this_object())->ccommand("say 不……不要碰……不……可以……");
		return 1;
    }
    message_vision(HIB"$N轻轻扭动灯台，脚下的石板突然翻开，$N直直坠了下去。\n"NOR,me);
    me->move(load_object(__DIR__"mysticroom"));
    me->perform_busy(1);
    message(HIR"vision",me->name()+"掉了下来。"NOR,environment(me),me);
    return 1;
}



/*

	       (\~~~/)            
	       ( ．．)        

	       (_____)~．      

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
