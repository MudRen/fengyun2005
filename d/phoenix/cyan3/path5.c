// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "山道");
    set("long", @LONG
这里的山道与其叫山道，倒不如叫做山隙更恰当些：道路仅有肩宽，左右
都是坚硬的花岩，惟有一丝微弱的光芒自头顶的石缝中漏下。借着微光，你隐
可看见窄缝中洒满了凌乱而且锋利的碎石，节节爬高，不知通向何方。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/cliff":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westdown" : "forest3",
  		"eastup" : "peak1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}

int	valid_leave(object who, string dir)
{
	if (dir == "westup")
		return ::valid_leave(who,dir);
	return notify_fail("就别到处乱晃了吧？\n");
}




void init()
{
	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (REWARD_D->riddle_check(me,"天涯魂梦") ==2) 
	{
		ob=new(__DIR__"npc/shi");
		ob->move(this_object());
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy3",4,me,ob,0);
	}
	
	return;
}

object fob()
{
	object *inv=all_inventory(this_object());
	int i;
	for (i=0; i<sizeof(inv);i++ )
		if (userp(inv[i]))
			return inv[i];
	return 0;
}

void c()
{
	object me = fob();
	object ob = present("li qingzhuo",this_object());
	if (!me || !ob)
		return;
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy4",4,me,ob,0);

}

void do_ggyy4(object me,object target,int count)
{
	string msg;
	object ob,l;
	string *event_msg = ({
YEL"天渐渐阴了下去，有雷光在天上遨游。秋林风切，一山木叶簌簌作响，黄叶萧索肃杀。",
"李青卓取出一块白帕，缓缓拭去剑上血迹，收剑回鞘，鞘作龙吟。",
MAG"没想到倭人动作如此迅速，排好的如意算盘立时打乱；现下又不可表露身份，只能且行且看，静观其变了。\n"CYN"你心下已有计较，朝李青卓点点头：＂走？＂",
"＂走。＂",
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


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy4",4,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		REWARD_D->riddle_set(me,"天涯魂梦",4);
		delete("exits");
		set("exits/westup","peak3");
		return;
	}
	return;
}




void do_ggyy3(object me,object target,int count)
{
	string msg;
	object ob,l;
	string *event_msg = ({
"上得山道，但见一个身著笔挺青衫的剑客正满面焦急地来回踱步，一边来去一边喃喃低咒甚么。",
"那剑客一见李青卓，立刻便迎了上来：＂师弟，师傅说．．．嗯？＂\n石未巍瞟了你一眼，欲言又止。",
"李青卓淡淡道：＂说。＂",
"石未巍脸色一青，沉声道：事情有变。原来魔教与倭贼勾结，早将我们的动向打听得一清二楚。\n丐帮飞鸽传信，东瀛海司数十战船前夜已抵临东海，大群浪人正拥堵明霞，计划将中原好手一举\n歼灭。",
"李青卓微微一笑：＂只怕没那么容易。＂",
"＂师傅说，只是那帮流寇则大可不必顾忌；可魔教此番亦是倾巢而出，据说天、夜、烟、空四坛\n坛主此次齐聚明霞，魔教六司也来了三个，若他们混入大会，与倭人内外夹击，只怕．．．＂",
MAG" (你心中暗暗吃惊。在临行之时，你亦仅知铭心与师父长风此遭亲临，何以至这些正派名门倒知晓\n得如此清晰？)"NOR,
"＂烟魔坛纪玺，＂李青卓轻轻说，＂他与东海流寇有戴天之仇，不必担心。＂",
"石未巍皱皱眉头，置若未闻：＂东将军与师傅合计之后，下令兵分两路：武当弟子前去瞭望台守\n备大弩阻止倭贼上山，其他人沿走山阴小道下山，绕到流寇背后给他们．．．＂",
WHT"话音未落，便见几道黑影沿山道飞掠而来，身法怪异之极。\n石未巍低咒一声，喝道：＂来得这么快．．．我得去上报掌门，师弟你且先守在这里！＂",
WHT"黑影转瞬间掠至眼前，李青卓冷冷一按剑柄，秋水般清亮的剑身跳脱而起，向黑影斩去！\n"
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


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",4,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		REWARD_D->riddle_set(me,"天涯魂梦",3);
		destruct(target);

		if (present("li qingzhuo",this_object()))
			l=present("li qingzhuo",this_object());

		ob = new(__DIR__"npc/j1");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);


		ob = new(__DIR__"npc/j2");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);


			
		ob = new(__DIR__"npc/j3");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);



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


