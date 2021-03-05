#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("大肚子的小媳妇",({"pregnant woman","woman"}));
		set("long","一个穿着一身红缎子衣服的小媳妇，挺着个大肚子正在和店里的伙计讨价还价。\n");
     	
     	set("gender","女性");
    	set("attitude", "friendly");
    	    	
    	set("combat_exp",200000);  
    	set("age",22);
    	   	
		set("inquiry", ([
        	
   		]));

    	set("death_msg",CYN"\n$N说：“天哪！这不是一尸两命么。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"叫道：“来人啊，强奸啦！”\n",

        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"拿起一块缎子揉了揉说：“这块吧？还是那块？”\n",
    	}) );    	    	
    	
		setup();
		set("cloth_code",4);
    	carry_object("/obj/armor/cloth",([	"name": "丝缎衣",
    						"long": "一件丝缎小衣，做工精巧。\n",
    						 ]))->wear();    
}

void init()
{	
		object ob;
		
		::init();
		if( interactive(ob = this_player()) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
		add_action("do_answer", "answer");
}

void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
	if (REWARD_D->check_m_success( me, "义助小媳妇")){
		command("xixi "+me->get_id());
		return;
	}
	
	if ( REWARD_D->riddle_check( me, "义助小媳妇")==1) {
		message_vision(CYN"$N对$n说：改主意了吗？能替我买下这布料么？\n"NOR,this_object(),me);
		return;
	}
	
	if (me->query("timer/wanma/answer_preg")+900 > time()) {
		message_vision("小媳妇扭过头去，对$N不理不睬。\n",me);
		return;
	}
	
	message_vision(CYN"$N一把拉住$n的手说：“这位"+RANK_D->query_respect(me)+"替我出个主意吧。”\n"NOR,this_object(),me);
	message_vision(CYN"$N说：“你说我是买这红的呢，还是蓝的，或者是绿的，黄的？”\n",this_object());
	tell_object(me,YEL"（answer red/blue/green/yellow/dunno） \n"NOR);
	me->set_temp("wanma/answer_preg",1);
}

int do_answer(string arg)
{
	object me,ob,huoji;
	
	me=this_player();
	ob=this_object();	
	
	if(!me->query_temp("wanma/answer_preg")) {
		command("say 我又没问你，你瞎掺乎什么?");
		return 1;
	}
	
	if(	(arg=="red" && ob->query("cloth_code")==0)
		|| (arg=="blue" && ob->query("cloth_code")==1)
		|| (arg=="green" && ob->query("cloth_code")==2)
		|| (arg=="yellow" && ob->query("cloth_code")==3)	) {
		command("say 哎呀，您可真是猜到我心坎里去了。");
		command("say 我就要这个了。");
		command("say 不过,我今儿个忘了带金子，你借我三两吧，知音难觅呀。");
		me->delete_temp("wanma/answer_preg");
		REWARD_D->riddle_set(me,"义助小媳妇",1);
		return 1;	
	}
	if ( arg == "dunno" && (ob->query("cloth_code")==4 || !ob->query_temp("armor/cloth"))) {
		command("say 恩，我也拿不定主意，这些我都不喜欢。");
		command("say 等下货来了再说吧。");
		me->delete_temp("wanma/answer_preg");
		return 1;	
	}
	
	if (arg=="yellow" || arg=="blue" || arg=="green" || arg =="red" || arg=="dunno") {
		message_vision(CYN"$N想了想，摇了摇头说：“不好不好。”\n"NOR,this_object());
		message_vision(CYN"$N转过头去不搭理$n了。\n",this_object(),me);
		me->delete_temp("wanma/answer_preg");
		me->set("timer/wanma/answer_preg",time());
		huoji=present("huo ji",environment(this_object()));
		if (huoji) 
		{
			message_vision(CYN"\n$N拍了拍$n的肩头说：“替女人买东西，不容易吧！”\n"NOR,huoji,me);
			message_vision(CYN"\n$N喃喃地说：一个男人若是能活六十年．至少有十年光阴是白白浪费了的。
这十年中，起码有五年是在等女人换衣服。

$n忍不住问道：还有五年呢？
			
$N叹了口气说：你一定要听，我就说，还有五年是在等女人脱衣服。\n"NOR, huoji, me);
			
			return 1;
		}
	}
	tell_object(me,"你只能回答 answer red/blue/green/yellow/dunno \n");
	return 1;
}

int accept_object(object who, object ob)
{
	if (REWARD_D->riddle_check(who, "义助小媳妇")!= 1) {	
//	if (!who->query("marks/wanma/答小媳妇")) {
		command("say 我是规规矩矩人家出来的，怎么可以乱拿别人的钱呢？");
		return 0;
	}
	if (ob->value()>=30000) {
		command("touch "+who->get_id());
		command("say 太感谢了，你比我家那口子大方多了，我决不会忘记你的！");
		command("kiss "+who->get_id());
		
		if (!REWARD_D->check_m_success( who, "义助小媳妇"))
		{
			REWARD_D->riddle_done( who, "义助小媳妇",20, 1);
			who->set("marks/e_wanma/义助小媳妇",1);
			tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
		}
		
		return 1;		
	} 
	command("say 这点钱不够买布呀。");
	command("addoil "+who->get_id());
	return 0;
}			

			 

