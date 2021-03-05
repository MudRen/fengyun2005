#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long", @LONG
无边无际的丛林中一片黑暗，就是再烈的日光也穿不透那密密的树叶，黑暗中
充满了各式各样的危险，每一种都可以致命。若是在丛林中迷失了方向，饥渴就足
以致命。如果没人指引的话，生还的可能性是微乎其微的。
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest_c",
		"south" : __DIR__"forest_c",
		"east" : __DIR__"forest_c",
		"west" : __DIR__"forest_c",
	]));
	set("outdoors", "ghost");
	set("coor/x",-70);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}

void init(){
	add_action("do_go", "go");
}



int	do_go(string dir){
	
	string route, walk;
	object room, gudu;
	object who = this_player();
	
	if (!userp(who))	return 0;
		
	walk = who->query_temp("marks/gudumei_walk");
	switch (dir){
		case "east": walk = walk + "e";  break;
		case "west": walk = walk + "w";  break;
		case "north": walk = walk + "n"; break;
		case "south": walk = walk + "s"; break; 	
		default:	return 0;
	}
//	tell_object(who, "route is "+ who->query_temp("marks/gudumei_route") +"\n");
//	tell_object(who, "walk is "+ walk +"\n");
	who->set_temp("marks/gudumei_walk", walk);
						
	if (strlen(walk)< strlen(who->query_temp("marks/gudumei_route"))){
		tell_object(who,BLU"一个黑影闪过，紧紧地跟在你的背后。\n"NOR);
		return 1;
	}
	
	if (who->query_temp("marks/gudumei_route"))
	if (!strcmp(walk, who->query_temp("marks/gudumei_route")))
	{
		room = find_object(__DIR__"forest8");
		if (!room) room = load_object(__DIR__"forest8");
		gudu = present("gu du mei", room);
		if (!gudu) gudu = new (__DIR__"npc/gudumei2");
		who->move(room);
		tell_object(who,CYN"孤独美说：不错，出口就在眼前了。\n"NOR);
		gudu->move(room);
		return 1;
	}
	
	tell_object(who, WHT"后面有人不满地说道：“为甚么不听我话？这样乱走是走不出的！
算了，你自谋生路吧。”落叶上悉悉簌簌的脚步声渐渐远去。。。。\n"NOR);
	
	who->delete_temp("marks/gudumei_route");
	who->set_temp("marks/gudumei_walk","");
	who->move(__DIR__"forest1");
	return 1;
}

/*
int	valid_leave(object who, string dir){
	
	string route, walk;
	object room, gudu;
	
	walk = who->query_temp("marks/gudumei_walk");
	switch (dir){
		case "east": walk = walk + "e";  break;
		case "west": walk = walk + "w";  break;
		case "north": walk = walk + "n"; break;
		case "south": walk = walk + "s"; 	
	}
//	tell_object(who, "route is "+ who->query_temp("marks/gudumei_route") +"\n");
//	tell_object(who, "walk is "+ walk +"\n");
	who->set_temp("marks/gudumei_walk", walk);
						
	if (strlen(walk)< strlen(who->query_temp("marks/gudumei_route"))){
		tell_object(who,BLU"一个黑影闪过，紧紧地跟在你的背后。\n"NOR);
		return 1;
	}
	
	if (!strcmp(walk, who->query_temp("marks/gudumei_route")))
	{
		room = find_object(__DIR__"forest8");
		if (!room) room = load_object(__DIR__"forest8");
		gudu = present("gu du mei", room);
		if (!gudu) gudu = new (__DIR__"npc/gudumei2");
		who->move(room);
		tell_object(who,CYN"孤独美说：不错，出口就在眼前了。\n"NOR);
		gudu->move(room);
		return notify_fail("\n");
	}
	
	tell_object(who, WHT"后面有人不满地说道：“为甚么不听我话？这样乱走是走不出的！
算了，你自谋生路吧。”落叶上悉悉簌簌的脚步声渐渐远去。。。。\n"NOR);
	
	who->delete_temp("marks/gudumei_route");
	who->set_temp("marks/gudumei_walk","");
	who->move(__DIR__"forest1");
	return notify_fail("\n");
}
*/