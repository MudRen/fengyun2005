#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "山崖下");
        set("long", @LONG
你跃下深谷，游目四顾，只见谷底繁花青草，便如同一个不大的花园，幽径环
绕，花香扑鼻，竟是别有洞天。然而花影不动，幽谷无人，只有数十丈外，一道碧
绿色的玉门守着空山鸟语，另一边的两扇黑铁门却是关得严严实实，滴水不入。
LONG
        );
	set("no_fly",1);
	set("no_fight",1);
	set("no_magic",1);
	set("exits",([
  		"north" : __DIR__"hall",
  		"south" : __DIR__"hall",
	]) );
    create_door("north","door", "黑铁门", "south", DOOR_CLOSED);
	set("item_desc", ([
		"north": "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"黑铁门": "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"铁门": "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"irongate": "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"iron gate": "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"玉门": "绿玉门此刻正半掩着，想是方才水如昔打开。\n",
		"jadegate": "绿玉门此刻正半掩着，想是方才水如昔打开。\n",
		"south": "绿玉门此刻正半掩着，想是方才水如昔打开。\n",
		"jade gate": "绿玉门此刻正半掩着，想是方才水如昔打开。\n",
		"gate": "绿玉门此刻正半掩着，想是方才水如昔打开，而两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"门": "绿玉门此刻正半掩着，想是方才水如昔打开，而两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n",
		"花": "这是一种你没有见过的淡蓝色小花，阵阵异香扑鼻而来(smell)。\n",
		"繁花": "这是一种你没有见过的淡蓝色小花，阵阵异香扑鼻而来(smell)。\n",
		"flower": "这是一种你没有见过的淡蓝色小花，阵阵异香扑鼻而来(smell)。\n",
	]) );

	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_swing","smell");
	add_action("do_open","open");
}

int do_open(string arg){
	object me, ob, room;
	
	me = this_player();
	if(!arg || arg != "黑铁门" && arg != "铁门" && arg != "door" && arg != "gate"){
		return 0;
	} 
	tell_object(me, "两扇黑铁门关得严严实实，门上一丝缝隙也没有。\n你根本无从下手打开．．．\n", me);
	return 1;
}

int do_swing(string arg)
{
	object me = this_player(),env=this_object();
	int gin,kee,sen;
	mapping buff;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙。\n");
	message_vision("$N弯下身去，闻了闻淡蓝色的小花．．．\n",me);
	tell_object(me,HIB"你只觉得一阵头晕目眩，站立不稳。\n"NOR);

		  gin = me->query("max_gin");
		  me->set("effgin", gin);
		  me->set("gin", gin);
		  kee = me->query("max_kee");
		  me->set("effkee", kee);
		  me->set("kee", kee);
		  sen = me->query("max_sen");
		  me->set("effsen", sen);
		  me->set("sen", sen);

		tell_object(me,HIR "\n你的眼前一黑，接著什麽也不知道了....\n\n" NOR);
			me->add_temp("block_msg/all",1);

			buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"bless",
				"name":"巴山最终战·返魂花",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":HIR " <昏迷不醒>"NOR,
				"time":20+random(20),
				"buff_msg":"\n$N脚下一个不稳，跌在地上一动也不动了。\n\n"NOR,
//				"disa_msg":HIY "\n慢慢地你终於又有了知觉....\n\n" NOR,
				"disa_msg":"\n$N慢慢睁开眼睛，清醒了过来。\n\n",
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
			me->add_temp("block_msg/all",-1);
		return 1;
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
