
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", "梅花小筑");
     set("long", @LONG
这是铁少夫妇歇息的地方，房中收拾的一尘不染，皓白如雪，但却空空荡荡没
什么摆设，除了墙上挂着一副昔年铁少赠与雪蕊儿的“雪梅傲霜图”外，便只有一
大块青白玉石。当年铁少夫妇行走江湖，雪蕊儿被仇家所伤，几近不治，铁少踏遍
天涯，历尽艰辛，终于觅得这块产于极北苦寒之地的寒玉石为雪蕊儿疗伤。
LONG
        );
    	set("exits", ([ 
  			"west" : __DIR__"bamboo_hall",
		]));

    	set("item_desc", ([
      		"寒玉石": "一块长条的青白玉石，床上只铺了张草席，一幅白布当作薄被，你可以躺(laydown)在上面。\n",
      		"青白玉石": "一块长条的青白玉石，床上只铺了张草席，一幅白布当作薄被，你可以躺(laydown)在上面。\n",
      		"玉石": "一块长条的青白玉石，床上只铺了张草席，一幅白布当作薄被，你可以躺(laydown)在上面。\n",
      		"jadebed": "一块长条的青白玉石，床上只铺了张草席，一幅白布当作薄被，你可以躺(laydown)在上面。\n",
   		]) );
    	set("no_magic", 1);
		set("coor/x",20);
		set("coor/y",0);
		set("coor/z",0);
		setup();
}

void init()
{
	add_action("do_laydown", "laydown");
//	add_action("do_exercise","exercise");
}

int do_laydown()
{
	object me = this_player();
	if (me->query_temp("in_bed"))
	{
		return notify_fail("你在床上呢。。。\n");
	}
	message_vision("$N缓缓躺在寒玉床上。\n",me);
	me->set_temp("in_bed", 1);
	tell_object(me,"你只觉彻骨冰凉，寒气逼人。\n");
	call_out("curePlayer",5,me);
	return 1;
}

void curePlayer(object me)
{
	if (!me) return;
	me->set_temp("in_bed", 0);
	if (environment(me) == this_object())
	{
		tell_object(me,WHT"你慢慢觉得寒气渐去，感觉心头愈来愈暖，丹田之中气息流转不停。\n "NOR);
		if(me->query("eff_kee") != me->query("max_kee"))
		{
			tell_object(me,"你身上的伤势竟神奇般地好了！\n");
			me->set("eff_kee",me->query("max_kee"));
			me->status_msg("kee");
		}
		message_vision("$N从床上缓缓坐了起来，舒展一下筋骨，舒服极了。\n",me);
/*		if (me->query("class") == "legend")
		{
			me->set_temp("marks/FastenExec",1);
			//need to give tiexue dizi any hint that they can exercise here and get double effect?
		}	*/
	}
}

/*
int do_exercise(string arg)
{

	int kee_cost=30, force_gain;
	int ratio = 2;
	object me=this_player();

	if (!(me->query_temp("marks/FastenExec"))) return 0;

      	seteuid(getuid());
        
    	if( me->is_fighting() )
        	return notify_fail("战斗中不能练内功，会走火入魔。\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能练内功。\n");
    
    	if( !stringp(me->query_skill_mapped("force")) )
        	return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");
    
    	if( arg && !sscanf(arg, "%d", kee_cost) )
        	return notify_fail("你要花多少气练功？\n");

    	if( kee_cost < 10 ) return notify_fail("你最少要花 10 点「气」才能练功。\n");

    	if( (int)me->query("kee") < kee_cost )
        	return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

    	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
        	return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

    	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
        	return notify_fail("你现在精力不够，无法控制内息的流动！\n");

    	write("你暗运真气，心中一片清明，内息运转愈来愈快，却又平和通畅，浑身但觉舒畅无比。。 \n");

    	me->receive_damage("kee", kee_cost);
    	me->start_busy(1);
        // This function ranged from 1 to 15 when kee_cost = 30
    	force_gain = kee_cost * ((int)me->query_skill("force")/10
                             + (int)me->query_con() ) / 30;
    	force_gain = (force_gain + random(force_gain))/2;
	
	//what exactly double effect mean? -- change to 3/2
	force_gain = ratio * force_gain * 3/4;

    	if( force_gain < 1 ) {
        	write("但是当你行功完毕，只觉得全身发麻。\n");
        	return 1;
    	}

    	me->add("force", force_gain );
    
    	if( (int)me->query("force") > (int)me->query("max_force") * 2) {
        if( (int)me->query("max_force") >= 
            ((int)me->query_skill("force", 1) + 
             me->query_skill("force")/5) * 5 ) {

            write("当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶颈！\n");
	} else {
            write("你的内力增强了！\n");
            me->add("max_force", 1);
        }
        me->set("force", me->query("max_force"));
    }       
    return 1;	
    
}
*/

int valid_leave(object me, string dir)
{
	if (me->query_temp("in_bed")) 
	{
		remove_call_out("curePlayer");
		me->set_temp("in_bed", 0);
	}
	return 1;
}

