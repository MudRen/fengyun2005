#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","东次间");
  set("long",@LONG
天贶殿大殿内，东、西、北三面的墙壁上，彩绘有《泰山神启跸回銮图》。图
以后门为界，东为“启跸”，西为“回銮”。东次间有明代铜铸“照妖宝境”一架，
直径逾三尺，原是遥参亭中碧霞元君神像后的供物。
LONG
  );
  	set("exits",([
        	 "west":__DIR__"tiankuang",
        ]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object ob;
	add_action("do_say","say");
}

int do_say(string arg)
{
	object me = this_player(),room;
	if (arg != "众生云云难貌相，海水滔滔难斗量")
		return 0;
	if (REWARD_D->riddle_check(me,"探流追源") < 8 && !REWARD_D->check_m_success(me,"探流追源"))
		return 0;
	message_vision(CYN"照妖镜里突发异光，一片青芒转眼间将东次间笼罩。\n"NOR,me);
	me->add_temp("block_msg/all",1);
	if (!room = find_object(__DIR__"maze_enter"))
		room = load_object(__DIR__"maze_enter");
	me->move(room);
	me->add_temp("block_msg/all",-1);
	tell_room(this_object(),CYN"待到光华渐渐退去，你忽然发觉身边少了一人。\n"NOR);
	tell_object(me,CYN"眼前青色的光芒渐渐退去，你发现自己已不在东次间中。\n"NOR);
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

