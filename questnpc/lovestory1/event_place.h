//mimicat@fy4


#include <ansi.h>

mapping *event_list= ({
	([	"name":"沉香台",
		1:({"event_meet",10}),
	]),
	([	"name":"舞雩台",
		1:({"event_meet",10}),
	]),	
	([	"name":"法王寺",
		1:({"event_meet",3}),
	]),	
	([	"name":"散花坞",
		1:({"event_meet",3}),
	]),	
	([	"name":"梨园",
		1:({"event_meet",3}),
	]),			
});



mapping query_event(object here);
int enable_event(string event,object me);
int add_trigger_count(object me)
{
	string trigger;
	int count,i,event_count;
	string event;
	mapping events;

//	判断应该发生的事件是否发生过了。	
	if(event=me->query("event_working/"+query("short")))
		enable_event(event,me);
	trigger="event_trigger_count/"+query("short");
	me->add(trigger,1);
	count=me->query(trigger);
	events=query_event(this_object());
	for(i=1;i<sizeof(events);i++)
	{
		event=events[i][0];
		event_count=events[i][1];
		event_count=event_count+random(event_count);
//		判断是否能够发生事件，是否在这里经过了足够的次数，该事件是否已经结束。
		if(me->query("enable_event/"+event)&&count>event_count
			&&me->query("event_finished/"+query("short"))!=i)
		{
			me->delete(trigger);
			me->set("event_finished/"+query("short"),i);
			me->set("event_working/"+query("short"),event);
			enable_event(event,me);
		}
	}
	return 1;
}


int enable_event(string event,object me)
{
	remove_call_out(event);
	call_out(event,3+random(3),me);
}




mapping query_event(object here)
{
	int i;
	string place_name;
	
	place_name=here->query("short");
	for(i=0;i<sizeof(event_list);i++)
	{
		if(event_list[i]["name"]==place_name)
			return event_list[i];
	}
}



int event_meet(object me)
{
	object heroine;
	
	if(environment(me)!=this_object())
		return 0;
	me->delete("event_working/"+query("short"));
	heroine=new("/questnpc/lovestory1/secretgirl1.c");
	heroine->set("event_person",me);
	heroine->move(this_object());
	message_vision(HIW"一阵幽香轻袭而过。\n"NOR,me);
	me->add("lovestory1/event_meet_count",1);
}

