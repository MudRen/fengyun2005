inherit ROOM;
#include <ansi.h>

string gate();
void self_heal();

void create()

{
        set("short", "龙虎寨");
        set("long", @LONG
密林后竟然是一座山寨，依山势而建，地势险峻。正中是两扇巨大的木门，木
门上的柱子每根都有一尺方圆，外侧包有铜皮。寨门两侧是高耸的寨墙，两人多高
的寨墙上每过十数尺就是一个箭楼，箭楼分三层，每层皆有射孔，孔中隐约可看见
蓝崭崭的箭矢。这强人聚集的龙虎寨，端得是个易守难攻之势，难怪官兵数次围剿
都铩羽而归。
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest4",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"gate": (: gate() :),
		"door": (: gate() :),
		"木门": (: gate() :),
		"寨门": (: gate() :),
	]));
	set("outdoors", "zangbei");
        set("total",100);
        set("coor/x",-1540);
        set("coor/y",600);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

void 	init(){

	add_action("do_ram","ram");	
	if (query("total")<100) call_out("self_heal",10);

}

void 	reset(){
	::reset();
	delete("exits/south");
}

string gate() {
	int integrity;
	string msg;	
	integrity=query("total");
	msg="两扇巨大的木门，外侧包有铜皮。";
	if (integrity<1) msg +="门已经被撞开了。\n";
		else {
			msg +="门的坚实度现在是"+(string)integrity+"％。\n";
			msg +="看来闯进去的唯一办法就是把门撞开了（ｒａｍ）。\n";
		}
	return msg;
}


int 	arrow_out(object me) {
	
	string *rooms = ({__DIR__"e_wall1",__DIR__"e_wall2",__DIR__"e_wall3",__DIR__"w_wall1",
		__DIR__"w_wall2",__DIR__"w_wall3"});
	int i;
	object archer_room,g_room,archer;
	
	message_vision(WHT"寨墙上一个声音冷冷地说道：“放箭！！！”\n"NOR,me);
	for (i=0;i<sizeof(rooms);i++){
		archer_room=find_object(rooms[i]);
		if (!objectp(archer_room)) archer_room=load_object(rooms[i]);
		if (!archer=present("archer",archer_room)) continue;
		message_vision(HIR"只听嗖嗖风声，一支利箭向$N当心射到！！！\n"NOR,me);
		if (random(me->query_skill("perception",1)) < 100)
			me->receive_wound("kee",random(me->query("max_kee")/10),archer);
		message_vision(HIR"只听嗖嗖风声，一支利箭向$N当心射到！！！\n"NOR,me);
		if (random(me->query_skill("perception",1)) < 100)
			me->receive_wound("kee",random(me->query("max_kee")/10),archer);
	}
	 COMBAT_D->report_status(me);
}		
		

	

int	do_ram(){
	object me=this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	if (me->query("str")<30)
		return notify_fail("你的力气太小，不可能撞开寨门，看来只能另想办法了。\n");
	if (!present("stump",me))
		return notify_fail("你没有可以用来撞门的器具。\n");
			
	message_vision(YEL"$N用尽全身之力，举起手中的树桩向寨门撞去。\n"NOR,me);
	me->start_busy(3);
	add("total",-2);
	if (query("total")>0) {
		message_vision(YEL"只听寨门轰轰作响，似乎松动了些。\n\n"NOR,me);
		call_out("arrow_out",2,this_player());
	}	else {
			message_vision(WHT"轰隆一声巨响，烟尘冲天，寨门倒了下去。\n\n"NOR,me);
			set("exits/south",__DIR__"village");
		}
	if (remove_call_out("self_heal")==-1) call_out("self_heal",10);
	return 1;
}
	

	
void self_heal() {
	if (query("total")<0) set("total",0);
	if (query("exits/south")) delete("exits/south");
	if (query("total")<95 && query("total")>=0) {
		add("total",5);
		call_out("self_heal",10);
	}
}

