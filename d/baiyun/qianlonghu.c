#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "潜龙泉");
    set("long", @LONG
剑林西行，蜿蜒盘亘的是一条溪流，汩汩得冒着热气，千万年前白云本为火山，
千载而下，火山不再，但地热丰富，其中夹杂着许多世人不能参晓的物质，不过白
云岛的岛民和白云城的弟子倒也经常来这条形状宛如龙盘的泉水中沐浴，时日一久
更加发觉这汩汩热流着实功用非凡。
LONG
    );
    set("exits", 
      ([ 
		"eastup" : __DIR__"jianlin",
      ]));
    set("outdoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-60);
    set("coor/z",0);

    set("resource/water",1);
    set("liquid/name","潜龙泉水");
    set("liquid/container","潜龙泉");
    set("liquid/type", "water");

    setup();
}



void init()
{
    add_action("do_jump", ({"wash","jump"}));

}

int do_jump()
{
    object me;
    int wait;
    me = this_player();
    		
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("你已经在洗澡了。\n");
    if (me->query("gender")=="女性")
    	message_vision(YEL"$N缓步走入池中，挽起一瓢泉水，晶莹的水珠滴滴从发梢、身畔滚落。。。\n"NOR,me);
    else
    	message_vision(YEL"$N扑通一声跳进泉中，池水荡漾，如情人的手在$N身上轻轻摩挲。。。\n"NOR,me);
    	
    me->set_temp("jiqi/in_pool",1);
	me->add_temp("jiqi/pool_num",1);
	
	call_out("done_pool",20, me);
	return 1;
}


void done_pool(object me)
{
    int gin,kee,sen;
    string msg;
    
    if(!me)	return;
    	
    if ( me->is_ghost() || environment(me)!= this_object()) 
    {
    		me->delete_temp("jiqi");
    		return;
    }
    	
    if (me->query_temp("jiqi/pool_num")>=3) {
		if (me->query("gender")=="女性")
			msg = WHT"你懒懒地从潜龙泉里站起身来，脸色微红，眼眸湿润，显得越发地清丽脱俗，娇媚可爱。\n"NOR;
		else
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


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
