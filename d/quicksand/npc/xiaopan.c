#include <ansi.h>
inherit NPC;

int answer();

void create()
{
        set_name("小潘", ({ "xiao pan","xiaopan" }) );
        set("title","能言善辩");
        set("gender", "男性" );
        set("age", 42);
	set("long","
这小潘其实早已不是小伙子，至少已有叁十来岁，但却天生着一张娃娃
脸，没说话就先笑，说完了还在笑，教任何人也没法子对他发脾气。\n");
	set("combat_exp", 500000);

	set("inquiry",([
		"沙漠": (: answer() :),
		"desert": (: answer() :),		
		"camel": (: answer() :),
		"骆驼": (: answer() :),
		"骆驼队": (: answer() :),
	]));

	set("chat_chance", 1);
        set("chat_msg", ({
                "小潘陪着笑道：“小人的本事，就是什麽都不会，什麽都不懂，一个人活
到四十多，还是一点本事也没有，这也不是件容易事，您说是麽？”\n",
		"小潘说：“要想太太平平地过沙漠，就得雇我们的骆驼队！”\n",
        }) );
      
	set("attitude", "friendly");
	set("class","baiyun");
	
    	set_skill("unarmed", 100);
    	set_skill("force", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("calligraphy", 120);
    	set_skill("chessism", 150);
    	set_skill("feixian-steps", 80);
	set_skill("move",120);
	
    	map_skill("unarmed", "calligraphy");
    	map_skill("force", "chessism");
    	map_skill("dodge", "feixian-steps");
    	map_skill("move","feixian-steps");

        setup();
        carry_object(__DIR__"obj/scloth")->wear();

}


int answer(){
	message_vision("
小潘说：“要过沙漠？找我就对了！”\n",this_object());
	if (!environment(this_object())->query("route_clear")) {
		message_vision("
小潘唉声叹气地说：“不过，最近路上不太平，我跟太平镇的驿站失了联系，
这骆驼队的生意也做不成了。如果有人能到太平镇那儿去看看就好了。”\n",this_object());
		return 1;
	}
	message_vision("
小潘说：“石驼是这儿最好的车把式儿，只要三两银子，他就能又快又安
全地送你过沙漠。”\n",this_object());
	return 1;
}


int accept_object(object who, object item){
	object ob/*, gold*/;
	
	ob = this_object();
	
	if (!environment(ob)->query("route_clear")) {
		message_vision("
小潘唉声叹气地说：“没用，最近路上不太平，我跟太平镇的驿站失了联系，
这骆驼队的生意也做不成了。如果有人能到太平镇那儿去看看就好了。”\n",this_object());
		return 0;
	}
	if ((item->query("value")<300 && !who->query("石观音/desert_route"))
		|| item->query("value")<300) {
		message_vision("
小潘为难地摇摇头：“这点钱，就是买骆驼草都不够啊！”\n",ob);
		return 0;
	}
	if (who->is_busy()) {
		message_vision("小潘说：“客官似乎还有事儿没了吧？”\n",ob);
		return 0;
	}
		
	message_vision("小潘满脸堆笑地说：“客官，咱们这就上路。”\n",ob);
	message_vision("
石驼从后面牵出一头又大又壮的骆驼，$N一纵身骑了上去。\n",who);
	message_vision("$N高声吆喝：“骆驼队出发喽！”\n",ob);
	who->set_temp("ride","骆驼");
	who->start_busy(16);
	environment()->go_out_1(who, 0);
	return 1;
}

void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		if (environment()->query("route_clear")) return;
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob) {
	
	object gold;
	
	if (!ob || environment() != environment(ob))	return;
			
	if (interactive(ob) && ob->query_temp("quicksand/route_notice")) {
		ob->delete_temp("quicksand/route_notice");
		command("touch "+ob->query("id"));
		command("say 多谢你带来的好消息！路上终于太平了。");
		command("say 这点小意思你就收下吧。");
		
		gold = new("/obj/money/gold");
		gold ->set_amount(5);
		if (!gold ->move(ob))	{
	    	tell_object(ob, HIR"由于你身上的东西带的太多，奖励被没收了。。。\n"NOR);
	    	destruct (gold);
	    } 
	    		
		REWARD_D->riddle_done(ob,"沙漠驼旅", 20, 1);
			
		environment()->set("route_clear",1);
		CHANNEL_D->do_sys_channel("info","往返沙漠的骆驼队又开始启程了！");
		return;
	}
}