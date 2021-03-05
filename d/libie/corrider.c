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
	"down":__DIR__"yuelai",
	"enter":__DIR__"qilin",
	]) );
	//}}


	set("objects", ([
        __DIR__"npc/xiaoyezi": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
		setup();	
}

int valid_leave(object me,string dir)
{
	object xiaoyezi;
	object room,cloth;
	
	room=this_object();
	if(dir!="enter") return 1;
	if(me->query_temp("libie/离别钩_准许进入麒麟阁")) {
		return 1;
	}
	if(!objectp(xiaoyezi=present("xiao yezi",room))) return 1;
 	if(!living(xiaoyezi)) return 1;
 	if(me->query_temp("libie/离别钩_最后结局开始")){
 		message_vision(HIR"小叶子微笑的对$N说道：“这位"+RANK_D->query_respect(me)+"一定就是"+me->query("name")+"大侠吧，敝上已经等候阁下多时了。”\n"NOR,me);
 		me->delete_temp("libie/离别钩_禁止进入麒麟阁");
 		me->set_temp("libie/离别钩_准许进入麒麟阁",1);
 		return notify_fail("");
 	}
 	if(me->query_temp("libie/离别钩_禁止进入麒麟阁"))
 		return notify_fail(HIR"小叶子身形一闪，挡在你身前。\n"NOR);
 	
 	cloth=present("waiter cloth",me);
   	if(objectp(cloth))
   	if(cloth->query("equipped")){
   		message_vision(HIY"小叶子挡住了$N的去路：“这没你的事了，下去忙活吧。”\n"NOR,me);	
   		return notify_fail("");
   	}
   	add_action("do_answer","answer");
   	message_vision(HIY"小叶子向$N问道：“请问这位"+RANK_D->query_respect(me)+"是不是要找狄小侯爷？”\n"NOR,me);
   	return notify_fail(HIY"answer(yes/no)\n"NOR);
}

int do_answer(string arg)
{
	object ob, me;
	object room;
	
	room=this_object();
	ob=present("xiao yezi",room);
	me=this_player();
	if(!objectp(ob)) return 0;
	if(!living(ob)) return 0;
	if (arg=="no")
	{
		message_vision(HIW"小叶子微笑的对$N说道：“既然不是来找狄小侯爷的，就请不要在这里打扰狄小侯爷的休息了。”\n"NOR,me);
		remove_action("do_answer","answer");
		return 1;
	}
	if (arg=="yes")
	{
		message_vision(HIY"小叶子微笑的对$N说道：“原来是这样，请跟我来。”\n"NOR,me);
		if(me->query_temp("libie/小叶子杀"))
		{
			call_out("killing",1,ob,me);
			me->set_temp("libie/离别钩_禁止进入麒麟阁",1);
			return 1;
		}
		message_vision(HIY"小叶子向$N示意可以进入麒麟阁。\n"NOR,me);
		me->set_temp("libie/离别钩_准许进入麒麟阁",1);
		remove_action("do_answer","answer");
		return 1;
	}
	return 0;
}


/*
一个瞽目老者，盘膝坐在一个蒲团上，膝头上横摆根青
竹杖，仿佛象老僧入定，物我两忘。另一个蒲团的两边，枪一般站着
两个年轻人。
*/

void killing(object ob, object me)
{
	message_vision(HIR"小叶子忽然对$N狞笑道：“去死吧。。。”\n",me);
	ob->ccommand("wield dagger");
	ob->kill_ob(me);
	ob->ccommand("perform sharenruma");
}
