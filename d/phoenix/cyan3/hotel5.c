// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "初雨阁");
    set("long", "这是一间很普通的小小木屋，几张凳子，一个小桌，旁边的梳妆台镜缘斜
斜地簪著几朵山野间随处可见的淡黄色碎蕊星花。很简单的摆设，却有著难以
名状的舒适感觉，唯一略显突兀的便是正堂之上悬著的一面"WHT"匾额"NOR"，书著大大的
＂杀妖狐＂三字，笔法刚中见柔，显是出自女子之手。
"NOR
        );
	set("objects", ([
	__DIR__"obj/scroll":1,

	]));
	set("item_desc", ([
	
	]) );
	set("exits",([
  		"east" : "bridge",
	]) );
	set("area","cyan3");


	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}


int do_nothhing()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	else
		return 1;
}

int do_a1()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy3",2,me,present("su ruo"),0);
	return 1;
}

int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy2",2,me,present("su ruo"),0);
	return 1;
}


int do_g(string arg)
{
	object me=this_player(),l;
	if (arg != "all from 匾额" && arg != "pill from 匾额")
		return 0;
	if (query("al"))
		return 0;
	message_vision("$N自匾额后面取出一丸"HIR"九转还魂丹。"NOR,me);
	l=new("/d/shenshui/obj/medicine");
	l->move(me);
	set("al",1);
	REWARD_D->riddle_done(me,"杀妖狐后的药丸",0,1);
	return 1;
}

void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (query("c"))
		return;

	set("c",1);

	
	if(!wizardp(this_player()))
			add_action("do_nothhing", "");
	add_action("do_a1","1");
	add_action("do_a2", "2");
	add_action("do_g", "get");



	if (REWARD_D->check_m_success(me,"顾曲") 
		|| REWARD_D->check_m_success(me,"听曲")
		|| REWARD_D->check_m_success(me,"相会")) 
	{

		ob=new(__DIR__"npc/ruo");
		ob->move(this_object());

//		input_to( (: call_other, __FILE__, "select_main", me,ob :));
//		"/cmds/std/look"->look_room(this_player(),this_object());
		

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);

		return;
	}
	ob = new(__DIR__"obj/letter");
	ob->move(this_object());
	return;


}





void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"少女背著双手，偏头露出一抹俏皮可爱的甜笑，左颊上一弯月牙般的伤痕也似开颜。",
"＂当然是要帮穆坛主盯着你，怕你又在哪儿睡死了呀。＂苏若眨眨眼：＂虽然，师父\n要我别同你走得太近呢。＂",
MAG"你心念电转，却怎么也想不起来几时开罪过夜魔坛主。",
"＂还不是上回那事，＂少女撅嘴白了你一眼，＂很伤的呢，人家好容易才快修成逝水\n华年，可一下子就被你毁得乾乾净净。＂",
"＂那个．．．＂",
"＂呆子。＂苏若嗤一声笑出来：＂快去忙你的罢，我还有事情呢，可不是大家都同你\n一般游手好闲。＂


苏若向你挥挥手中的木笛，风一般自你身边掠过，消失在雾海中。",
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
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));
		
		REWARD_D->riddle_done(me,"初晴",0,1);
		return;
	}
	return;
}




void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"\n＂她方才还在下面的山道上，伤得很重的样子呢，＂苏若回头望向窗外的云海：＂凤姐姐．．．＂",
"少女顿了一顿，声音中染上了淡淡的哀愁：＂凤姐姐．．．很可怜啊。教主救下她的
时候，她差点就要被卖进青楼了。那对无良的父母，得知女儿身患绝症，想得不是怎
么救她，倒是．．＂",
"苏若轻轻地叹了口气。",
"＂她几乎．．从来没有笑过的。空魔坛主．．．是为了报答教主吧，我总觉得凤姐姐
是在燃着自己的性命呢，总觉得有一天，她会就那么倒下去．．．＂",
WHT"满室寂静。",
"少女侧过头，抚弄著手中的木笛，轻轻的说：＂有时候我觉得自己真的很幸运，可以
生活得那么幸福．．．＂",
"一声清啸自下方的山谷中传出，苏若一怔，风一般地自你身边掠了过去，消失在雾海
之中。",
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
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));
		
		REWARD_D->riddle_done(me,"初雨",0,1);
		return;
	}
	return;
}



void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"山风穿过敞开的木窗，窗前少女及肩的短发随著时变的风势翻卷。\n许是听见了你的脚步，紫衣的少女回转过头，向你露出璀璨的笑容。\n",
WHT"大少爷．．．真是稀客啊，是什么风把你吹了过来？\n\n"NOR"　　("HIW"1"NOR CYN")"HIY"可见到铭心？\n"NOR CYN"　　("HIW"2"NOR CYN")"HIY"你怎在这里？"NOR CYN"",
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


	message_vision(CYN+msg+"\n"NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
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


