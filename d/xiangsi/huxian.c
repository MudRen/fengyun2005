// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
int imbue_event(object me);
inherit ROOM;

void create()
{
	set("short", "壶仙岩");
        set("long", @LONG
春雪已经融了，高山上已经有雪融后清澈的泉水流下来。可是在山之巅的
白云深处，这一片自古以来就存在的积雪。仍然在闪动着银光。在这一片银白
色的世界里，万事万物都很少有变化，甚至可以说，没有变化。只有生命才有
变化，可是在这里，几乎完全没有生命。
LONG
        );
	set("exits",([
  		"southdown" : __DIR__"houmen",
  		"northup" : __DIR__"feilai",
  		"enter" : __DIR__"icecave",
	]) );

	set("outdoors", "xiangsi");
	set("no_fight",1);

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",30);
	setup();
}

void do_ggyy(object me,object li,object xue,int count)
{
	string msg;
	mapping buff;
	string *event_msg = ({
WHT"月色雪积间，仿佛有层淡淡的烟雾飘来，烟雾间仿佛有一条淡淡的人影。",
"",
CYN"李坏见到她，动了动嘴唇，却一个字也没有说。",
CYN"薛音素合着双眼，淡淡道：一招定胜负？",
CYN"李坏点点头，又想起她看不见，苦笑道：你我交锋，本就只需一招。",
CYN"好。薛音素从袖中摸出一把银白色的小刀，握在莹白如玉的手中。\n"HIW"天上的明月的光芒在一瞬间消弭，那柄银色的小刀散出雪白的辉华，映得壶仙岩上亮如白昼。",
CYN"她慢慢睁开双眼，直视李坏：请。",
CYN"李坏深深地吸了口气，抿紧唇瓣，缓缓掏出了如蝉翼轻薄的飞刀。",
"",
WHT"一阵沁凉的山风卷过，地上的雪浸起淡淡胧胧的白雾。",
"",
CYN"你只觉得眼前刀光一闪，两人身形跃动，双双扬手——",
CYN"例不虚发的小李飞刀射向月神，却是对着她身侧的孤松而去；而月神的手中飞出\n的只是几滴晶莹的水珠；不知何时那精敛的光辉又归与了明月。",
HIC"事起仓卒。\n\n薛音素莲步微纵，伸长纤细的脖颈，竟迎向那本已偏离的飞刀。\n\n变生不测。\n\n人影幢幢跃过，你还不及看清发生了什么，就已经结束。",
HIR"但见薛音素被撞到一旁，踉跄后退；在她身前是一串鲜红的血珠飞洒在素洁\n的雪地上，在惨淡的月色下显得分外妖艳。鲜血的尽处，李坏的右手捂在颈前，\n飞刀暗赤的追穗夹在两指之间。\n\n小李飞刀，例不虚发。只这是第一次，也是最后一次，例不虚发的飞刀插在主人的项上。\n\n他的喉咙咯咯作响，充满痛苦却依然优雅的凤眼望向被撞开到边上的月神；薛音素\n眉间怔忡，眼里交织着爱意、疑惧、伤心与痛苦，终于慢慢的垂下头：我……输了。\n\n李坏因巨痛而扭曲的脸上竭力绽开了一抹微笑，身子晃了一晃，慢慢倒在地上。\n他始终握成拳的左手渐渐松开，露出已被汗水湿糊的一块药粉。",
HIW"月神的影子微微轻颤，紧随着化作月下的一道轻烟，隐去无踪。",
WHT"在她方才站着的地方有一滴深绯色的水珠滑下，",
HIW"不知何时，壶仙岩上飘起了阵阵的碎雪，将地上的血迹与李坏的身体，寂寂掩去。",
});
	if (!me )
		return;
	if (!li && count < 14)
	{
		if (xue)
			destruct(xue);
		return;
	}
	if (!xue && count < 16)
	{
		if (li)
			destruct(li);
		return;
	}
	if (count < 14 && environment(me) != environment(li))
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		return;
	}
	if (count < 16 && environment(me) != environment(xue))
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		return;
	}
	msg = event_msg[count];


	message_vision("\n"+CYN+msg+NOR+"\n",li,me);

	if (count == 14)
	{
		li->die();
		li=present("corpse",this_object());
	}
	if (count == 16)
	{
		destruct(xue);
		imbue_event(me);
	}

	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1,me,li,xue,count+1);
	else
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		set("start",0);
		REWARD_D->riddle_done(me,"两世恩怨",100,1);

//		write(me->query_busy()+"i");
		return;
	}
	return;
}


int start(object who)
{
	object npc1,npc2;
	set("start",1);
	npc1=new(__DIR__"npc/lihuai");
	npc2=new(__DIR__"npc/xue");
	npc1->move(this_object());
	npc2->move(this_object());
	who->start_busy(20);
	call_out("do_ggyy",1,who,npc1,npc2,0);
}

int init()
{
	object who = this_player();
	if (!NATURE_D->is_day_time())
		if (REWARD_D->riddle_check(who,"两世恩怨") == 11  )
			if (!query("start"))
				start(who);
}


int imbue_event(object me)
{
	object weapon, obj, *inv;
	string prop;
	int i;
	int j;
	mapping data;

	if(!interactive(me) || environment(me) != this_object()){
		return 0;
	}

	j = me->query("宿命B/相思_飞来");

	if(me->query("imbue/moon_xue"))
	{
			message_vision(WHT"滴落在雪地上，溅成一朵小小的鲜红梅花。\n"NOR,me);
	} 
	else 
	{
		message_vision(WHT"滴落在$N的掌心，化成一朵小小的鲜红梅花。\n"NOR, me);  
		data = ([
			"name":		"两世恩怨",
			"target":	me,
			"att_2":	"str",
			"att_2c":	1,
			"mark":		3,
		]);

		REWARD_D->imbue_att(data);	
		me->set("imbue/moon_xue", 1);
		me->save();
		log_file("riddle/IMBUE_LOG",
			sprintf("%s(%s) 解开 两世恩怨，得到结局 event %d. %s \n",
				me->name(1), geteuid(me), j, ctime(time()) ));
		return 1;
	} 
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
