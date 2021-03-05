//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit NPC;
#include <ansi.h>

int do_boat();
int do_raft();

void create()
{
	set_name("老掌柜", ({ "old zhanggui", "zhanggui" }) );
	set("gender", "男性" );
	set("age", 69);
	set("long","这位船行的老掌柜正在忙着噼哩啪啦打着算盘算账。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("inquiry",([
		"木筏": (:do_raft():),
		"raft": (:do_raft():),
		"小舟": (:do_boat():),
		"boat": (:do_boat():),
	]));	
				
	set("NO_KILL","杀了他别人怎么去白云岛呢？\n");
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int do_raft(){
	object who;
	int price;
	object paper;
	string msg;
	
	who = this_player();
	
	if (!who->query("env/e_money")) {
		ccommand("say 这个，客官似乎没有四海金卡，小店无法划账啊。");
		return 1;
	}
	
	price = 100;
	
	if (who->query("deposit")< price) {
		command("say 这个，客官好像账面上有点周转不开？");
		return 1;
	}
	
	MONEY_D->charge_him(who,price);
	
	paper = new(__DIR__"obj/contract");
   	paper->set("shiptype", price/500);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say 多谢这位" + RANK_D->query_respect(who) +
	     "光顾本船行，请拿这张租约到码头给老狐狸。\n");
	
	msg = CYN"老掌柜看了看$N，叹口气说：“不过，这海上风高浪急，这位客官恐怕没到白云岛就。。。。”\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"（需60级纵跃闪躲之术方保无恙）\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"（需30级纵跃闪躲之术方保无恙）\n");	
	}	
	    
	return 1;
	
}

int do_boat(){
	object who;
	int price;
	object paper;
	string msg;
	
	who = this_player();
	
	if (!who->query("env/e_money")) {
		ccommand("say 这个，客官似乎没有四海金卡，小店无法划账啊。");
		return 1;
	}
	
	price = 500;
	
	if (who->query("deposit")< price) {
		command("say 这个，客官好像账面上有点周转不开？");
		return 1;
	}
	
	MONEY_D->charge_him(who,price);
	
	paper = new(__DIR__"obj/contract");
   	paper->set("shiptype", price/500);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say 多谢这位" + RANK_D->query_respect(who) +
	     "光顾本船行，请拿这张租约到码头给老狐狸。\n");
	
	msg = CYN"老掌柜看了看$N，叹口气说：“不过，这海上风高浪急，这位客官恐怕没到白云岛就。。。。”\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"（需60级纵跃闪躲之术方保无恙）\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"（需30级纵跃闪躲之术方保无恙）\n");	
	}	
	    
	return 1;
	
}

void init()
{       
	object ob;
	::init();
	if ( interactive(ob = this_player()) && !is_fighting() ) 
	   {
	     remove_call_out("greeting");
	     call_out("greeting", 1, ob);
	   }
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) 
	      {
		case 0:
		message_vision("$N用他的老花眼看了$n一眼，说道：欢迎这位"+RANK_D->query_respect(ob)+
			       "光临本船行！\n",this_object(),ob);
		break;
		
		case 1:
		message_vision("$N轻轻捶了捶发酸的肩膀说道：这位"+RANK_D->query_respect(ob)+
			       "想要租什么样式的船？\n",this_object(),ob);
 		break;
 		
        case 2:
		message_vision("$N说道：如要询问租船的价格，请参看本店的价格牌．．．\n",this_object(),ob);
	      }
}

int accept_object(object who, object ob)
{
	int val;
	object paper;
	string msg;
	
//	message_vision(CYN"$N说：风浪太大，航船暂停。\n"NOR,this_object());
//	return 0;
	val = ob->value();
    if ( val < 100 ) 
	{
		message_vision("$N皱了下眉头道：这位客官，钱不够啊。\n",this_object());
		return 0;
	}
	
	if (val > 1000 )
	{
		  message_vision("$N苦笑道：大海船自从载上次那个四条眉毛的爷出海后，就再也没回来过。哎。。\n",this_object());
			return 0;
	}	
	
	paper = new(__DIR__"obj/contract");
    if ( val>=100 && val < 500 ) 
    	paper->set("shiptype", 0);
    else if ( val >= 500 && val < 10000 ) 
    	paper->set("shiptype", 1);
    else if ( val >=10000) 
    	paper->set("shiptype", 2);
	
	paper->set("employer",who->query("name"));	
	paper->move(who);	
	
	command("say 多谢这位" + RANK_D->query_respect(who) +
	     "光顾本船行，请拿这张租约到码头给老狐狸。\n");
	
	msg = CYN"老掌柜看了看$N，叹口气说：“不过，这海上风高浪急，这位客官恐怕没到白云岛就。。。。”\n"NOR;
	
	if (paper->query("shiptype") == 0 && who->query_skill("dodge",1)< 60)
	{	
		message_vision(msg, who);
		tell_object(who,"（需60级纵跃闪躲之术方保无恙）\n");	
	} else if (paper->query("shiptype") == 1 && who->query_skill("dodge",1) < 30)
	{
		message_vision(msg, who);
		tell_object(who,"（需30级纵跃闪躲之术方保无恙）\n");	
	}	
	    
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
