inherit DOOR_ROOM;
#include <room.h>
#include <ansi.h>

void create()
{
    set("short", "浸龙浴池");
    set("long", @LONG
一入门，热气扑面，白白的水气立刻包围了你。你依稀看到一个巨大的檀木水池,
水呈碧绿，散发着一种奇特的药香，水面上还漂着一片片红红的花瓣儿，你真想一下
子跳（ｊｕｍｐ）进去，闭上眼睛好好的放松一下。
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlonglang3",
      ]));
    set("objects", ([
	__DIR__"npc/xianu": 1,
	__DIR__"npc/troublemaker": 1,
      ]) );
    set("no_fly", 1);
    set("coor/x",-80);
    set("coor/y",-140);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("south", "door","檀木门", "north", DOOR_CLOSED);

}

void init()
{
    add_action("do_jump", "jump");

}

int do_jump()
{
    object me;
//  int wait;
    me = this_player();
    
    if (me->query("gender")=="女性") {
    	tell_object(me,"这么多大男人看着，你怎么好意思洗澡呢？\n");
    	return 1;
    }
    	
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("你已经在洗澡了。\n");
    
    message_vision(YEL"$N扑通一声跳进泉中，池水荡漾，如情人的手在$N身上轻轻摩挲。。。\n"NOR,me);
    if(!me->query("宿命B/武当_枫叶") && !random(10))
		call_out("give_maple_leaf",5,me);
    me->set_temp("jiqi/in_pool",1);
	me->add_temp("jiqi/pool_num",1);
	
	call_out("done_pool",20, me);
	return 1;
}


int give_maple_leaf(object me)
{
    object leaf;

    if(!me || !present(me,this_object()))
	return 1;
    tell_object(me,"一片红红的枫叶飘了过来，你好奇的将它拾了起来。\n");
    leaf=new("/d/fy/obj/mapleleaf");
    leaf->move(me);
    return 1;
}


void done_pool(object me)
{
//  int gin,kee,sen;
    string msg;
    
    if(!me)	return;
    	
    if ( me->is_ghost() || environment(me)!= this_object()) 
    {
    		me->delete_temp("jiqi");
    		return;
    }
    
       	
    if (me->query_temp("jiqi/pool_num")>=3) {
		msg = WHT"你从枫叶泉里一跃而起，浑身热气腾腾，透着用不完的劲儿！\n"NOR;
		tell_object(me, msg);
		me->delete_temp("jiqi");
		me->full_me();
	} 
	else {
		tell_object(me,"你感到全身无比的舒泰，忍不住再想多洗一次。。。。\n");
		me->delete_temp("jiqi/in_pool");
	}
	
    return;
}


int valid_leave(object me, string dir){
	
	me->delete_temp("jiqi");
	return ::valid_leave( me, dir);

}