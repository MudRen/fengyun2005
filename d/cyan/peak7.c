// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "离音谷");
    set("long", @LONG
离音谷地中满布着荧荧白石，有一道蜿蜒溪流自南向流过，小谷中溪水横
洞，波声潺潺，间或有几声鹤唳，倒也别具一方幽情。谷中似已经多年渺无人
迹，有一些前来喝水的小动物一点儿也不怕生，正睁着圆圆的大眼睛好奇地打
量着你。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/cat":1,
	__DIR__"npc/turtle":1,
		__DIR__"obj/river" : 1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : __DIR__"path8",
  		"southup" : __DIR__"peak11",
  		"northup" : __DIR__"peak10",
  		"eastdown" : __DIR__"patha",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("溪水", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
	}
	return;
}

int	valid_leave(object who, string dir)
{
	object me,npc;
	me = who;
	if (me->query_temp("annie/no_leave"))
		return notify_fail("你的去路被挡住了耶．．．\n");

	if (dir != "southup")
		return ::valid_leave(who,dir);

	if (REWARD_D->riddle_check(me,"探流追源") != 3 && REWARD_D->riddle_check(me,"探流追源") != 4)
		return ::valid_leave(who,dir);

	me->set_temp("annie/no_leave",1);
	REWARD_D->riddle_set(me,"探流追源",4);
	npc=new(__DIR__"npc/stormeye");
	npc->move(this_object());
	message_vision(CYN"\n你身后突传衣角振空之声，一个高大的人影凌空掠到，落在$N面前。\n\n",me,npc);
	message_vision(CYN"$n脸色铁青，沉声道：站住！\n",me,npc);
	tell_object(me,RED"你为灰衣人神威所震，禁不住收住脚步。\n");
	who->start_busy(9);
	call_out("do_ggyy",2,me,npc,0);
	return notify_fail(" ");
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$n冷冷地将$N从头到脚打量一遍，将手按在腰间的配剑之上。\n$n道：老夫早就听说魔教想对顾道人痛下毒手，特意过去保护，\n$n道：没想到还是着了你们这群卑鄙小人的道！",
"$N满脸疑惑地问：但顾道人难道不是魔教中人？",
"$n斥道：胡说！顾道人一生行为堂堂正正，怎可能是魔教中人？\n\n$n脸色突然一变，愈见青白：谁告诉你顾道人是魔教爪牙？",
"$N皱紧眉头，将事情始末原原本本和盘托出。",
"$n越听越气，到最后直是怒发须张，大喝道：蠢材！蠢材！笨蛋！笨蛋！",
HIR"$n气得浑身发颤，指着$N的鼻子道：你送上门去作人家的"YEL"棋子"HIR"，事到如今还不明白么？"NOR,
"$N恍然醒悟，迟疑道：那．．．",
"$n叹气道：朽木，朽木……\n$n道：老夫本想自你身上问出刺客下落，你既是被利用，此事已成泡影。\n$n沉吟片刻道：不如给你个将功折罪的机会。",
"$n道：老夫听闻他们又要对龙图阁老下手，为防万一，我们兵分两路。\n$n道：如今老夫前去济南府保护阁老，你则直接前去截击刺客。",
"$N问道：不知那刺客是谁？",
"$n一字一字道：便是那沽名钓誉的武林败类，兴国禅寺的"HIR"晦气大师"NOR CYN"！",
"$n道：你去过之后，只向他询问龙图阁大学士的名字，他即会败露原形。",
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

	if (count == 1)
		tell_object(me,RED"魔教？可是．．．\n"NOR);

	message_vision(CYN+msg+"\n"NOR,me,target);

	if (count == 5)
		tell_object(me,RED"你心念电转，骤而有一个可怕的念头窜进脑海，灵光突至。\n原来自始至终你都上了别人的当，所谓的山流引路，根本是魔教设下的一个骗局。\n"NOR);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"探流追源",5);
		message_vision(CYN"话音乍停，灰衣人三起三落消失无影。\n"NOR, me);
		destruct(target);
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


