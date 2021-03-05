inherit __DIR__"heroine";
#include <ansi.h>
void create()
{
	set_name("神秘女子",({"secret girl","girl"}) );
	set("long", "明艳不可方物的面容，但却刻印着一丝淡淡的忧愁。\n");
	::create();
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}
	
void kill_him(object me);
	
mapping *event_list=({
	([	"question": "name",
		1: ([	1: ({"command","hmm",	}),
		]),
	]),
	([	"question": "age",
		1: ([	1: ({"message","$N哼了一声，并不理睬$n。\n",})
		]),
	]),
	([	"question": "here",
		1: ([	1: ({"command","hmm",}),
			2: ({"delay",5}),	
			3: ({"message",CYN"$N说道：“你觉得呢？”\n"NOR,}),
		]),
	]),
	([	"events": "sigh",
		1: ([	1: ({"message",HIY"$N低头叹道：“如此星辰如此夜，为谁风露立中宵？”\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh2",
		1: ([	1: ({"message",HIM"$N入神的看着明媚的星空，似乎完全没有注意到其他人的存在。”\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh3",
		1: ([	1: ({"message",HIW"$N。。。。。。。”\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh4",
		1: ([	1: ({"message",HIW"$N。。。。。。。”\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh5",
		1: ([	1: ({"message",HIW"$N。。。。。。。”\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
});
	
mapping query_answers(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["question"]==topic)
			return event_list[i];
	return 0;
}

mapping query_events(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["events"]==topic)
			return event_list[i];
	return 0;
}


void kill_him(object me)
{
	kill_ob(me);
}

void init()
{
	object me;
	
	::init();
	me=this_player();
	if(me==query("event_person")&&interactive(me))
	switch(me->query("lovestory1/event_meet_count"))
	{
		case 1:
		event_action(me,"sigh");
		break;
		
		case 2:
		event_action(me,"sigh2");
		break;
		
		case 3:
		event_action(me,"sigh3");
		break;
		
		case 4:
		event_action(me,"sigh4");
		break;
		
		case 5:
		event_action(me,"sigh4");
		break;
	}
}