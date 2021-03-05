#include <ansi.h>
inherit NPC;
int do_jie(string arg);
void create()
{
        set_name("金狮子", ({ "jin shizi", "jin" }) );
        set("long","他狮鼻阔口，相貌丑陋。尤其是一只大鼻子，占了半张脸的地方，让
人不觉得恐怖，只觉得可笑。\n");
    	set("chat_chance",1);
		set("chat_msg",	({
			"金狮子上上下下打量着你，粗声道：“别乱走，这些天大盗凤栖梧出
没无常，小兔崽子还是回家乖乖呆着去。”\n",
		})  );

        set("combat_exp", 300000);
	
		set_skill("dodge",100);
		set_skill("move",100);
		set_skill("shenji-steps",100);
		set_skill("unarmed",160);
		set_skill("changquan",160);
		set_skill("parry",100);
	
		map_skill("unarmed","changquan");
		map_skill("dodge","shenji-steps");
		map_skill("move","shenji-steps");
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
}

int do_jie(string arg){
	
	object ob, me, yaopai;
	me= this_player();
	
	if (arg == "gaoshi"&&  environment(this_object())->query("gaoshi")) {
		if (REWARD_D->check_m_success(me,"智擒大盗")) {
			command("say 凤栖梧一案已破，您可以自由出入，不必揭告示了。");
			if (!ob=present("yao pai", me)) {
				ob = new(__DIR__"obj/yaopai");
				ob->move(me);
				write("金狮子给"+me->query("name")+"一个腰牌。\n");
			}
			me->set_temp("yaopai",1);
			return 1;
		}
		
		if (!ob=present("yao pai",me)) {
			if (this_player()->query_temp("yaopai"))
				{
				command("say 哎，这可是你自己不要腰牌，怨不得我．．．");
				return 1;
				}
									
			if( time()-(int) this_player()->query("marks/last_time_jiegaoshi") < 1200 ) {
				command("say 你刚刚试过没多久，等会儿再来吧！");
			} else if(present("jia gun", environment())) {
				command("point jia gun");
				command("say 你要证明你的实力，就和他过几招吧，你同意（ａｃｃｅｐｔ）吗？");
				this_player()->set_temp("jiegaoshi",1);
				this_player()->set("marks/last_time_jiegaoshi",time());
			} else {
				message_vision("$N对$n道：夹棍不在，你等会儿再来吧。\n", this_object(), this_player());
			}
		} else if (this_player()->query_temp("yaopai")) 
				command("say 不是已经给过你腰牌了吗？");	
		else 
			command("say 这腰牌是哪里偷来的？快快从实招来，否则就把你抓牢里去！");
		return 1;
	
	}
	return 0;
}

/*
void die()
{
	object ob;
	object *enemy;
	ob = query_temp("last_damage_from");
	if(!ob) { 
		enemy = this_object()->query_enemy();
		if(sizeof(enemy))
			ob=enemy[0];
	} else {
		if(userp(ob)) 	ob->set_temp("marks/killjin",1);
	}
	::die();

}				

*/