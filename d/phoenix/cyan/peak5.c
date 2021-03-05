// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "沉香海");
    set("long", @LONG
或许是因为处在难得的谷地，身边有星花盛放，四面是凉风习习，琴松风
而拂竹翠，藤萝冥冥而草木和鸣。离开了枯燥单调的黄树林步入这里，眼前青
碧的花木、淡淡的松香令你骤觉得仿然仙境，直想躺平在茸茸花草之间，享受
片刻的宁静。
LONG
NOR
        );
	set("objects", ([
		__DIR__"obj/pine":1,
		__DIR__"obj/hole":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path7",
  		"eastup" : "path8",
  		"southup" : "forest5",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void trigger(object me)
{
	object ob;
	message_vision(CYN"原是一个巧笑倩兮的紫衣少女蹲在你身边轻轻呵气。\n",me);
	message_vision(MAG"你盯著少女左颊上的寸许疤痕，一时但觉她十分面善，似与你渊源极深，可是却想不起来．．．\n\n",me);
	message_vision(CYN"苏若瞅著你银铃般轻笑：我的大少爷，你可算醒了，大家寻你寻得焦头烂额，
你倒是藏在这里好一顿饱觉啊。\n\n",me);
	message_vision(CYN"苏若说道：穆坛主可是找你半天了呢。喏，用这水洗一把脸，然后还是快点过去吧，
可莫要拖得惹他老人家生气才好。\n",me);
	
	message_vision(CYN"\n苏若给你一个大肚瓶，扮了个鬼脸飘然而去。\n",me);

	tell_object(me,HIY"\n你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"到"CYN+"映景明湖"+WHT"找天魔坛主穆长风"NOR);
	me->set("quest/location", "映景明湖");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	REWARD_D->riddle_set(me,"韶光虚掷",1);

	if (present("su ruo"))
		destruct(present("su ruo"));

	return;
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "eastup")
		if (REWARD_D->riddle_check(me,"韶光虚掷") == 1) 
			return notify_fail("还是先去找师傅吧。\n");

	return ::valid_leave(who,dir);
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


