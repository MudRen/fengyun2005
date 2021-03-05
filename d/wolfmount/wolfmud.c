#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "泥沼");

	set("long", @LONG
万丈绝壑下，是一片无边无际的沼泽，没有树木、没有花草、没有生命！有的
只是湿泥、臭水、正在腐烂的枯木败草和迷雾般的沼气。泥沼浓而粘，有种奇怪的
张力，所以从万丈深渊掉下来也没有完全陷落泥底。       
LONG);	
	set("no_dazuo",1);
       set("outdoors", "wolfmount");
	set("no_magic",1);
	set("type","mud");
	set("item_desc", ([
                "枯木": "漂浮在泥沼中的枯木，身处险境的人能抓住（ＧＲＡＳＰ）点东西就等于抓住希望。\n",
 		"tree": "漂浮在泥沼中的枯木，身处险境的人能抓住（ＧＲＡＳＰ）点东西就等于抓住希望。\n",
 		"wood": "漂浮在泥沼中的枯木，身处险境的人能抓住（ＧＲＡＳＰ）点东西就等于抓住希望。\n",
 		"枯木败草": "漂浮在泥沼中的枯木，身处险境的人能抓住（ＧＲＡＳＰ）点东西就等于抓住希望。\n",
        ]) );
	set("coor/x",80);
	set("coor/y",10);
	set("coor/z",-60);
	setup();
}

void init()
{
	add_action("do_grasp", "grasp");
	if(interactive(this_player()))
	call_out("do_moving",180,this_player());
}

void do_moving(object me)
{
	object room;

	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"\n泥沼缓缓地流动着，不知不觉中，你随着泥沼缓缓地漂移着。！\n\n");
	room = find_object(__DIR__"wolfmud1");
	if(!objectp(room)) room= load_object(__DIR__"wolfmud1");
	me->move(room);
}

int do_grasp(string arg)
{
	object me/*, room*/;
	int sen;

	me = this_player();
	sen =(int) (me->query("max_sen")/3);

	if(!arg || (arg != "枯木" && arg !="tree" && arg!= "wood" ) ) 
	{
		write("你要抓什么？\n");
		return 1;
	}
	switch (random(3)) 
	{
		case 0:
			tell_object(me,"你伸手抓向泥沼中的枯木，但是手一滑，没有抓住。\n");
			break;
		case 1:
			tell_object(me,RED "你颤抖着将手伸向枯木，突然你感觉到有什么东西在你手上一口。\n"NOR);
			message_vision(YEL "$N突然发出一声惊叫，身子又向下陷落一些。\n"NOR, me);
			me->receive_damage("kee",50);
			me->set_temp("last_damage_from","在泥沼里窒息而死了。\n");
			break;
		case 2:
			tell_object(me, RED"你用尽吃奶的力气抓住枯木，泥沼似乎有种可怕的力量拉扯着你......\n"NOR );
			tell_object(me,YEL"你想叫但叫不出声......你开始往下一点点陷落......。\n"NOR);
			message("vision", "你只见"+me->name()+"抓着枯木开始往下一点点陷落。\n" , environment(me),me);
			me->receive_damage("sen",sen);
			me->set_temp("last_damage_from","在泥沼里窒息而死了。\n");
			break;
	}
	return 1;
}