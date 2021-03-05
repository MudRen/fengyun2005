inherit NPC;


mapping query_answers(string topic);
mapping query_events(string topic);

string *msg_dunno = ({
	"$n根本不想回答你的问题。\n",
	"$n睁大眼睛望著$N：这么简单的问题都要问吗？\n",
	"$n耸了耸肩，很惋惜地说：你真是不可救药！\n",
	"$n说道：嗯....这问题你可以问问自己吗！\n",
	"$n说道：对不起，太多人问我同样的问题了！\n"
});

int inquiry_action(object me,string inquiry,int count,mapping actions)
{
		
	if(actions) 
	{
		if(count>sizeof(actions))
			count=sizeof(actions);
		set_temp("inquiried",actions[count-1]);
	}
	else
		message_vision(msg_dunno[random(sizeof(msg_dunno))],me,this_object());
	return 1;
}
	
int do_ask(string arg)
{
	object me,ob;
	string dest, topic;
	int count;
	mapping actions;
	
	me=this_player();
	ob=this_object();
	
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return 0;
	if( !objectp(ob = present(dest, environment(me))) )
		return 0;
	if( ob!=this_object())
		return 0;
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
	if( ob->query_temp("inquiried"))
	{
		tell_object(me,ob->query("name")+"正在思索着什么，还是等一会再问吧。。。\n");
		return 1;	
	}

	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
	me->add_temp("inquiried/"+topic,1);
	count=me->query_temp("inquiried/"+topic);
	actions=query_answers(topic);
	set_temp("inquirying_person",me);
	return inquiry_action(me,topic,count,actions);
}
	
int event_action(object me,string topic)
{
	mapping events;
	
	events=query_events(topic);
	set_temp("inquiried",events[1]);
	set_temp("inquirying_person",me);
	return 1;
}
	
void heart_beat()
{
	string answer,func;
	mapping events;
	mixed *event;
	object me;
	int i,j;
	
	::heart_beat();
	if(j=query_temp("delay/duration"))
		add_temp("delay/duration",-1);
	else
	if(events=query_temp("inquiried"))
	{
		me=query_temp("inquirying_person");

		for(i=1;i<=sizeof(events);i++)
		{
			if(j=query_temp("delay/status"))
			{
				i=j+1;
				delete_temp("delay/status");
			}
			event=events[i];
			switch(event[0]) {
			case "message":
				message_vision(event[1],this_object(),me);
				break;
			case "function":
				call_out(event[1],1,me);
				break;
			case "command":
				this_object()->ccommand(event[1]);
				break;
			case "enable":
				break;
			case "delay":
				set_temp("delay/duration",event[1]);
				set_temp("delay/status",i);
				break;
			}
			if(j=query_temp("delay/duration"))
				break;
		}
		if(!j)
			delete_temp("inquiried");
	}		
}

