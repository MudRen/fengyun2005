mapping query_answers(string topic);
int inquiry_action(object me,string inquiry,int count,mapping actions)
{
		
	if(actions) 
	{
		if(count>sizeof(actions))
			count=sizeof(actions);
		set_temp("inquiried",actions[count-1]);
	}
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
		

	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
	me->add_temp("inquiried/"+topic,1);
	count=me->query_temp("inquiried/"+topic);
	actions=query_answers(topic);
	set_temp("inquiring_person",me);
	return inquiry_action(me,topic,count,actions);
}
	
void heart_beat()
{
	string answer,func;
	mapping action;
	object me;
	
	::heart_beat();

	if(action=query_temp("inquiried"))
	{
		me=query_temp("inquiring_person");
		answer=action["answer"];

		if(stringp(answer))
			message_vision(answer,this_object(),me);
		func=action["function"];
		if(stringp(func))
			call_out(func,1,me);		
		delete_temp("inquiried");
	}		
}