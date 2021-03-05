// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
int tell_him();
int wakeup(object me);
int warning();

void create()
{
    	set_name("袁姬", ({ "queen yuanji","yuanji" }) );
    	set("gender", "女性" );
    	set("long","袁姬是米公公出巡时替皇上选的秀女，不日便要送入宫中。\n");
    	set("age", 25);
    	set("combat_exp", 7000);
    	set("attitude", "friendly");
    	set("per",30);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        		"袁姬满脸惆怅，轻轻地叹了口气．．．心里似乎有化不开的愁。\n",
        		"袁姬黯然道：公子，只有来生再见了。\n",
        }) );
    	set("inquiry", ([
        	"清波公子" : (: tell_him :),
        	"公子" :  	(: tell_him :),
        	"qingbo" : 	(: tell_him :),
        	"警告":		(: warning :),
        	"恩人":		"如果你能让我和清波公子团聚，你就是我们的大恩人。\n",
        	"大恩人":	"如果你能让我和清波公子团聚，你就是我们的大恩人。\n",
        ]));

    	setup();
    	carry_object(__DIR__"obj/scloth")->wear();
}

int warning(){
	
	object me= this_player();
	object dai;
	
	
	if (query("drugged")){
		message_vision(CYN"袁姬痴痴地看着$N，笑笑，似乎不知道你在说些什么。\n"NOR, this_player());
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"魂断鹊桥")
		|| REWARD_D->riddle_check(me,"魂断鹊桥")!=10
		|| REWARD_D->riddle_check(me,"局中局")!= 1)
	{
		command("doubt");
		return 1;
	}
	
	command("doubt");
	
	tell_object(me,YEL"忽然身后风声簌簌，你觉得后心一凉，竟是被点了穴道，动弹不得。\n"NOR);
	me->start_busy(10);		// 别跑
	
	dai = new(__DIR__"gaibang3");
	if (dai) dai ->move(environment());
	
	message_vision("\n戴寅走了过来。\n",dai);
	message_vision("\n戴寅悄悄地把麻沸散塞到袁姬手中。
	
袁姬感激地看了戴寅一眼，一口将药粉吞了下去。\n\n",dai);

	
	message_vision(CYN"袁姬哀哀地叫了一声：公子，我来找你了！
	
袁姬一头栽到地上死了。\n"NOR, me);

	if (dai)	destruct(dai);
	set("NO_KILL","如此楚楚可怜的女子，你怎么下得了手！\n");
	set("drugged",1);
	set_temp("is_unconcious",1);
	disable_player(" <假死中>");
	set("disable_type",HIG "<假死中>" NOR);
	call_out("wakeup", 10, me);
	
	tell_object(me,WHT"\n（你心中狂吼，却一个字也吐不出来！）\n\n"NOR);
	return 1;
	
	
}


int tell_him(){
	
	if (!query("drugged"))
	{
		command("say 公子，只有来生再见了。");
		return 1;
	}
	
	message_vision(CYN"袁姬痴痴地看着$N，笑笑，似乎不知道你在说些什么。\n"NOR, this_player());
	return 1;
}

int accept_object(object me, object ob) {
	
	if (is_fighting())	return 0;
		
	if (REWARD_D->check_m_success(me,"魂断鹊桥"))
	{
		command("doubt");
		return 0;
	}	
	
	if (query("drugged"))
	{
		message_vision("袁姬痴痴地朝$N笑了笑说：我就要进宫了，宫里什么都有。\n",me);	
		return 0;
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥") == 9)
	{
		command("pei");
		command("say 你是那米公公的帮凶么，不见到公子，我不会要任何东西。");
		return 0;
	}	
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")!= 10)	return 0;
	
	if (ob->query("name")!= "麻沸散" || ob->query("real")!=2) return 0;
		
	tell_object(me,YEL"你趁人不注意，悄悄地把麻沸散塞到袁姬手中。
	
袁姬感激地看了你一眼，一口将药粉吞了下去。\n\n"NOR);

	
	message_vision(CYN"袁姬哀哀地叫了一声：公子，我来找你了！
	
袁姬一头栽倒地上死了。\n"NOR, me);

	set("NO_KILL","如此楚楚可怜的女子，你怎么下得了手！\n");
	set("drugged",1);
	set_temp("is_unconcious",1);
	disable_player(" <假死中>");
	set("disable_type",HIG "<假死中>" NOR);
	call_out("wakeup", 10, me);
	me->start_busy(10);		// 别跑
	tell_object(me,WHT"\n你心中大喜：终于大功告成了！\n"NOR);
	return 1;
}
	
int wakeup(object me){
	
	object mi, gold;
	
	mi = present("mi gonggong");
	
	message_vision("袁姬嘤咛一声，慢慢地从地上坐了起来。。。。\n\n", this_object());
	delete_temp("is_uncooncious");
	delete("disable_type");
	
	if (!me || environment(me) != environment())	{
		delete("NO_KILL");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"局中局")) {	
		tell_object(me,WHT"你心中一惊：这个，好像有点不太对头，药性过去也太快了！\n"NOR);
	}
	
	message_vision(CYN"
只听旁边亟亟亟几声尖笑，米公公慢慢地踱了过来！
	
米公公说：袁姑娘，时辰已到，咱们该进宫了，从此荣华富贵，享用不尽。

袁姬似乎有些糊涂：进宫？我是谁？公公你是？

米公公击掌道：这"YEL"忘忧散"CYN"果然名不虚传！小子，你立大功了！\n\n",me);


	if (REWARD_D->riddle_check(me,"局中局")==1) {
		message_vision("米公公对戴寅说：不错，黄金五十两就是你的赏头。\n"NOR, me);
	}
	else
	{
		message_vision("米公公对$N说：不错，黄金五十两就是你的赏头。\n"NOR, me);
		gold= new("/obj/money/gold");
		gold->set_amount(50);
		if (!gold->move(me))
		gold->move(environment());
	}		
	
	message_vision(YEL"\n\n米公公弹指放出一只绿色的信鸽，唿哨一声，带着袁姬上轿飞驰而去。\n\n", me);
	
	if (REWARD_D->riddle_check(me,"局中局")==1) {
		
		tell_object(me,CYN"戴寅淡淡道：你无须怨我，袁姬忘却过去，于人于己，未必不是解脱。
行侠仗义，本非黑白分明之事。说罢，拍开你的穴道，绝尘而去。\n\n"NOR);
		
		REWARD_D->riddle_done(me,"魂断鹊桥", 0, 2);
		REWARD_D->riddle_set(me,"局中局",2);
				
		tell_object(me,WHT"\n事到如今，你忽然"YEL"悟"WHT"出了任慈话中的含义。\n\n"NOR);
		
		
	} else 
	{
		tell_object(me,WHT"你忽然明白，原来这从头到底就是一个局，而你就是这局中的一步棋！
	
你心中大悔，可是，已经无法挽回了。。。。。\n"NOR);
		REWARD_D->riddle_done(me,"魂断鹊桥", 50, 1);
	}
		
	destruct(mi);
	destruct(this_object());
}

	
	



	

	