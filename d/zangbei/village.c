inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "龙虎寨大院");
        set("long", @LONG
龙虎寨就在密林后，四面群山环抱，奇峰矗立，看来就像是一只野兽，正张大
了嘴在等着择人而噬。住在这里的人，也正像是一群野兽。谁也不愿意被野兽吞下
去，所以这地方非但很少看得见陌生人，连飞鸟都已几乎绝迹。不过，强盗们在这
儿却是如鱼得水，欢天喜地，不大的山寨里西面是谷仓，东面是武库，中间一个大
院是头领们召集手下的所在。大院的一侧还有张长梯，通往寨墙，一有风吹草动，
山寨里的人就会冲上墙头防守。
LONG
        );
        set("exits", ([ 
//		"west" : __DIR__"v_barn",
		"east" : __DIR__"v_armory",
		"north": __DIR__"v_gate",
	]));
        set("objects", ([
        	__DIR__"npc/baimian":	1,
        	__DIR__"npc/tulaohu":	1,
        	__DIR__"npc/oneeye":	1,
        	__DIR__"npc/bandit1":   6,
	]) );
	set("item_desc",([
		"barn":	"一扇木门通向谷仓。\n",
		"谷仓": "一扇木门通向谷仓。\n",
		"ladder":"东墙下，一张长梯把院子和寨墙连接起来。\n",
		"长梯": "东墙下，一张长梯把院子和寨墙连接起来。\n",
	]));
	
	set("outdoors", "zangbei");
        set("coor/x",-1540);
        set("coor/y",560);
        set("coor/z",0);
	set("map","zbwest");
        set("closed",1);
	setup();
//	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}

void init() {
	add_action("do_climb","climb");
	add_action("do_open","open");
}


int do_climb(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="up" || arg == "ladder" || arg== "长梯") {
		if (me->query_temp("zangbei/zaiqiang_2"))
			return notify_fail("你已经在梯子中央了。\n");
		message_vision("$N把着长梯小心翼翼地向上爬去。\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/zaiqiang_2",1);
		return 1;
	}
	tell_object(me,"你要爬什么？\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"e_wall3");
	if (!objectp(room)) room=load_object(__DIR__"e_wall3");
	tell_object(me,"你轻巧地上到寨墙上。\n");
	message("vision",me->name()+"从梯子上爬了上来。\n",room);
	me->move(room);
	me->delete_temp("zangbei/zaiqiang_2");
	return 1;
}


int do_open(string arg) {
	object me=this_player();
	object out_room;
	if (!arg || (arg!="door" && arg!="木门" && arg !="门"))
		return notify_fail("你要打开什么？\n");
	if (!query("closed"))
		return notify_fail("门已经是开着的了。\n");
	message_vision("$N把谷仓的门打开。\n",me);
	set("exits/west",__DIR__"v_barn");	
	set("closed",0);
	out_room=find_object(__DIR__"v_barn");
	if (!objectp(out_room)) out_room=load_object(__DIR__"v_barn");
	message("vision","谷仓的门忽然从外面被打开了。\n",out_room);
	out_room->set("exits/east",__DIR__"village");
	call_out("door_close",20,out_room);
	return 1;
}
	
int door_close(object out_room){
	out_room->delete("exits/east");
	this_object()->delete("exits/west");
	this_object()->set("close",1);
	message("vision","谷仓的门又被关上了。\n",this_object());
	message("vision","木门荡了回来关上了。\n",out_room);
	set("closed",1);
	return 1;
}
/*
void reset() {
	object badguy,*inv,room=this_object();
	int count,i;
	
	::reset();
	
	inv=all_inventory();
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->name()=="山寨喽罗")
			count++;
	}
	if (count<4) {
		badguy=new(__DIR__"npc/bandit");
		badguy->set("attitude", "friendly");
		badguy->move(room);
		badguy->ccommand("say 大王,小的准备好了。");
	}
}
	
*/

/* 
void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(5);
	
	if(!random(10)) {
		for(i=0; i<bandit_no; i++) {
			if(objectp(badguy = new("/obj/npc/bandit"))) {
				badguy->setup_bandit("山西土匪", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "fy");
				badguy->move(room);
				badguy->ccommand("chat 月黑杀人，风高放火！");
			}
		}
		NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
	object *ob_list;
	int i;
	
	ob_list = children("/obj/npc/bandit");
	for(i=0; i<sizeof(ob_list); i++) {
		if(ob_list[i]->query("area_mark") == "fy") {
			if(environment(ob_list[i])) {
				message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
			}
			destruct(ob_list[i]);
		}
	}
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
*/