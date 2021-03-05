// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit "/d/phoenix/ann_door_room.c";
string look_stone();

void create()
{
	set("short", "明月故居");
    set("long", @LONG
琼花劫到，玉树歌终，暮色中的小小木屋只似天地间一抹黛色，竟是极薄
极淡，吹弹得破，转教人疑惑它竟何以承载得一时间绝代风华，牵萦魂魄，颠
倒梦想。只当年过后，风雨至今，屋中最后一点绮靡风光也寂寂散去，只余荒
烟落日，蓬卷尘飞。 

即便是片石孤云窥色相，清池皓月照禅心。

LONG
NOR









        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : "peak12",
	]) );
	set("area","cyan3");

    create_door("southdown","rock","大石","northup",DOOR_CLOSED);

	set("outdoors","cyan");

	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",50);
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
	call_out("do_ggyy2",2,me,present("su ruo"),0);
	return 1;
}


int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
		message_vision(CYN"$n心念电转，只觉得这其中有一个极难勘破的关节，却又没有任何头绪，顿顿脚转身离去。\n"NOR,me,me);

		open_door("southdown",0);
		me->ccommand("southdown");
		REWARD_D->riddle_done(me,"听曲",0,1);

		if (present("su ruo"))
			destruct(present("su ruo"));
		return 1;
}


void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;


	
	if(!wizardp(this_player()))
	{
			add_action("do_nothhing", "");
			add_action("do_a1","1");
			add_action("do_a2", "2");
	}


	if (REWARD_D->riddle_check(me,"天涯魂梦") <=6 && !REWARD_D->check_m_success(me,"顾曲") && !REWARD_D->check_m_success(me,"听曲") && !REWARD_D->check_m_success(me,"相会") && NATURE_D->getTime(time())[1] >7 && NATURE_D->getTime(time())[1] <11) 
	{

		ob=new(__DIR__"npc/ruo");
		
		ob->move(this_object());

//		input_to( (: call_other, __FILE__, "select_main", me,ob :));
//		"/cmds/std/look"->look_room(this_player(),this_object());
		

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);

		return;
	}
	if (REWARD_D->riddle_check(me,"天涯魂梦") <=6 && !REWARD_D->check_m_success(me,"顾曲") && !REWARD_D->check_m_success(me,"听曲") && !REWARD_D->check_m_success(me,"相会") ) 
	{
		ob=new(__DIR__"npc/ruo");
		
		ob->move(this_object());



		me->set_temp("disable_inputs",1);

		call_out("do_ggyy3",2,me,ob,0);

		


	}
	
	return;


}


void select_main(object me, object ob,string arg)
{
	if (arg != "1" && arg != "2")
	{
		input_to( (: call_other, __FILE__, "select_main", me, ob :));
		return;
	}
	if (arg == "1")
	{
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy2",2,me,ob,0);
	}
	else
	{
		message_vision(CYN"$n心念电转，只觉得这其中有一个极难勘破的关节，却又没有任何头绪，顿顿脚转身离去。\n"NOR,me,me);

		open_door("southdown",0);
		me->ccommand("southdown");
		REWARD_D->riddle_done(me,"听曲",0,1);

		destruct(ob);
	}
	return;

}



void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"你振衣纵跃到那杨木边蹲下，双手轻环抱起紫衣少女，让她枕在臂弯之间，动作自然随性，仿佛许久之前便有过这般经验。",
"喂她服下两剂西凉化生散，少女苍白的脸颊上渐渐地浮起红晕，朱唇微启，在你怀中低低呻吟。",
"你一时间心猿意马，正要俯下头去，却见少女缓缓睁开眼睛，秋瞳迷迷蒙蒙地望著你。",
"她似是认出了你的面容，嘴角牵动扯出一个虚弱的微笑：＂昭光．．你又害我．．＂",
"一阵怪风忽迩卷过，你只觉手里一轻，紫衣少女已落入一个淡绿的影子怀中。\n那影子瞬霎间穿林而去，留下清清冷冷的一句警告在你身边：＂天魔坛的小子，下次再伤我门下弟子，可\n莫怪老娘不卖你那臭师父面子亲手宰了你！＂",
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
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));

		if (present("demon drug",me))
			if (present("demon drug",me)->query_amount()>=2)
				present("demon drug",me)->add_amount(-2);
		
		REWARD_D->riddle_done(me,"顾曲",0,1);
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"苏若轻笑道：呀，我刚要去找你，大少爷怎就自己过来了？",
"苏若扬扬手中的一封朱红信柬巧笑：穆坛主要你去那什么捞咋子的大会不是？喏，请柬已经在这里等你啦！",
"苏若双指一弹将请柬射到你怀中，旋即飘然而去，身后留下一串银铃般的笑声：大少爷，可记得你又欠我一份人情噢～",
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
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));

		target=new(__DIR__"obj/letter1");
		target->move(me);

		REWARD_D->riddle_done(me,"相会",0,1);


	tell_object(me,HIY"你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"去"CYN"凌云顶"WHT"参加饮血平寇大会"NOR);
	me->set("quest/location", "somewhere");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


		return;
	}
	return;
}




void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({

"落日的夕霭斜斜地洒在小木屋前的竹篱上，微风扬起，满山的木叶簌簌作响，天地间流转著淡淡的金黄。",
"紫衣少女倚靠著篱院内一株杨木，合唇轻按手中的木笛，飞旋起阵阵捉摸不定的飘渺旋律。",
"听著她的曲子，你的眼前幻化出种种斑斓景象，似乎一生的所求已都在那里，却又可望而不可及。",
"音节渐渐拔高，一时间蜃景转变得极尽奢靡，在几无可能达到的高度再三扬起，犹如攀上了千仞的顶峰，\n又隐隐昭示著繁华背后无限的空虚。",
HIR"你的心脏在胸口邃急跳动，真气沿著奇经八脉疾速游走又毫无规律，一股热气自体内源源不绝地涌出，你\n暗叫一声不妙，敛起残存的内力舌绽春雷，喝道：“开！”",
HIR"回旋的曲声猝然而止，少女如受重击，向前打了个踉跄，啪地将手中的木笛掰作两截，哇一声喷出一大口\n鲜血扑倒在地。",
"你只觉这场景竟是分外熟悉，一时心头大乱，不知是该("HIW"1"NOR CYN")"HIY"上前扶她"NOR CYN"或是("HIW"2"NOR CYN")"HIY"尽速离去"NOR CYN"。",
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


