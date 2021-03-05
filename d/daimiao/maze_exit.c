#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","镜中世界");
  set("long",@LONG
这是个镜子的世界。游目四望，不论是东南西北，抑或是天顶脚下，无处不覆
盖着明亮光洁的盈盈镜面。层层叠叠无数个的映像正在镜中满脸仓皇的与你对视，
看着环绕在周围的再熟悉不过的人影，一丝恐惧爬上了你的心头。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"maze_ns",
        	 "south":__DIR__"maze_ns",
        ]));
	set("coor/x",99);
	set("coor/y",99);
	set("coor/z",0);
	set("no_fly",1);
		set("item_desc", ([
		"west":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"north":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"east":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"south":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
	]) );
	setup();
}

void init()
{
	if(userp(this_player()))
	{
		remove_call_out("attack");
		call_out("attack",3+random(3),this_player());
	}
	add_action("do_say","listen");
	add_action("do_push","push");
}


int do_push(string arg)
{
	object me = this_player(),room;
	mapping data;
	
	if (REWARD_D->riddle_check(me,"探流追源") != 10 
		&& !REWARD_D->check_m_success(me,"探流追源"))
		return 0;
	if (!arg)
		return 0;
	if (arg != "mirror" && arg != "镜壁" && arg != "镜面")
		return 0;
	message_vision("$N伸手推了推镜面。\n",me);
	if (me->query_str() < 60)
		return notify_fail("可是镜面纹风不动．．．你是不是太多疑了？\n");
	message_vision("镜面突然一转，$N猝不及防，整个人跌进镜中。\n",me);
	if (!room = find_object(__DIR__"maze_room"))
		room = load_object(__DIR__"maze_room");
	me->move(room);
	tell_room(this_object(),"镜面飞快的合回原位，仿佛什么也没有发生。\n"NOR);

	REWARD_D->riddle_done(me,"探流追源",100,1);
	
	    data = ([
			"name":		"探流追源",
			"target":	me,
			"att_1":	"int",
			"att_1c":	1,
			"mark":		1,
		]);
	
		REWARD_D->imbue_att(data);	
	
	return 1;

}

int do_say(string arg)
{
	object me = this_player(),room;
	if (REWARD_D->riddle_check(me,"探流追源") != 9 && !REWARD_D->check_m_success(me,"探流追源"))
		return 0;
	me->set_temp("annie/demon_feng",0);
	tell_object(me,CYN"你将耳朵贴到镜面上，隐隐约约听到那面有两个人对话之声。\n"NOR);
	me->start_busy(12);
	call_out("do_ggyy",1,this_object(),me,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item;
	string msg;
	string *event_msg = ({
"\n一个油腔滑调的声音响了起来，你只觉似曾相识，一时间却又想不起在哪里听过。",
"只听那声音道：凤大人，奴才已经将那人骗来此地，算算时间，也差不多该嗝屁了。",
"另一个温厚的声音说道：作得不错，如此我教一统天下之际，就又少掉一个阻碍。",
"先前的声音干笑几声，应道：这都仰赖凤大人神机妙算，智．．智那个什么无边。",
"后一人略带讥诮的道：不用废话，下去罢，去银先生那里取了这次的报酬，你就可以滚了。",
"一阵悉悉索索的声音传来，四下里又归于寂静无声。",
});
	if (!me || !target)
		return;
	if (me != environment(target) || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{

		if(REWARD_D->riddle_check(target,"探流追源") == 9)
			REWARD_D->riddle_set(target,"探流追源",10);

		tell_object(target,HIB"\n贴耳的镜面忽然微微一震，你心下一动：莫非这镜壁可以推开？\n"NOR);
		return;
	}
	return;
}

int attack(object ob)
{
	int i;
	int damage;
	object room;
	if( environment(ob) == this_object() && REWARD_D->riddle_check(ob,"探流追源") == 8)
	{
		tell_object(ob,CYN"\n你突然听到一阵窃窃私语之声从镜面回廊里传来．．．\n"NOR);
		REWARD_D->riddle_set(ob,"探流追源",9);
		return 1;
	}
	else
		return 1;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

