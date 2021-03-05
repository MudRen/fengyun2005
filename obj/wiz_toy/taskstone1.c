//Created by justdoit at Oct 2001 
//All Rights Reserved ^_^
//combat_exp lvl star:200k moon:1.2M sun:2.8M
//skill lvl star:50 moon:100 sun:150

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY "月影石"NOR , ({ "taskstone" }) );
	set_weight(9);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","块");
		set("long", CYN"
盘古开天劈地之始，天地初开，日月星辰运转不断，而此石起源于远古月球坠落地球
的一块陨石，因其在月光下异彩涟涟，发出淡淡的黄色光辉，并显现圆月状奇异图案，
因而被称之为月影石。此石经一武林前辈异人加工，将其毕生武功心得刻于其上，并
在临终前将其两甲子的内丹封在此石之中。任何人只要得到此石将马上脱胎换骨，功
力大增。\n"NOR + YEL"
石头中心有一掌形凹印(moonmark)，刚好可以容纳一个人的手掌，
似乎可以Ｐｒｅｓｓ。\n
"NOR);
		set("value",20000);
		//set("no_get",1);
	}
}

void init()
{
	add_action("pressmark","press");
}

int pressmark(string arg)
{
		object me,room;
		int num, leftover, task_level, task_num;
		me = this_player();

   		if(!arg || arg!="moonmark") return notify_fail("你要按压什么？");

    	if(arg=="moonmark")  {
		/*if (me->query("rewarded_task")<50) {
			message_vision( HIR "$N觉得浑身筋脉欲断，“哗”一声喷出一蓬血雨！！\n" NOR, me);
			tell_object(me,"需要做５０个ｔａｓｋ才能使用！！！\n");
			return 1;
		}
		
		if(!wizardp(me)){
			tell_object(me,"这块宝石不是你能够使用的，你见都不应该见到。\n");
			return 1;
		}*/
			
		num = me->query("rewarded_task");
		
		task_level = F_LEVEL->get_level(me->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;		// 1/10 leveling up reward
    	    	    		
    	if (task_num <= num) {
    		tell_object(me," HEY YOU DONT NEED IT ANYMORE, wait for next level \n");
    		return 1;
    	}
    		
    	//leftover = task_num - num;
leftover = 1;
    	    tell_object(me,HIW"你完成了一个TASK，你得到一点评价！\n你的潜能点增加了50！\n"NOR);
		   me->add("rewarded_task",leftover);
		   me->add("task_pot",leftover*50);
		   me->add("potential",leftover*50);
		   me->add("TASK", leftover);
		   me->add("score",leftover);
		//   me->add("deposit",5000*leftover);
	   
	   message_vision(HIY "
月影石立时莹亮生辉，采光流溢。$N剧震一下，有若触电！！那是难以描述的一种强
烈感觉。就像月影石活了过来般，放射出无与伦比的精神异力，要侵进$N的脑袋和体
内去。奇怪而陌生的景象纷纷呈现，令人烦躁得几欲疯狂大叫，似若陷身在不能自拔
的噩梦。月影石的亮度不断剧增，亮得有如天上明月，彩芒闪耀，诡异无比。最后渐
渐的化成了一摊粉末。\n" NOR, me);
		//this_object()->destruct();
destruct(this_object());
room=environment(me);
//message("vision",this_object()->query("name")+"渐渐的化成了一摊粉末。\n",room);
tell_object(me,HIW"你完成了一个TASK，你得到一点评价！\n你的潜能点增加了50！\n"NOR);
		return 1;
	  }
}	

