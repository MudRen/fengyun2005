#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "荒野");
        set("long", @LONG
再往南又是荒野了，李大娘的庄园就在镇边。太平镇八十三户人家，一半是武
镇山武三爷的，另一半就是这李大娘的。没有人知道大娘真名叫什么，也没人知道
她的来历，只知道她三年前买下了这座庄园。李家庄两边是三丈高墙，墙上倒插着
锋刃。西墙有扇铁门，门上挂着一把已经锈了一半的铜锁。
LONG
        );
        set("exits", ([ 
		"northwest": __DIR__"mroad8",
		"west": __DIR__"swamp1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door": "一扇铁门，门上挂着一把已经绣了一半的铜锁。\n",
		"铁门": "一扇铁门，门上挂着一把已经绣了一半的铜锁。\n",
		"铜锁": "这把锁很奇怪，没有锁孔，只有一个小小的转盘。\n",  
		"lock": "这把锁很奇怪，没有锁孔，只有一个小小的转盘。\n",  
		"转盘": "这个转盘也许是开门的机关？你可以转转看。\n",
		
	]));
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init() {
	add_action("do_turn","turn");
	add_action("do_open","open");
}

int do_open(string arg) {
	if (arg=="door" || arg =="铁门" || arg=="门"){
		tell_object(this_object(),"你推了推门，一点动静没有。\n");
		return 1;
	}
	return 0;	
}

int do_turn(string arg){
	object me,room, paper;
	me=this_player();
	
	if (arg=="转盘" || arg == "lock" || arg == "铜锁") {
		if (!REWARD_D->check_m_success(me,"喋血李家庄")) {
			message_vision("$N拿着铜锁左转右转，一点动静没有，许是没找到窍门。\n",me);
			if (REWARD_D->riddle_check(me,"喋血鹦鹉")==7)	{
				REWARD_D->riddle_set(me,"喋血鹦鹉",8);
				tell_object(me,BLU"忽然一个黑影从你身边掠过，你急转身，却只有风声簌簌。\n"NOR);
				tell_object(me,BLU"一张小纸片忽悠忽悠地飘在你肩上。\n"NOR);
				paper= new(__DIR__"obj/paper");
				if (!paper->move(me))
					paper->move(environment(me));
			}				
			
			return 1;
		}
		tell_object(me,"你拿着铜锁左三转，右五转，再左七转。\n");
		tell_object(me,"铁门没有开，你的脚下却开始摇晃起来。\n");
		message_vision(YEL"土地竟忽然裂了开来，露出了个地洞。$N一个跟斗栽进了洞里。\n"NOR,me);
		room = find_object(__DIR__"pond");
        	if(!objectp(room))
                 	room = load_object(__DIR__"pond");
        	me->move(room);
        	return 1;
	}
	return 0;
}