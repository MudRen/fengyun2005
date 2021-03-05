// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
mapping directions= ([
		"west":		"西方",
		"north":	"北方",
		"east":		"东方",
		"south":	"南方"
			]);


void echoforest(object me);
void create()
{
        set("short", "古树顶");
        set("long", @LONG
丛树顶放眼望去，林海茫茫，了无边际。浓密的树枝象一块厚实的地毯铺盖着
整个大地，看不出一点道路的痕迹。这棵树上粗壮的[37m树枝[32m极力向四周伸展，其中有
一根略为光滑，似乎是经常被人攀把过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"down" : __DIR__"center1",

	]));
        set("outdoors", "manglin");
	set("current_dir",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_swing","swing");
	add_action("do_turn","turn");
	add_action("do_look","look");
}
int do_look(string arg)
{
	if( arg == "vine" 
		|| arg == "树枝" )
	{
	write("树上有无数根粗壮光滑的树枝，对着四面八方，你可以试着荡荡看（swing），
向着你想去的方向荡上两次便能够到达你要去的地方了。
东（万梅山庄）南（南海）西（沉香镇）北（风云城）\n");
	return 1;
	}
	return 0;
}

int do_swing(string arg)		// WEST END
{
	object me;
	int c_dir;
	me = this_player();
   	
   	if (arg == "west" || arg == "north" || arg == "east" || arg == "south") {
   		 if (!random(10))	echoforest(me);
   		 message_vision("\n\n$N抓紧树枝，用力向"+directions[arg]+"荡去！	
听着耳边的呼呼风声，$N不禁惊叫道：
啊啊啊．．．哦哦哦哦哦哦．．．啊啊！！！\n\n",me);
		if(arg == "west")
			me->move(__DIR__"edge1");
		else
			switch (arg) {
				case "north":	me->move(__DIR__"top2"); break;
				case "east":	me->move(__DIR__"top3"); break;
				case "south":	me->move(__DIR__"top4"); break;
			}
		return 1;
	}

	tell_object(me,"你想要荡什么？（swing east/south/west/north）\n");		
		
	return 1;

}


int do_turn(string arg)
{
	object me;
	int c_dir;
	me = this_player();
    if( arg == "vine" || arg == "树枝" )
    {
		message_vision("$N嘿咻嘿咻地用力扳动树枝，又回忆起往日的美好时光。\n",me);
        return 1;
    }
        
    tell_object(me,"你想转动什么？（此处可“turn vine 或者 turn 树枝”）\n");   
    return 1;

}

void echoforest(object me)
{
	int i;
	object room;
	string *names = ({"center1","center2","center3", "center4",
		"dummy1","dummy2","dummy3","dummy4",
		"groupe1","groupe2","groupe3","groupe4",
                "groupw1","groupw2","groupw3","groupw4",
                "groupn1","groupn2","groupn3","groupn4",
                "groups1","groups2","groups3","groups4",
		"top2","top3","top4" });
	for(i=0;i<sizeof(names);i++)
	{
		if( room = find_object(__DIR__+names[i]))
		tell_object(room,HIW "\n\n远方传来一声长叫：＂啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！＂\n\n"NOR);
	}
}
