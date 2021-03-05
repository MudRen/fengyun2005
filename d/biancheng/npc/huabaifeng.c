#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("花白风",({"hua baifeng","hua","baifeng"}));
	set("title",YEL"双手如鸡爪的老妇"NOR);
   	set("long","
她脸上蒙着黑纱，黑色的长袍乌云般散落在地上，只露出一双干瘪、苍老、
鬼爪般的手。她双手合什，喃喃低诵，但却不是在析求上苍赐予多福，而
是在诅咒。诅咒着上苍，诅咒着世人，诅咒着天地间的万事万物。\n");
     	
     	set("gender","女性");
     	     	
    	set("age",32); 	 	
    	set("int",52);
    	set("cor",30);
    	set("cps",20);
    	set("str",40);
    	set("per",1);
    	

    	set("combat_exp",1250000);  
    	set("attitude", "friendly");
    	
    	
//    	set("death_msg",CYN"\n$N说：“善者不来，来者不善啊。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
//		"白面郎中道：“我们这里的人本来就不喜欢打架的。”\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
//    	carry_object(__DIR__"obj/gsword")->wield();    
    
}

void init()
{	
	object me;

	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

}

void greeting(object me)
{
	object ob;
	ob=this_object();
	if( !me || environment(me) != environment() ) return;
	if (me->query("marks/wanma/寻地洞") && !me->query("marks/wanma/杀场主_bai")) {
		call_out("event1",1,me,0);	
	}
	if (me->query("marks/wanma/杀场主_bai")
		&& me->query_temp("marks/wanma/杀花满天_bai") && me->query_temp("marks/wanma/杀云在天_bai")
		&& me->query_temp("marks/wanma/杀公孙断_bai") && me->query_temp("marks/wanma/杀马芳玲_bai")
		&& me->query_temp("marks/wanma/杀小虎子_bai") 
		&& !me->query("marks/wanma/准备杀同伙_bai")) { 	
		message_vision(CYN"
花白风点了点头，她的声音凄厉、尖锐，如寒夜中的鬼哭，“马空群，马
空群，你也有今天！”\n"NOR,ob);
		message_vision(CYN"
花白风说：“下一步，就轮到马空群的同伙了，我已经知道的有薛斌和易
大经，你要找出其余的三个，杀光他们的一家老少。”\n"NOR,ob);
		me->set("marks/wanma/准备杀同伙_bai",1);
	}
	if (me->query("marks/wanma/准备杀同伙_bai") 
		&& me->query_temp("marks/wanma/易大经_bai") && me->query_temp("marks/wanma/薛斌_bai")
		&& me->query_temp("marks/wanma/桃花娘子_bai") && me->query_temp("marks/wanma/柳东来_bai")
		&& me->query_temp("marks/wanma/郭威_bai") 
		&& !me->query("marks/wanma/准备杀主脑_bai")) {
		message_vision(CYN"
花白风转过身去，跪在黑色的神龛前，喃喃低语，没有人能听到她在说什么，
片刻，。。\n"NOR,ob);
		me->set("marks/wanma/准备杀主脑_bai",1);
	}	
	if (me->query("marks/wanma/准备杀主脑_bai") && me->query_temp("marks/wanma/杀马空群")
		&& me->query_temp("marks/wanma/杀丁白云") && me->query("marks/wanma/结局_bai",1)){
		message_vision("hmm, what's the reward here?\n",ob);
		me->set("marks/wanma/结局_bai",1);
	}
	return;
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {
        	if(owner=me->query("possessed")) {
			me = owner;
		} 
        	if(me->query("marks/wanma/花白风_ma"))
                        me->set_temp("marks/wanma/花白风_ma",1);
        }
        ::die();
}


string *event1_msg=	({
	CYN"
花白风冷冷地说：“是三娘指点你到这里的吧，我不管你的来历是什么，
只要你能为神刀堂报了这血海深仇，你就是神刀堂的传人。”\n"NOR,

CYN"为了这一天，我已准备了十九年，整整十九年，傅红雪背叛了我，叶开背
叛了我，他们是背叛了神刀堂几十条屈死的冤魂！！！”\n"NOR,

CYN"她的声音里充满了一种神秘的自信，仿佛已融入了天上地下所有神魔恶鬼
的诅咒。”\n"NOR,

CYN"你要记住，从此以后，你就是神，复仇的神！无论你做什么，都用不着后
悔，无论你怎么样对他们，都是应当的！”\n"NOR,

CYN"“不过，我绝不会让马空群死得太快，太容易，我要你先去杀了他的手下，
他的儿子女儿，让他尝尝家破人亡的滋味。\n"NOR,

});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"花白风突又挥刀，一刀插入$N面前的土地上，厉声说道：“快走，用这把
刀将他们的头全都割下来，再回来见我，否则非但天要咒你，我也要咒你！\n\n\n"NOR,me);
		me->set("marks/wanma/杀场主_bai",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}