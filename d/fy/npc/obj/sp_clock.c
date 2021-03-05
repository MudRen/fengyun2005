// annie 07.2003
// dancing_faery@hotmail.com

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("定时闹钟", ({ "clock" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1000);
		set("material", "steel");
		set("long", "一个从西洋国度流传过来的小圆铁块(watch clock)。\n");
		set("desc_ext","闹铃(settime) ");
	

	}
	::init_hammer(3);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_set","settime");
	      add_action("do_watch","watch");
         }


int do_set(string arg)
{
	int time;
	object me,clock;
	me = this_player();
	clock=this_object();
	if (!arg)
		return notify_fail("你要弹什么？\n");

	if( sscanf(arg, "%d", time)!=1 || time < 0 || time > 43200)
		return notify_fail("用settime [秒数]来设置闹铃时间，时间不能超过六个时辰。\n");
	message_vision("$N取出一个定时闹钟，一板一眼的拧起发条。\n",me);
	remove_call_out("do_beep");
	call_out("do_beep",time,me);
	clock->set("time",time());
	clock->set("time2",time);
	return 1;
}

int do_watch(string arg)
{	int x,y;
	object me,clock;
	me = this_player();
	clock=this_object();
	if (environment() != me)
		 return notify_fail("什么？\n");
      if (!arg||arg!="clock")
		return notify_fail("你要看什么？\n");
	if(!clock->query("time"))
			return notify_fail("还没定时你要看什么？\n");
		
     y= clock->query("time2")+query("time")-time();
     if(y<0)
           	return notify_fail("闹钟都结束了你要看什么？\n");
     
	x=time()-clock->query("time");

	message_vision("$N取出一个定时闹钟，看了一眼。\n",me);
      tell_object(me,"\n定时闹钟显示时间已经过去了：" +(x/60)+"分"+(x%60)+"秒。\n");
      tell_object(me,"\n定时闹钟距离结束还有：" +(y/60)+"分"+(y%60)+"秒。\n");
     
       
       	return 1;
}



void do_beep(object me)
{
	if (environment() == me)
	{
		message_vision("$N身上突然有什么东西＂哔哔哔＂的叫唤起来。\n",me);
		tell_object(me,"\n定时闹钟发出了一阵尖锐的鸣叫。\n\n现在时间是：\n");
		me->ccommand("uptime");
	}
}

