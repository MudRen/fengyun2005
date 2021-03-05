// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "走廊");

	set("long", @LONG
麒麟阁外面的一条走廊。本来在这个破落的小镇上，客栈也没什么钱修葺这条
本已摇摇晃晃，嘎吱嘎吱做响的木头走廊，但因为世袭一等侯狄青麟的到来，一辈
子省吃俭用的老板狠狠心硬是几乎搭上了所有的家当在走廊上铺上了红地毯，两边
栏上也高高挂起了大红灯笼。
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"down":__DIR__"corridor",
		"enter":__DIR__"qilin",
	]) );
	//}}

	set("no_fight",1);
	set("objects", ([
        	__DIR__"npc/tongzi": 2,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",20);
	setup();	
}


int valid_leave(object me,string dir)
{
	object menfang;
	object room,ob;
	
	if(dir!="enter") return ::valid_leave();
	
	if (!objectp(ob = present("jinyi tongzi", this_object())))
		return notify_fail("阁门紧闭，你无法进入。\n");
			
	if(REWARD_D->riddle_check(me,"离别")==3)
	{
		room = find_object(__DIR__"qilin");
		if (!room)	room = load_object(__DIR__"qilin");
		if (room->usr_in())
			return notify_fail(CYN"锦衣童子微笑说：敝上正在见客，请稍候。\n"NOR);
		
		if (me->query_temp("libie/libie_enter"))	{
			me->delete_temp("libie/libie_enter");
			room->reset();
			return 1;
		}
		
		message_vision(CYN"锦衣童子微笑的对$N说道：“这位"
 			+RANK_D->query_respect(me)+"一定就是"
 			+ me->query("name")+"大侠吧，敝上已经等候阁下多时了。”\n"NOR,me);
		me->set_temp("libie/libie_enter",1);
		return notify_fail("");
	}
	
	if (!me->query_temp("libie/libie_enter"))
	{
		message_vision(CYN"锦衣童子斜眼看着$N，皮笑肉不笑地哼了一声，冷冷地问：
“你知不知道这里是什么地方？”"WHT" answer(yes/no)\n"NOR, me);
		add_action("do_answer","answer");
		return notify_fail("");
	}
	return 1;
}

int do_answer(string arg)
{
	object ob, me;
	object room;
	
	room=this_object();
	ob=present("jinyi tongzi",room);
	me = this_player();
	
	if(!objectp(ob)) return 0;
	
	if (arg=="no")
	{
		message_vision(CYN"
锦衣童子挺了挺胸说道：这里就是世袭一等侯、当今天下第一风流侠少狄小侯爷的
行栈，像你这样的无名小辈还是快快退下吧。\n"NOR,me);
		remove_action("do_answer","answer");
		return 1;
	}
	if (arg=="yes")
	{
		remove_action("do_answer","answer");
		message_vision(CYN"锦衣童子说道：“既然知道，还不快快退下。”\n"NOR,me);
		return 1;
	}
	
	return 0;
}
