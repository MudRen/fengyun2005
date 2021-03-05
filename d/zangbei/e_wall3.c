inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "东寨墙");
        set("long", @LONG
寨墙是照箭楼的格式修筑的，一、二两层都有箭眼，三层只有一半墙壁，从上
半段也可露出头来向外射箭。若是有人来攻，寨里的人站在墙上向下射箭。居高临
下，十分得手。寨墙外面是茂密的森林，寨墙里面可以看到一个大院，院子的四周
有几间瓦房。靠墙有一把长梯供人上下。
LONG
        );
        set("exits", ([ 
		"northwest":	__DIR__"e_wall2",
	]));
        set("item_desc", ([
        	"ladder": "一把长梯从寨墙上通向大院，你可以爬下去（climb down），
不过，若是在梯子上遭到敌人攻击，恐怕会吃大亏。\n",
        	"长梯":	 "一把长梯从寨墙上通向大院，你可以爬下去（climb down），
不过，若是在梯子上遭到敌人攻击，恐怕会吃大亏。\n",        
        ]));
        
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1480);
        set("coor/y",580);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}


void init() {
	add_action("do_climb","climb");	
	add_action("do_yell","yell");
	 if(interactive(this_player()))
    {
         remove_call_out("do_hints");
         call_out("do_hints",random(10)+10,this_player());
    }
}

int do_hints(object me)
{
    if (! me || environment(me)!=this_object())	return 1;
    message_vision(WHT"墙下传来吆喝声：寨上的兄弟小心了，若有敌来犯，速速呼叫（yell）寨主！！！\n"NOR,me);
    return 1;
}


int do_yell(string arg){
	object me, boss, room;
	string *boss_name=({"baimian langzhong","tu laohu","one eye"});
	string boss1;
	int i,num;
	string file;
	
	me = this_player();
	room = this_object();
	
	if (present(boss_name[0],room) || present(boss_name[1],room)
			|| present(boss_name[2],room)) {
		tell_object(me,"还是先把眼前的强盗解决了再说吧。\n");
		return 1;
	}
	
	if (!arg || (arg!="大王" && arg!="二大王" && arg!="三大王")) {
		tell_object(me,"你想叫哪个大王？（大王、二大王、三大王）\n");
		return 1;
	}
		
	message_vision(YEL"$N学着山寨喽罗的腔调大叫道：风紧、风紧、"+arg+"快来啊！！！\n"NOR, me);

	switch (arg) {
		case "大王": 	boss1 = "one eye"; break;
		case "二大王":  boss1 = "baimian langzhong"; break;
		default:		boss1 = "tu laohu";
	}
	
	boss=find_real_living(boss1);
/*	if (boss) {
		write("boss is " + file_name(boss)+"\n");
		if (sscanf(file_name(boss),"%s#%d",file, num)!=2)	write ("bad boss is" + living(boss) + "\n");
	}*/
	if (boss && !boss->is_fighting()) {
		boss->command("say 他奶奶的，又有人来捣乱！");
		boss->move(room);
		boss->start_busy(2);
		message_vision(CYN"寨墙下一阵骚动声，一个脑袋从梯子上冒了出来。
$N说，什么人敢到龙虎寨来捣乱，让我把他的脑袋拧下来斟酒！！！\n"NOR,boss);
		boss->kill_ob(me);
		me->kill_ob(boss);
		return 1;
	}
		
	tell_object(me,"许久许久，寨中什么动静也没有。\n");
	return 1;		
}	

void reset() {
	object *inv, room;
	int i;
	
	::reset();
	inv=all_inventory();
	
	for (i =0; i<sizeof(inv); i++) {
		if (inv[i]->query("longhu_boss") 
			&& !inv[i]->is_fighting()) {
			inv[i]->ccommand("say 孩儿们好好看守山寨，我去歇息一阵！");
			room=find_object(AREA_ZANGBEI"village");
			inv[i]->move(room);
			message_vision("$N从山寨外面走了进来。\n",inv[i]);
		}		
	}		
}			
	
int do_climb(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="down" || arg == "ladder" || arg== "长梯") {
		if (me->query_temp("zangbei/zaiqiang_1"))
			return notify_fail("你已经在梯子中央了。\n");
		message_vision("$N把着长梯小心翼翼地向下爬去。\n\n",me);
		call_out("pass_river",4,me);
		me->start_busy(6);
		me->set_temp("zangbei/zaiqiang_1",1);
		return 1;
	}
	tell_object(me,"你要爬什么？\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"village");
	if (!objectp(room)) room=load_object(__DIR__"village");
	tell_object(me,"你轻巧地下到院子里。\n");
	message("vision",me->name()+"从梯子上爬了下来。\n",room);
	me->move(room);
	me->delete_temp("zangbei/zaiqiang_1");
	return 1;
}

