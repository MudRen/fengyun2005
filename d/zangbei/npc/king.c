inherit SMART_NPC;
#include <ansi.h>

int show_me();

void create()
{
    set_name("龟兹王", ({ "king" }) );
    set("title","富甲天下");
    set("gender", "男性" );
//    set("group","guizi");
    set("age", 52);
    set("per",30);
    set("long","一个卷须虬髯，头戴金冠的红袍人，他高踞在正中的一张低几後，左手拿
着金杯，右手却搂着一个美女的纤腰，开怀大笑。\n");
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("class","lama");	
	set("chat_chance",1);
    	set("chat_msg",({
			"龟兹王大笑道：“无论各位究竟是什麽人，各位的武功才艺，都已令小王
倾倒不已，今日小王能与各位欢聚一堂，小王自己先干三杯为敬。”\n",
			"龟兹王眉间忽有忧色道：“这"YEL"极乐之星"NOR"一失，如何是好？”\n",
    	}) );  
    
    	set("inquiry", ([
        	"极乐之星" : 	(: show_me :),
        	"紫霞":			"极乐之星原是有两粒宝石合成，一名朝阳，一名紫霞。\n",
        	"朝阳":			"极乐之星原是有两粒宝石合成，一名朝阳，一名紫霞。\n",
   		]));
    	
    
    auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_u","kwan-yin-spells",1);    		
	setup();
	carry_object("/obj/armor/cloth",([	"name": "青绸面皮袍",
    						"long": "一件青绸面皮袍。\n",
    						"value": 80,
    						 ]))->wear();    
	carry_object("/obj/armor/hat",([	"name": HIY"镏金冠"NOR,
    						"long": "一顶镶着宝石的镏金冠。\n",
    						"value": 100,
    						 ]))->wear();    
}
	
void init()
{       
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
	        if (!ob->query("zangbei/龟兹_入帐成功")) {
			ccommand("kick "+ob->query("id"));
			message_vision(CYN"龟兹王道：哪里来的小贼，若不是本王今天心情好，这就把你给丢到沙漠里喂蝎子。\n"NOR,ob);
			return;
		}
	
		if (ob->query("gender")=="女性") {
			message_vision(CYN"龟兹王大笑道：各位请看，我们的琵琶公主新浴之後，是不是更美了？\n"NOR,ob);
			return;
		}
	
		message_vision(CYN"龟兹王大笑道：我的好女儿，你带来的这位客人又是谁呢？我记得这里附近几百里
之内，都没有如此英俊的男人呀！\n"NOR,ob);
		return;
        }

}


int show_me(){
	object me;
	
	me= this_player();
	if (REWARD_D->check_m_success(me,"极乐之星")) {
		command("say 谢谢你替我们找回了极乐之星！");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"极乐之星")) {
		message_vision(CYN"
龟兹王看看你，摇摇头说：你这三脚猫的功夫，还管什么闲事儿。\n"NOR,me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"极乐之星")==1) {
		command("sigh");
		message_vision(CYN"
龟兹王长叹道：那『极乐之星』乃是两粒价值连城的宝石所成，一名紫霞，
一名朝阳，乃是我龟兹传国之宝。没料到三月前紫霞竟为人盗走，据说是
大盗凤栖梧所为，这、这可如何是好！\n"NOR, me);
		return 1;
	}
			
	if (me->query_temp("zangbei/龟兹_龟兹送宝")) {
		message_vision(CYN"
龟兹王急切地说：事情办的怎么样了？\n"NOR,me);
		return 1;
	}
				
	if (REWARD_D->riddle_check(me,"极乐之星")==2) {
	message_vision(CYN"
龟兹王长叹道：祸不单行，祸不单行啊，这极乐之星中的朝阳也已落入他人
之手。小王本是委托那彭氏五虎保送的。小王也知道他们十分可靠，是以才
敢将这天大的责任交给他们，想不到的是，这兄弟五人此刻俱已丧命，朝阳
自然也落人别人手中了。如今对方要求十万两黄金来交换，我却没有手下可
以担此重任。壮士可愿意为我护送这笔钱财？\n"NOR,me);
	me->set_temp("zangbei/guizi_talk",1);
	return 1;
	}

	return 1;
}

int do_answer(string arg){
	object me,item;
	me = this_player();
	
	if (!me->query_temp("zangbei/guizi_talk")) return 0;
	if (!arg || (arg!= "yes" && arg!="no")){
		return notify_fail("answer yes 或者 no\n");
	}
	
	if (arg == "no") {
		message_vision(YEL"$N吓得一激灵，赶忙不作声了。\n"NOR,me);
		me->delete_temp("zangbei/guizi_talk");
		return 1;
	}
	
	if (arg == "yes"){
		message_vision(YEL"$N拍拍胸脯说：这事儿就包在咱家身上了。\n"NOR,me);
		me->delete_temp("zangbei/guizi_talk");
		command("touch "+me->query("id"));
		item = present("cun piao",this_object());
		if (!item) item = new(__DIR__"obj/cundan");
 		item->set("item_owner",me);
		if (item->move(me)){
			message_vision(CYN"
龟兹王拿出一物说：好，这是中原南宫钱庄的存票，由此西行五十里的沙漠
中，对方自然有人接应于你。\n"NOR,me);
			me->set_temp("zangbei/龟兹_龟兹送宝",1);
		} else {
			message_vision("龟兹王说：不过，你身上好像没地方携带我的东西。。\n",me);
			destruct(item);
		}
		return 1;
	}

	return 1;
}

int accept_object(object me, object item){
	object real_gem;
	mapping data;
	
	if (REWARD_D->check_m_success(me,"极乐之星"))	return 0;
		
	if (item->name()==HIM"极乐之星"NOR) {
		if ( item->query("item_owner")!=me) {
			message_vision(CYN"
龟兹王说：这"HIM"极乐之星"NOR+CYN"虽然来路不明，物归原主我也就不挑剔了，
龟兹王说：快走快走，否则我就报官了！\n"NOR,me);
			return 1;
		}
		
		message_vision(CYN"
龟兹王说："HIM"极乐之星！极乐之星！"NOR+CYN"你竟然找到了这紫霞，太谢谢了！\n"NOR, me);
		REWARD_D->riddle_set(me,"极乐之星",2);
		command("say 可惜，"HIY"极乐之星"NOR+CYN"还流失在外，没有了它，我复国无望啊！");
		return 1;
	}
	
	if (item->name()==HIY"极乐之星"NOR ) {
 if (item->query("item_owner")!=me || !me->query_temp("zangbei/龟兹_还极乐")) {
			message_vision(CYN"
龟兹王说：这极乐之星虽然来路不明，物归原主我也就不挑剔了，
龟兹王说：快走快走，否则我就报官了！\n"NOR,me);
			return 1;
		}
		command("touch "+me->query("id"));
		message_vision(CYN"
龟兹王大笑道：多亏你的帮助，我可以找到历祖的宝藏，复国指日可待。\n"NOR,me);
		REWARD_D->riddle_done( me, "极乐之星", 50, 1);
		data = ([
			"name":		"极乐之星",
			"target":	me,
			"att_1":	"agi",
			"att_1c":	1,
			"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);	
		
		return 1;
	}
	message_vision(CYN"
龟兹王说：我只想找回我那货真价实的极乐之星。\n"NOR,me);
	return 0;
}		

