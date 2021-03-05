#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_go","go");
	add_action("do_look","look");
//	add_action("do_goo","goo");
	add_action("do_map","map");
	add_action("do_nothing",({ "new","chat","rumor","shout",
		"announce","alias","alter","fy","inform","gab",
		"tell","reply","set","cemote","cfy","entermaze",
		"recruit","team","afk","baohu","destroy","friend",
		"passwd","save","semote","suicide","task","tune",
		"vote","unset","new*","chat*","fy*","rumor*","gab*","riddle",
		"whistle", "ability","teamhp""apprentice","abandon"}));
}

int do_goo()
{
	object me = this_player();
	me->leftnow();
	return 1;
}
int do_nothing()
{
	object me = this_player();
	if (!query("free_cmds"))
	{
		write("你现在不能这么做。\n");
		return 1;
	}
		return 0;

}


string ngstr(string str)
{
    int i,i2;
    string strc;
    strc=str;
    // filter color-code
    str=replace_string(str,CSI,"");

    str=replace_string(str,"2;37;0m","");

    str=replace_string(str,"41;","");
    str=replace_string(str,"42;","");
    str=replace_string(str,"43;","");
    str=replace_string(str,"44;","");
    str=replace_string(str,"45;","");
    str=replace_string(str,"46;","");
    str=replace_string(str,"47;","");
    str=replace_string(str,"1;","");
    str=replace_string(str,"30m","");
    str=replace_string(str,"31m","");
    str=replace_string(str,"32m","");
    str=replace_string(str,"33m","");
    str=replace_string(str,"34m","");
    str=replace_string(str,"35m","");
    str=replace_string(str,"36m","");
    str=replace_string(str,"37m","");
    str=replace_string(str,"38m","");
    str=replace_string(str,"40m","");
    str=replace_string(str,"41m","");
    str=replace_string(str,"42m","");
    str=replace_string(str,"43m","");
    str=replace_string(str,"44m","");
    str=replace_string(str,"45m","");
    str=replace_string(str,"46m","");
    str=replace_string(str,"47m","");
    str=replace_string(str,"1m","");

    return str;

}



int do_map(string arg)
{
	object me = this_player();
	    int i;
    string file, area, room, map, room_name, room1;
    string a1, a2, a3;

	if (me->query_temp("timer/map")+2>time())
		return notify_fail("检验地图最多只能每两秒执行一次。\n");


	if (file_size("/d/phoenix/"+query("area")+"_map.txt")>0)
	{
	    map = read_file("/d/phoenix/"+query("area")+"_map.txt");
	    room_name = environment(me)->query("short");

	    room_name = ngstr(room_name);
//	    write(room_name); 
	    map = replace_string(map,room_name,BGRN HIW""+room_name+""NOR);
	    write (map);
	    write ("\n\n你现在所处地点的地名为  "+ HIR""+room_name + NOR"\n");
	    write ("此地名在地图上以"HIG"亮绿色"NOR"标出。（注意，可能有重名地点存在）\n\n\n");
	    me->set_temp("timer/map",time());
	    return 1;
	}
    return notify_fail("当前地区的地图不存在．．．\n");
}



int	do_go(string arg)
{
	object me = this_player();

	string l;
	//ici nous changeons des portes
	if (query("exits/"+arg))
	{
		l=query("exits/"+arg);
		if (l[0..0] != "/")
		{
			l = "/d/phoenix/base/"+query("owner")+"/"+query("area")+"/"+l;
			set("exits/"+arg,l);
		}
	}

	return 0;
}


int	do_look(string arg)
{
	object me = this_player();
	string *dir, l;
	mapping exits;
	object env;
		
	exits = query("exits");
	if (!mapp(exits) || sizeof(exits)<1)	return 0;
		
	dir = keys(exits);
	if (member_array(arg, dir) == -1)	return 0;
	
	l=query("exits/"+arg);
	if (l[0..0] != "/")
		l = "/d/phoenix/base/"+query("owner")+"/"+query("area")+"/"+l;

//	write("l is "+ l + "\n");
	
	env = find_object(l);
	if (!env)	env = load_object(l);
	if (env)	{
		"/cmds/std/look"->look_room(me, env);
	}	else
		write("ERROR: no object\n"); 
	return 1;
}
