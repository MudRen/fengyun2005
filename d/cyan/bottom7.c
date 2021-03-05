// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", HIG"扶桑古木"NOR);
    set("long", @LONG
走进山谷，你忍不住屏住呼吸，只因面前那一株参天大树。树的根部竟
似有半个济南城大小，占满了上百坪泥土，仰头而望，只见枝叶虬结，密密
地覆满了整片天穹，整个冠盖似乎向着你压了下来，压住了你的呼吸，时间
仿佛也在这一刹静止，天地之间所剩下的，只有这一株巍巍古木。
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/treeoftales":1,

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"root":"你注意到一条向你延展而来的树根上有一扇小小的门。\n",
	"根部":"你注意到一条向你延展而来的树根上有一扇小小的门。\n",
	"树的根部":"你注意到一条向你延展而来的树根上有一扇小小的门。\n",
	"树根":"你注意到一条向你延展而来的树根上有一扇小小的门。\n",	

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"树影":	"黑漆漆的，什么也看不清楚。\n",

	]) );
	set("exits",([
  		"west" : __DIR__"bottom6",
  		"enter" : __DIR__"bottom19",
	]) );

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
    create_door("enter","door","小小的门","out",DOOR_CLOSED);
}
void init()
{
	add_action("do_search", ({"search"}));
	add_action("do_look", ({"look"}));
}

void aaa(object me,object room)
{
	if (!me)	return;
	if (environment(me) != room)
		return ;
	if (me->query_temp("annie/emeraldx") != 99)
		return ;
	if (REWARD_D->riddle_check(me,"天灵翡翠") != 1)
		return ;

	me->set_temp("annie/emeraldx",0);
	tell_object(me,HIG"\n你不甘心地低头又望了那株小草一眼，突然发现小草附近有被碾压过的痕迹。\n"NOR);
	tell_object(me,HIW"似乎有什么东西曾经落在这里．．．．\n\n"NOR);
	
	REWARD_D->riddle_set(me,"天灵翡翠",2);
	return;
}

int do_search(string arg)
{
	object me = this_player(),he;
	object room,item;
	room=find_object(__DIR__"bottom20");
	if (!room)
		room=load_object(__DIR__"bottom20");
	
	me->set_temp("annie/emeraldx",0);

	if (me->is_busy() || me->is_fighting())
	{
		write("你现在正忙。\n");
		return 1;
	}

	message_vision("$N在扶桑古木虬结的根系中行走搜寻．．．\n",me);

	if (room->usr_in() || random(3) || REWARD_D->riddle_check(me,"天灵翡翠") != 1)
		tell_object(me,"你越过了大半个根部，却什么都没有找到。\n");
	else
	{

		if (me->query("annie/gstone") == 1)
		{
			if (!me->query_temp("marks/bottom7_warning")) {
				me->set_temp("marks/bottom7_warning",1);
				tell_object(me,HIG"\n草丛中忽然有绿光一闪，你蹲下身看去。\n\n"NOR);
				tell_object(me,CYN"五十六，你有五十六么？\n"NOR);
				tell_object(me,HIB"树影中有人阴阴地哼了一声，你浑身起了一阵鸡皮疙瘩，只觉得杀意凛人。。。\n"NOR);
				me->perform_busy(1);
				return 1;
			}
			me->delete_temp("marks/bottom7_warning");					
			tell_object(me,HIB"密密的杂草下透出绿色，你伸手去拨，却突然觉得一阵眩晕．．．\n\n"NOR);
			me->move(room);
			if (!present("fiftysix",room))
			{
				he=new(__DIR__"npc/devil");
				if ( me->query("combat_exp")>= 2100000) {
					he->set("combat_exp", me->query("combat_exp"));
					"/feature/nada"->reset_npc(he);
					he->set_skill("feixian-sword",he->query_skill("feixian-sword",1)
						+ F_LEVEL->get_level(he->query("combat_exp"))/6);
					he->set_skill("feixian-steps",he->query_skill("feixian-steps",1)
						+ F_LEVEL->get_level(he->query("combat_exp"))/6);	
				}										
				he->full_me();
				he->move(room);
			}
			me->perform_busy(1);
			return 1;
		}

		tell_object(me,HIG"\n草丛中忽然有绿光一闪，你蹲下身看去。\n"NOR);
		tell_object(me,HIG"然而那只是一株小草，露出土外的茎秆已经断成了两截．．．\n\n"NOR);
		me->set_temp("annie/emeraldx",99);
		call_out("aaa",12,me,this_object());
	}

	me->perform_busy(2);
	return 1;
}

int do_look(string arg){
	
	object me = this_player();
	if (REWARD_D->riddle_check(me,"天灵翡翠")!=2)	return 0;
	if (arg != "grass" && arg!="小草" && arg!="草") return 0;
		me->set_temp("annie/emeraldx",0);
	tell_object(me,HIG"\n你不甘心地低头又望了那株小草一眼，突然发现小草附近有被碾压过的痕迹。\n"NOR);
	tell_object(me,HIW"似乎有什么东西曾经落在这里．．．．\n\n"NOR);
	
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


