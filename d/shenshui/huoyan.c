// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "火岩洞口");
        set("long", @LONG
原来整个神水宫是建筑在山腹之中，整个工程的巨大可想而知。你走到这里眼
前又是一番不同的景色，不远处一个洞口向外散发着热气，北面是一间美伦美焕的
大殿，南边的石梯上远远的也有几间房屋，只是异常的昏暗，看不太清楚。身旁的
石壁上明显可见人工的痕迹。
LONG
        );
        set("exits", ([ 
   "down" : __DIR__"migong2",
  "northup" : __DIR__"gong",
  "southup" : __DIR__"ruanhong",
]));
	set("item_desc", ([
		"stone" : (: stone :),
		"石壁" : (: stone :),
		"山石" : (: stone :),
	]));
   set("objects", ([ 
      __DIR__"npc/jian": 1,
   ]) );
	set("indoors","shenshui");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_push", "push");
}


string stone(){
	object me;
	me = this_player();
	if(me->query("class") == "shenshui"){
		tell_object(me, "石壁上布满了人工凿刻的痕迹，其中一块石头你可以推。（ｐｕｓｈ）\n");
	} else {
		tell_object(me, "石壁上布满了人工凿刻的痕迹。\n");
	}
	return "";
}


int do_push(string arg){
	object me, room, jian;
	
	me = this_player();
	if(!arg || (arg != "stone" && arg != "山石" && arg!= "石壁")){
		return notify_fail("你要触摸什么？\n");
	}
	if(me->query("class") == "shenshui"){
		tell_object(me, "你伸手在山石上运力一推。\n");
		tell_object(me, CYN"山石上裂开了一道逢，你闪身进去。山石又在你身后合拢。\n\n"NOR);
		message("vision", YEL"你隐约看到" + me->name()+"的身影在石壁旁一闪就消失不见了。\n"NOR, 
				environment(me), me);
		room = find_object(AREA_QINGPING"forest4");
		if(!objectp(room)){
			room = load_object(AREA_QINGPING"forest4");
		}
		me->move(room);
	} else if(jian = present("jian er", this_object())){
		message_vision("$N喝道：“你鬼鬼祟祟的在干什么？”\n", jian);
	} else {
		tell_object(me, "你左推右推也不得法，山石纹丝不动。\n");
	}
	return 1;
}
