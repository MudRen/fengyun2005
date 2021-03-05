#include <ansi.h>
inherit SMART_NPC;

void create()
{
    set_name("谢掌柜", ({ "xie zhanggui"}) );
    set("gender", "男性" );
    set("age", 42);
	set("title","神剑山庄 第二代无为清静楼掌柜");
    set("long",
        "这就是无为清静楼谢掌柜，大家一般叫他谢先生，据说武功已出神入化。\n");
    set("combat_exp", 4000000);
    set("reward_npc", 1);
    set("difficulty", 5); 
    set("attitude", "friendly");

    set("fly_target",1);
    set("chat_chance", 1);
    set("chat_msg", ({
      		"谢掌柜道：没想到无情小子在三少爷面前居然这么不堪一击。\n",
            "谢掌柜道：你要去隐世楼得赢得了我的"YEL"神机八刀"NOR"才行。\n",
            }) );
    
    set("inquiry",([
    	"神机八刀":	"action谢掌柜冷冷地说：接我一招“计出连环”不死，你就可以去隐世楼了(accept test)。\n",
    ]));	
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shenji-blade",1);
    setup();
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
}


void init()
{
	object me,meizhi;
//	if(interactive(me = this_player()) && !me->is_fighting() && userp(me) && me->query("marks/少林_神剑_燕十三"))
	if(interactive(me = this_player()) && !me->is_fighting() && userp(me))
	{
		remove_call_out("greeting");
		call_out("greeting",2,me);
	}
	add_action("do_answer","answer");
	add_action("do_accept","accept");
}


void greeting(object me)
{
	if (objectp(me) && present(me,environment(this_object())))
	{
		if (!me->query_temp("marks/pass_xiezhanggui"))
		{
			message_vision("$N看了$n一眼，冷冷地说：“凭你的功夫，也想去挑战燕十三？你见过燕十三的剑法吗？”\n",this_object(),me);
			me->set_temp("marks/xie_inask",1);

		}
		
	}
}


int do_answer(string arg)
{
	object me;
	me = this_player();
	if (!me->query_temp("marks/xie_inask"))
	{
		return 0;
	}
	
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("你只可答yes/no \n");
	}
	me->delete_temp("inask");
	if (arg == "yes")
	{
		message_vision("$N眼睛一亮，对$n道：“那你给我看看(show)他的剑法是什么样的？” \n",this_object(),me);
		add_action("do_show","show");
	}else
	{
		message_vision("$N对$n说“你连他的剑法都没见过，就不要去送死了。” \n",this_object(),me);
	}
	return 1;
}


int do_show(string arg)
{
	object me,meizhi;
	me = this_player();
	if (arg != "meizhi" && arg != "削断的梅枝" && arg != "梅枝")
	{
		return 0;
	}
	if (!present("meizhi",me))
	{
		return notify_fail("你身上没有这样东西。\n");
	}
	if (me->query_temp("lookmeizhi")!=2)
	{
		message_vision("谢掌柜大笑道：这小小一段枯枝，连你都不知道是什么，拿给我做甚？\n",me);
		return 1;
	}
	
	message_vision( "$n拿出削断的梅枝，稳稳地横在$N眼前。 
$N看着梅枝的断口，脸色渐渐变得灰暗，失魂落魄的呐呐道：
“第十五剑，第十五剑。。。 你去吧。”\n ",this_object(),me);
	me->set_temp("marks/pass_xiezhanggui",1);
	return 1;

}


int do_accept(string arg)
{
    	mapping guild;
    	int extra,x;	
    	int mgin,mkee,msen;
    	object player, ob, blade;
    	string msg;
    	
    	player = this_player();
    	ob = this_object();	
    		
    	if( arg== "test" )    {
			if (REWARD_D->check_m_success(player,"入隐世楼")) {
				tell_object(player,"谢掌柜沉着脸让到一旁。\n");
				return 1;
			}
			
			if (player->is_busy()|| player->is_fighting()) 	{
	    		tell_object(player,"你现在正忙着，先把手边的事儿料理了吧。\n");
	    		return 1;
	    	}
		
			if (ob->is_busy()|| ob->is_fighting()) {
				tell_object(player,"谢掌柜正忙着呢，没空理你。\n");
				return 1;
			}
			
			if (ANNIE_D->check_buff(ob, "lockup"))
				ANNIE_D->debuff(ob,"lockup");
				
			ob->fight_ob(player);
			player->fight_ob(ob);
			
			if (!(blade=ob->query_temp("weapon"))) {
				blade = new("/obj/weapon/blade");
				blade->set("name",CYN"手刀"NOR);			
				blade->set("nodrop_weapon",1);
				blade->move(ob);
				message_vision(CYN"谢掌柜忽然伸出右手，并指如刀，非金非玉，手刀！\n"NOR, ob);
				message_vision(CYN"谢掌柜道：三十年来，你是第一个迫我使出此式的！接招吧！\n"NOR, ob);
				blade->wield();
				x= 1;
				ob->add_temp("apply/damage",700);
			}
		
			player->perform_busy(1);
			ob->ccommand("perform jichulianhuan");
			player->stop_busy();
			ob->stop_busy();
			ob->remove_all_killer();
			if (x && blade)	destruct(blade);
			if (x)	ob->add_temp("apply/damage",-700);
		
			if (player->query("kee")<0)
				msg = "谢掌柜冷笑道：狂妄之徒，死不足惜。\n";
			else if (player->query("kee")< player->query("max_kee")/4)
				msg = "谢掌柜摇摇头说：如此武功，还是不要来献丑了吧。\n";
			else if (player->query("kee") < player->query("max_kee")/2)
				msg = "谢掌柜摇摇头说：此招接的如此狼狈，怎么能去隐世楼？\n";
			else if (player->query("kee") < player->query("max_kee")*3/4)
				msg = "谢掌柜道：你这工夫么，还缺那么一丁点儿火候。\n";
			else {
				msg = "\n谢掌柜脸色灰暗道：你可以进去了。\n";
				message_vision(CYN+msg+NOR, player);
				REWARD_D->riddle_done(player,"入隐世楼",20);
				return 1;
			}

			message_vision(CYN+"\n"+msg+NOR, player);				
		}
		
		return 1;
}	
		
		
		
		
		
			