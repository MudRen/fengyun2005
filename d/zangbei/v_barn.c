inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "谷仓");
        set("long", @LONG
各式各样的谷物，把一个偌大的谷仓挤得满满的，东墙一座壁炉上布满了尘灰，
砖瓦砌就的烟囱通向房顶。装着谷物的麻袋上打着不同的商行印记，显然是龙虎寨
的强人们下山打劫的收获，最近官兵剿匪的风声日紧，龙虎寨凭着这点储备，守上
个半年八载绝没有问题。通向大院的一扇木门紧紧关着。
LONG
        );
        set("exits", ([ 
//		"east" : __DIR__"village",
	]));
	set("item_desc", ([
        	"chimney": "这烟囱显然已经废弃多时了，看上去勉强可以钻进一个人（squeeze through）。\n",
        	"烟囱":	 "这烟囱显然已经废弃多时了，看上去勉强可以钻进一个人（squeeze through）。\n",
        	"木门":	 "这扇木门上了锁关着。\n",
        	"door":	 "这扇木门上了锁关着。\n",
        ]));
        set("objects", ([
        	__DIR__"obj/bag":	1,
	]) );
        set("coor/x",-1560);
        set("coor/y",560);
        set("coor/z",0);
	set("map","zbwest");
	set("closed",1);
	setup();
}

void init() {
	add_action("do_squeeze","squeeze");
	add_action("do_open","open");
}

int do_open(string arg) {
	object me=this_player();
	object out_room;
	if (!arg || (arg!="door" && arg!="木门" && arg !="门"))
		return notify_fail("你要打开什么？\n");
	if (!query("closed"))
		return notify_fail("门已经是开着的了。\n");
//	if (me->query_skill("stealing")<200)
//		return notify_fail("你的妙手空空之技太差，没法打开这扇门。\n");
	message_vision("$N捣鼓了一阵，从里面把门打开了。\n",me);
	set("exits/east",__DIR__"village");	
	set("closed",0);
	out_room=find_object(__DIR__"village");
	if (!objectp(out_room)) out_room=load_object(__DIR__"village");
	message("vision","谷仓的门忽然从里面被打开了。\n",out_room);
	out_room->set("exits/west",__DIR__"v_barn");
	call_out("door_close",20,out_room);
	return 1;
}
	
int door_close(object out_room){
	out_room->delete("exits/west");
	this_object()->delete("exits/east");
	this_object()->set("close",1);
	message("vision","谷仓的门又被关上了。\n",out_room);
	message("vision","木门荡了回来关上了。\n",this_object());
	set("closed",1);
	return 1;
}
	
int do_squeeze(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="through" || arg == "烟囱" || arg== "chimney" || arg =="through chimney") {
		if (me->query_temp("zangbei/chimney_2"))
			return notify_fail("你已经在烟囱里了。\n");
		message_vision("$N一猫腰挤进烟囱，小心翼翼地向上爬去。\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/chimney_2",2);
		return 1;
	}
	tell_object(me,"你要爬什么？\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"w_wall3");
	if (!objectp(room)) room=load_object(__DIR__"w_wall3");
	tell_object(me,"你费力地从烟囱里爬了出去。\n");
	message("vision",me->name()+"从烟囱里钻了出来。\n",room);
	me->move(room);
	me->delete_temp("zangbei/chimney_2");
	return 1;
}


void reset(){
	object bag,seed,*player,*inv;
	::reset();
	
	inv=all_inventory(this_object());
	player=filter_array(inv,(: userp($1) :));
	if (player && sizeof(player)) return;
	
	bag=present("big bag",this_object());
	if (bag)
		seed=present("seed",bag);
	if (!seed) {
		seed=new(__DIR__"obj/seed");
		seed->move(bag);
	}
	return;
}
	