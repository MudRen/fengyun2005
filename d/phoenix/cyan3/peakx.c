// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
inherit F_LEVEL;

void create()
{
	set("short", "湖畔小径");
    set("long", @LONG
漫步在映景明湖畔的小径上，四周寂静无声，一边是落叶缤纷的高大树木
，一侧是隔着焦黄芦苇、平静无波的湖水，踏着轻盈的脚步，心逐渐地沉静下
来，呼吸的每一口空气都那么清新凉爽，飘著淡淡的水香。
LONG
NOR
        );
	set("objects", ([

	]));
	set("exits",([
  		"eastup" : "peak11",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-70);
	setup();

	set("no_fly", 1);
}

int do_nothhing()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	else
		return 1;
}

int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy2",2,me,present("feng minxin"),0);
	return 1;
}


int do_a1()
{
	object me = this_player();
	object target;
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");

		message_vision(CYN"\n少女垂下眼去，柔顺地点了点头，自长袖中摸出一封鲜红色的书柬，双\n指轻轻一按，书柬便轻跳而起，平平向你飞来。\n\n"WHT"你探手接住染著淡淡玉兰花香的书柬，再抬眼时，那一袭雪纱的少女已\n然消失不见。\n"NOR,me,me);

		REWARD_D->riddle_done(me,"湖畔相会",0,1);

		if (present("feng minxin"))
			destruct(present("feng minxin"));

		if (present("mayuri"))
			destruct(present("mayuri"));


		target=new(__DIR__"obj/letter2");
		target->move(me);


		return 1;
}


void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;


	if (REWARD_D->riddle_check(me,"天涯魂梦") <=6 && !REWARD_D->check_m_success(me,"铭心") && !REWARD_D->check_m_success(me,"湖畔相会") ) 
	{
			ob=new(__DIR__"npc/pet");
		
		ob->move(this_object());

		ob=new(__DIR__"npc/feng");
		
		ob->move(this_object());

//	if(!wizardp(this_player()))
//	{
			add_action("do_nothhing", "");
			add_action("do_a1","1");
			add_action("do_a2", "2");
//	}
		me->set_temp("disable_inputs",1);

		call_out("do_ggyy3",2,me,ob,0);

	}
	
	return;


}


void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({

"\n少女素色的脸颊上泛起一层淡淡的红晕，轻咬著下唇瞅著你一步步行了\n过去。\n\n",

"「铭心．．．」你步到少女身边，用一种如梦似幻的声音低唤，轻轻拥\n住雪纱下纤瘦玲珑的身躯。\n\n",

"少女垂下螓首，蝴蝶般的睫毛微微颤动，慢慢依偎下来，双手环环抱住\n，乌丝在你胸前如瀑披散。\n\n",

"你心跳的频率渐渐加快，在少女背后摸索著，轻柔地扯开了束在她腰上\n的素缎。少女在你怀中一颤，抬起头来望你，清澈的眼中似有淡淡的水\n雾流转。\n\n",

"你轻轻地拍著她如雪般细致光滑的脊背，嘟囔著宁定人心的音节，像在\n安抚一只受惊的小动物，一面慢慢地褪下她身上一直迤逦到地的云纱。\n\n",

"少女一声轻喘，将额头埋回你的胸口，啮咬著你的衣衫。你觉得阵阵热\n流在丹田之中凝聚，探手下握住她的脚踝向上抬举，低唤道：「铭心．\n．．」\n\n",

HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",
HIR BLK "．",

"\n\n你慢慢地睁开眼睛，发现自己斜躺在小径右侧的一堆枯草之上，身边渺\n无人迹，只是鼻端尚存著淡淡的玉兰花香。\n\n",

"一截扯破的雪纱垂挂在枯草边上，怵目惊心地烙印著一抹赭红。你盯著\n那一抹雪纱，背后的几道爪痕隐隐作痛，恍惚间忆起她当时的轻吟，挣\n扎．．．．\n\n"CYN"恍如一梦。\n\n",

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


	message_vision(WHT+msg+NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);

		if (present("feng minxin"))
			destruct(present("feng minxin"));

		if (present("mayuri"))
			destruct(present("mayuri"));

		REWARD_D->riddle_done(me,"铭心",0,1);
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({



HIR BLK"\n这一路湖色淡谧，茅草轻摇，浅灰色的天空静静地悬著，微风轻轻流过\n，从小径的这一头，直吹到那一头。"NOR,
WHT"披一袭雪色长纱的人影蹲在小径的深处，抱著一只溢彩流光的大鸟，一\n任乌黑的长发流泻在地。\n\n仿若偶落凡间的仙灵。"NOR,
"你不由自主松开了紧握长鞭的手，让一缕淡笑悄悄的爬上唇侧，轻唤那\n一个在心中一闪而过的名字：铭心。",
"少女缓缓抬起双眸。她的眼睛漆黑如墨，而又剔透晶莹。\n「韶光，」她望著你微微地笑，又唤道：「韶光。」",
"你们静静地对视著，心中盈满了难言的情绪。那只大鸟轻轻挣出少女的\n怀抱，偏著头好奇地打量著你们，继尔一声清脆的长鸣，展翅离去，在\n空中留下一串细碎的"HIY"金色光点"NOR CYN"构出的轨迹。",
"\n"HIW"1"NOR CYN")"HIY"呃．．．师傅交代我．．．"NOR CYN"\n"HIW"2"NOR CYN")"HIY"铭心．．．．．．"NOR CYN"",
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



	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",4,me,target,count+1);
	else
	{
		set("ggyying",0);
//		me->set_temp("annie/no_leave",0);
//		destruct(target);
		me->set_temp("disable_inputs",0);
//		if (present("su ruo"))
//			destruct(present("su ruo"));
		me->set_temp("annie/answer",1);
//		input_to( (: call_other, __FILE__, "select_main", me, target :));
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



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


