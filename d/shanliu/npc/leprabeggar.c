inherit NPC;
#include <ansi.h>
void create()
{
        set_name("疯乞丐", ({ "lepra beggar" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", "这是一个身患麻风的疯乞丐，浑身恶疮脓水，满面红斑，为世人所弃，蜷缩 
在穷街一角，浑身战栗，奄奄一息，不知有什么方法能治他（ｈｅａｌ）。 \n");
        set("combat_exp", 200000);
        set("str", 10);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 20);
        set("chat_chance", 1);
		set("chat_msg", ({
                "疯乞丐蜷缩躺在穷街的垃圾堆里，嘴里泛着白沫，涩涩发抖。\n",
        }) );
        setup();
        carry_object("obj/armor/cloth")->wear();
}


void init()
{
	add_action("do_heal","heal");
	add_action("do_decide","decide");
}

int do_decide(string arg)
{
	object wangshedan, zhuyeshedan, xiangweishedan;
	object me;
	me = this_player();
	if (!me->query_temp("入山流/喂蛇药"))
		return 0;
	if (arg != "not" && arg != "heal")
	{
		return notify_fail("你只可决定 heal 或 not \n");
	}
	if (arg == "not")
	{
		me->delete_temp("入山流/喂蛇药");
		me->delete_temp("入山流/治麻风");
		message_vision(HIW"$N跺了跺脚道：万一我也染上这麻风怎么办？算了，哎，算了。 \n"NOR,me);
		return 1;
	}else if (arg == "heal")
	{
		
		if (present("wang shedan",me) && present("zhuye shedan",me) && present("xiangwei shedan",me))
		{
			message_vision(
HIG"$n微微一笑，抛开杂念，将三个蛇胆放入口中，但觉一股冰凉之意充盈全身。 
$n跪在$N身前，将口中蛇胆与唾液缓缓渡到$N口中。。。\n \n"NOR,this_object(),me);
			wangshedan =present("wang shedan",me);
			destruct(wangshedan);
			zhuyeshedan = present("zhuye shedan",me);
			destruct(zhuyeshedan);
			xiangweishedan = present("xiangwei shedan",me);
			destruct(xiangweishedan);
			call_out("healing",3,me);
			return 1;
			
		}else
		{
			return notify_fail("你没有足够的药材！\n");
		}
	}
}

void bePrince(object me)
{
	if (me && environment(me) == environment(this_object()))
	{
		message_vision(
HIC"$N不由得心中一震：这哪里是刚才脏污的疯气丐，那一双黝黑深邃的双眸似乎
要把人心都吸进去。\n\n"NOR,me);
		message_vision(
HIC"青年缓缓站起，向$N微笑道：恭喜这位"+RANK_D->query_respect(me)+"，你已通过山流的第
一项考验了。\n说罢，转身离去。\n\n"NOR,me);	
		message_vision(
HIC"$N若呆了一般，浸在青年若微风拂过一池春水的微笑中久久不能自拔。。\n\n"NOR,me);
		destruct(this_object());
	}else
	{
		message_vision("$N缓缓站起，转身离去\n",this_object());
		destruct(this_object());
	}
	return;
}

void healing(object me)
{
	if (me && environment(me) == environment(this_object()))
	{
		me->delete_temp("入山流/喂蛇药");
		me->delete_temp("入山流/治麻风");
		me->set("入山流/治愈麻风",1);
		message_vision("半柱香的功夫，$N渐渐有了知觉，缓缓睁开双眼。\n",this_object());
		//let him be a prince for ppl who have patience,giggle
		call_out("bePrince",10,me);
		this_object()->set("long","一个身材修长，有着亮若明星双眸的青年。\n");		
		if (!me->query("山流/乞丐奖励"))
			me->set("山流/乞丐奖励",1);
	}
	return;
}


int do_heal(string arg)
{
	object me;
	me = this_player();
	if (arg != "lepra beggar" && arg != "疯乞丐")
	{
		return 0;
	}
	if (me->query_temp("入山流/治麻风"))
	{
		if (present("wang shedan",me) && present("zhuye shedan",me) && present("xiangwei shedan",me))
		{
			message_vision(
HIR"$N吸了口气，喃喃道：听老人说，需要将三大毒蛇胆化于唾液之中，然后以嘴 
喂给病人方能凑效，我倒是救与不救？（decide heal or not）\n "NOR,me);
			//me->delete_temp("入山流/治麻风");
			me->set_temp("入山流/喂蛇药",1);
		}else
			message_vision(
HIR"$n叹了口气，双膝跪地，仔细检查$N的病情，思量了半天，喃喃道：麻风这种
病，听人说必须要有天下三大毒蛇的蛇胆方能药到病除，看来得去找找。。 \n"NOR,this_object(),me);
		//me->set_temp("入山流/找蛇药");
	}else
	{
		message_vision(
WHT"$n犹豫了一下，看着$N的浑身恶疮，不禁直想呕吐，连忙掩住口鼻躲在一边。 \n"NOR,this_object(),me);
	}
	return 1; 
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您好心一定会有好报的！");
        return 1;
}


int accept_fight(object me)
{
     tell_object(me,"有一点同情心好不好，他都快要死了耶\n");
	 return 0;
}
 
