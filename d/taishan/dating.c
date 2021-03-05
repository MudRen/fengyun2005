// Room: dating.c --- by MapMaker

inherit ROOM;
#include <ansi.h>
string jinbian_desc();
void create()
{
	set("short", "侠义无双厅");

	set("long", @LONG
这里便是侠义无双厅。屋中摆设极为简单，但却打扫得一尘不染，素雅中透着
深深的凝重，正中端端正正摆了张檀木条案，案上放了盏油灯，旁边的太师椅上端
坐着无垢山庄的少主人连城璧，他微闭双眼，正轻轻抚着手中金剑，脸上露出种讥
诮不屑的笑容。厅中正上方，高高挂着副金匾，刻着【侠义无双】四个蘸金大字。
LONG);

	set("exits",([
	"east":__DIR__"shufang",
	"west":__DIR__"woshi",
        "out":__DIR__"damen",
	]) );
        set("objects", ([
                __DIR__"npc/lian" : 1,
        ]) );
	set("item_desc", ([
		"金匾" : (: jinbian_desc :),
        "jinbian" : (: jinbian_desc: ),
	]));
	set("indoors", "taishan");
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",150);
	set("mengce",1);
	setup();
}

string jinbian_desc()
{
	if (query("mengce"))
	{
		return "一块巨大的金匾，上面刻着侠义无双四个金字，但似乎金匾后隐隐藏着点什么东西，
不知道可否跳（leap）起来取出看看。 \n";
	}else
		return "一块巨大的金匾，上面刻着侠义无双四个金字\n";
}

void reset()
{
	this_object()->set("mengce",1);
	::reset();
}

void init(){
	add_action("do_leap", "leap");
}

int do_leap(string arg){
	object lian, me;
    object mengce;
	me = this_player();
	if(!arg || (arg != "up" && arg != "金匾" && arg != "jinbian"))
		return notify_fail("你要往哪里跳？\n");
     if (me->query_skill("dodge",1) < 100)
        return notify_fail("金匾太高，以你现在的轻功，是根本跳不到的。\n");
	 message_vision(HIC"\n$N吸了口气，突然纵身一跃。\n"NOR,me);
	if (random(me->query_skill("perception",1))>50)
	{
		if (this_object()->query("mengce"))
		{
			message_vision(
					HIC"一个鹞子翻身，$N从金匾后迅雷不及掩耳取出一卷卷轴，轻巧地落在大厅中。\n\n"NOR, me);
			mengce=new(__DIR__"obj/mengce");
			mengce->move(me);
			this_object()->delete("mengce");
		}else
			message_vision(RED"$N看见金匾后空空如也，似乎什么也没有。\n"NOR,me);

	}else
	{
		message_vision(HIW"瞬息之间，$N无法看清金匾后有些什么。\n"NOR,me);
	}
	me->start_busy(3);
	if( lian = present("lian", this_object()) )
	 {
                message_vision(
"\n$N"HIR"冷哼一声，对着$n嘿嘿笑道：何处狂徒，竟在我无垢山庄撒野！\n
$N"HIR"冷冷道：偷盟册者，杀无赦！\n\n"NOR,lian,me);
                lian->kill_ob(me);
       
       }
		return 1;
}

