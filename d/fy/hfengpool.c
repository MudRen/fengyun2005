inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
    set("short", "枫叶泉");
    set("long", @LONG
风云城中的枫叶泉是方圆五百里最著名的一口温泉。水温适中，泉水呈淡红,
故而得名枫叶。它不但有去腐生肌的奇效，据说还有延年益寿的妙用。武林第一
美人林仙儿每天都以此泉水浣面（ｗａｓｈ），来保持她如花似玉的容貌。
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang3",
      ]));
    set("objects", ([
	__DIR__"npc/xianu": 1,
	__DIR__"npc/troublemaker": 1,
      ]) );
    set("outdoors", "fengyun");
    set("no_fly", 1);
    set("coor/x",-80);
    set("coor/y",-260);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("north","door","檀木门", "south", DOOR_CLOSED);

}

void init()
{
    add_action("do_jump", "wash");

}

int do_jump()
{
    object me;
//  int wait;
    me = this_player();
    
    if (me->query("gender")=="男性"){
    	tell_object(me, "大老爷们到这里瞎转什么，小心撞见春十三娘。\n");
    	return 1;
    }
    	
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("你已经在洗澡了。\n");
    
    message_vision(YEL"$N缓步走入池中，挽起一瓢泉水，晶莹的水珠滴滴从发梢、身畔滚落。。。\n"NOR,me);
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
		msg = WHT"你懒懒地从枫叶泉里站起身来，脸色微红，眼眸湿润，显得越发地清丽脱俗，娇媚可爱。\n"NOR;
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