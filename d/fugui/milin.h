
//【五行相生】：木生火、火生土、土生金、金生水、水生木。 
//【五行相克】：木克土、土克水、水克火、火克金、金克木
//  s w e s w from 火

#include <ansi.h>

int check_dirs(object me, string dir);

/*
int valid_leave(object me, string dir)
{
	int lsteps,tsteps;
	int brief, brief2, brief3;
	string mout;
	object room;
	
	check_dirs(me,dir);
	lsteps=me->query_temp("milin_steps");
	tsteps=me->query_temp("milin_walk");
	if(lsteps>=15 && (random(tsteps)>=20 && !random(4)))
	{
		room=find_object(__DIR__"tomb");
		if(!room) room=load_object(__DIR__"tomb");
		mout="人影飘动之间，$N已经从密林穿了出去！\n";
	}
	else if( lsteps< -15 && (random(tsteps)>=20 && random(4)))
	{
		room=find_object(__DIR__"shandao3");
		if(!room) room=load_object(__DIR__"shandao3");
		mout="人影飘动之间，$N已经从密林穿了出去！\n";
		
	}
	if(room)
	{
		message_vision(mout,this_player());
		
// 		don't want to mess up with move(), so...a lazy fix... by silencer.		
		if (me->query("env/brief3")) brief3=1;
		if (me->query("env/brief2")) brief2=1;
		if (me->query("env/brief")) brief=1;
		me->delete("env/brief");
		me->delete("env/brief2");
		me->delete("env/brief3");
		
		me->move(room);
		
		if (brief3) me->set("env/brief3",1);
		if (brief2) me->set("env/brief2",1);;
		if (brief) me->set("env/brief",1);
		
		me->set_temp("milin_steps",0);
		me->set_temp("milin_walk",0);
		return notify_fail("");
	}
	me->add_temp("milin_walk",1);
	return 1;			
}*/

void init(){
	add_action("do_go","go");
	add_action("do_leave","leave");
}

int do_go(string arg){
	int lsteps,tsteps;
	int brief, brief2, brief3;
	string mout;
	object room,me;
	me = this_player();
	
	if (arg!= "north" && arg!="south" && arg != "east" && arg != "west") return 0;
	
	check_dirs(me,arg);
	lsteps=me->query_temp("milin_steps");
	tsteps=me->query_temp("milin_walk");
	
	if(lsteps>=15 && (random(tsteps)>=20 && !random(4)))
	{
		room=find_object(__DIR__"tomb");
		if(!room) room=load_object(__DIR__"tomb");
		mout="人影飘动之间，$N已经从密林中穿了出去！\n";
	}
	else if( lsteps< -15 && (random(tsteps)>=20 && random(4)))
	{
		room=find_object(__DIR__"shandao3");
		if(!room) room=load_object(__DIR__"shandao3");
		mout="人影飘动之间，$N已经从密林中穿了出去！\n";
		
	}
	
	if(room)
	{
		message_vision(mout,this_player());	
		me->move(room);		
		me->set_temp("milin_steps",0);
		me->set_temp("milin_walk",0);
		return 1;
	}
	me->add_temp("milin_walk",1);
	return 0;
}


int check_dirs(object me, string dir)
{
	string attrib_old,attrib_new;
	int stag;
	object room;
	mapping dirs;
	dirs=query("exits");
	if ( !undefinedp(dirs[dir]))
	{
		 room=find_object(dirs[dir]);
		 room=load_object(dirs[dir]);
		 attrib_old=query("attribute");
		 attrib_new=room->query("attribute");
	switch(attrib_old)
		{
		case "jin":
			if( attrib_new == "shui")
				me->add_temp("milin_steps",1);
			else if(attrib_new =="mu")
			   me->add_temp("milin_steps",-1);
			else
			   me->set_temp("milin_steps",0);
			break;
		case "mu":
			if(attrib_new == "huo")
			   me->add_temp("milin_steps",1);
			else if(attrib_new =="tu")
			   me->add_temp("milin_steps",-1);
			else
			   me->set_temp("milin_steps",0);
			break;
		case "shui":
			if(attrib_new == "mu")
			   me->add_temp("milin_steps",1);
			else if(attrib_new =="huo")
			   me->add_temp("milin_steps",-1);
				 else
			   me->set_temp("milin_steps",0);
			break;
		case "huo":
			if(attrib_new == "tu")
			   me->add_temp("milin_steps",1);
			else if(attrib_new =="jin")
			   me->add_temp("milin_steps",-1);
				 else
			   me->set_temp("milin_steps",0);
			break;
		case "tu":
			if(attrib_new == "jin")
			   me->add_temp("milin_steps",1);
			else if(attrib_new =="shui")
			   me->add_temp("milin_steps",-1);
				 else
			   me->set_temp("milin_steps",0);
			break;
		default:
			write("ERROR!!!!,PLEASE REPORT TO WIZARD!!!\n");

	}
	return me->query_temp("milin_steps");
 }
}


int do_leave(string arg)
{
	object room, me;
	me = this_player();
	room=find_object(__DIR__"shandao3");
	if(!room) room=load_object(__DIR__"shandao3");
	
	message_vision("$N绝望地抬起头大叫：我迷路了，放我出去！！！！\n", me);
	message_vision(WHT"\n林子里忽然起了一阵风，飘飘悠悠地飞来个风筝把$N吊了起来。\n"NOR,me);
	
	tell_object(room,me->name()+"扑通一声从半空中掉了下来，一脸茫然的样子。\n");
	me->move(room);
	return 1;
}
