inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>
int lu_disappear(object lu);

void create()

{
        set("short", "小桥");
        set("long", @LONG
乳白色的晨雾渐渐在山林间、泉水上升起又渐渐一缕缕随风飘靛飘散到远方。
小桥旁的屋子里正有几个人走出来手揽着身旁少女的腰，边打着呵欠，边讨论着方
才的战局。在这里你不但可以买得到最醇的酒最好的女人，还可以买到连你自己都
认为永远无法实现的梦想。只要你够慷慨，在这里你甚至可以买别人的命。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"bigtree",
		"west":  __DIR__"happywood",
		"east":  __DIR__"happyroom",
	]));
        set("objects", ([
        	__DIR__"npc/huhua": 1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1670);
        set("coor/y",610);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("east","door","铁门","west",DOOR_CLOSED);

}


void reset() {
	int dayTime;
	mixed *local;
	object lu;
	
	:: reset();
	local = NATURE_D->get_current_time();
	dayTime = local[5];
	if(dayTime > 240 && dayTime < 900) {
		call_out("do_reveal",2);
	}

}

int do_reveal() {
	object lu,qin;
	object *inv, *players;
	int i;
	
	message("vision",CYN"\n有个人从高老大的屋子里走出来，走上了小桥。\n"NOR,this_object());
	lu=new(__DIR__"npc/lumantian2");
	lu->move(this_object());
	qin=present("qin huhua",this_object());
	if (qin && !userp(qin) && !qin->is_fighting()) 
		message("vision",CYN"
秦护花的笑声突然间停顿了，脸上的神色立刻变得很恭谨，闪身在桥畔躬身行
礼。这人只点了点头，随意寒喧了两句。\n\n"NOR,this_object());
	call_out("lu_disappear",10,lu);
	return 1;
}


int 	lu_disappear(object lu) {
	
	
	if (!lu) return 1;
	if (lu->is_fighting()) {
		call_out("lu_disappear",lu,10);
		return 1;
	}
	message_vision(CYN"$N大步走出了快活林。\n"NOR,lu);
	destruct(lu);
	return 1;
}