inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菊花园西");
        set("long", @LONG
菊花园很大，菊花园旁是梅花园还有牡丹，蔷薇．芍药，茶花，甚至还有竹园。
所有的花园密密相接谁也不知道究竟占了多少地，只知道一个人就走得很快也难在
一天内绕着这片地走一圈。花园里很静，没有人，没有声音。老伯的花园一向都是
这样子的，但你只要一走进去，每个角落里都可能有人忽然出现，每个人都可能要
你的命。
LONG
        );
        set("exits", ([ 
		"northeast" :  	__DIR__"garden2",
		"west":		__DIR__"stable",
		"northwest":	__DIR__"sroad1",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
    	]));
		
	set("outdoors", "zangbei");
        set("coor/x",-1340);
        set("coor/y",950);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_pull","pull");
	add_action("do_look","look");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"园子里的菊花长得郁郁葱葱，恐怕搜一天都不会有结果。\n");
	return 1;
}

int do_look(string arg){

	object me = this_player();
		
	if (!arg || (arg!="菊花" && arg!="flower"))	return 0;
	
	if (REWARD_D->riddle_check(me,"菊园传奇")!=3)	{
		tell_object(me,"正当秋季，院子里的菊花有半人多高，绚烂多彩。\n");
		return 1;
	}
	
	tell_object(me,"正当秋季，院子里的菊花有半人多高，把地面遮住了许多。\n");
	return 1;
}

void reset() {
	int dayTime;
	mixed *local;
	object xiaohe;
	
	:: reset();
	if (xiaohe=present("xiao he",this_object()))
	if (!xiaohe->is_fighting()) {
		destruct(xiaohe);
		set("xiaohe",1);
		return;
	}
	
	local = NATURE_D->get_current_time();
	dayTime = local[5];
	if(dayTime > 0 && dayTime < 360) {
		call_out("do_reveal",2);
	}
	return;
}

int do_reveal() {
	
	object *inv, *players;
	int i;
	
	message("vision",BLU"\n风吹草动，园子里似乎有一个黑影闪过，一晃就消失在菊花丛里了。\n\n"NOR,this_object());
	
	inv = all_inventory();
    	players = filter_array(inv, (: interactive($1) :));
	for(i=0; i<sizeof(players); i++) {
		if (REWARD_D->riddle_check(players[i],"菊园传奇")==2)
			REWARD_D->riddle_set(players[i],"菊园传奇",3);
//		if (!players[i]->query("marks/kuaihuo/夜见黑影")) 
//			players[i]->set("marks/kuaihuo/夜见黑影", 1);
	}
	set("xiaohe",1);
	return 1;
}


int do_pull(string arg) {
	object me=this_player();
	object xiaohe;
	
	if (arg== "flower" || arg == "菊花") {
		tell_object(me,YEL"你蹲下去伸手拔起一株菊花。这株菊花竟是活的．被你一拔，就连根而起。
下面竟有个小小的洞穴。"NOR);
		
		if (REWARD_D->riddle_check(me,"菊园传奇")!=3 || !query("xiaohe")) {
//		if (!me->query("marks/kuaihuo/夜见黑影") || !query("xiaohe")) {
			tell_object(me,WHT"洞穴里空空的，什么也没有。\n"NOR);
			return 1;
		}
		message("vision","从地底下忽然无声无息地冒出一个人来。\n",this_object(),me);
		tell_object(me,BLU"一个穿着黑衣的人从洞穴里一跃而起向你扑来。\n"NOR);
		xiaohe=new(__DIR__"npc/xiaohe");
		xiaohe->move(this_object());
		xiaohe->kill_ob(this_player());
		set("xiaohe",0);
		return 1;
	}
	return notify_fail("你想拔/拉什么？\n");
}

