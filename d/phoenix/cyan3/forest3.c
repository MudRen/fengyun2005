// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"黄树林"NOR);
    set("long", @LONG
挤出狭窄的山缝，迎接你的是一片奇特的树林。从未见过的各种参天巨木
如列阵般在黑软的淤泥上排布得井然有序，远远看去，犹如墨盘上还未动过的
木棋。仰头上望，但见覆满苍穹的木叶竟无一片苍碧，满满漾着浅浅的鹅黄，
枝条如镀金边，构筑为一种奇异诡谲的美丽。
    不知名的季节，微风。
    金色的光线从树顶中浅浅地透了下来。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path4",
  		"southdown" : "forest2",
  		"eastup" : "path5",
	]) );
	set("area","cyan3");

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",50);

	setup();
}



void init()
{
	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (REWARD_D->riddle_check(me,"天涯魂梦") ==1) 
	{
		ob=new(__DIR__"npc/li");
//		ob->move(this_object());
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy3",1,me,ob,0);

	}
	
	return;


}



int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir == "southdown")
		return notify_fail("时间快赶不上了，就别到处乱晃了吧？\n");

	return ::valid_leave(who,dir);
}







void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
CYN"你打量了这白衣剑客半晌，想起他干脆利落的一剑，心中暗自警觉，微笑道：多谢。"NOR,
CYN"李青卓＂嗯＂的一声，淡淡道：走。"NOR,
});

	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n\n"NOR,me,target);
	me->set_temp("disable_inputs",1);

	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy2",1,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		target->ccommand("follow mu seoguang");
		me->stop_busy();
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	object ob;
	string *event_msg = ({
WHT"你只听背后木叶一颤，剑气横空。\n不，不是剑。兵刃窄，长，微带弧度，单侧开锋，那是刀，\n\n东瀛剑客的惯用兵器：太刀！\n",
HIR"变起仓卒，你脚下轻轻一滑，斜进七尺，却听得背后一声厉啸，那武士第二刀又已出，\n刀势极其惨烈，竟隐隐有万千亡魂号哭之声。"NOR,
HIY"你暗叫一声不妙，猛一翻身，望着天仰躺下去，铁板桥！\n"
HIW"眼前的白华骤然一闪，一道杏黄光芒流过，有柄长刀冲天而起，那武士胸口喷出一道血\n泉，又是一声厉啸：嘎～～～～～～～～～～",
"抹一把冷汗，你听见有个声音淡淡道：没伤著？\n那声音异常年轻，冷漠平静，沉稳中带一点非常过分的孤傲。\n",
});

	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if ( me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n\n"NOR,me,target);

	if (count==0)
	{
		target->move(this_object());
		ob=new(__DIR__"obj/corpse2");
		ob->move(this_object());
		ob=new(__DIR__"obj/corpse3");
		ob->move(this_object());

	}


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		call_out("do_ggyy2",10,me,target,0);	
		me->perform_busy(60);
		REWARD_D->riddle_set(me,"天涯魂梦",2);
		return;
	}
	return;
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


