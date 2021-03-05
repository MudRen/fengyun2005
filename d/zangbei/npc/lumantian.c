#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("陆漫天",({"lu mantian","lu"}));
	set("title","铁胆");
	set("long","
这人的身材高大，很魁伟穿着件淡青色的长袍，花白的头发挽了发髻，手
里叮当作响，像是握着两枚铁胆。\n");
   	
     	set("gender","男性");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 				"无名老人":	(: kill_him :),
   		]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","longfenghuan",1);
	
	setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
	carry_object("/obj/weapon/hammer/tiedan")->wield(); 
}

int kill_him(){
	object me, ob;
	me = this_player();
	ob = this_object();
	
		if (!me->query_temp("marks/kuaihuo/快活林_陆漫天")) {
			message_vision(CYN"陆漫天说：我不知道你在说些什么。\n"NOR,ob);
			return 1;
		}
		
		if (REWARD_D->riddle_check(me,"菊园传奇")<8){
			command("haha");
			command("say 你一个刚入菊园的小子，寸功未立，却敢来指证我陆漫天！");
			command("heng");
			return 1;
		}
		
		if (REWARD_D->riddle_check(me,"菊园传奇")== 9) {
			command("hehe");
			command("say 孙玉伯阴险狡诈，善得人心，你我需谋定而后动！");
			return 1;
		}
					
		message_vision(CYN"陆漫天的目光更冷，瞪着$n，瞪了很久才沉声道；“你巳知我是谁，我也知道你是
谁，既然我的秘密已经被你撞破，我们共同的敌人是孙玉伯，那么就合作吧。\n"NOR,ob,me);
		tell_object(me,WHT"\nanswer yes/no\n"NOR);
		me->set_temp("zangbei/lumantian_talk",1);
		add_action("do_answer","answer");
		return 1;
}

int do_answer(string arg){
	object me, ob;
	me = this_player();
	ob = this_object();
	
	if (!me->query_temp("zangbei/lumantian_talk"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no ");
	
	if (arg == "yes") {
		me->ccommand("touch "+ob->query("id"));
		message_vision(YEL"
$N点点头说：正当如此，你我需等待时机，切不可轻举妄动。\n"NOR,me);
		REWARD_D->riddle_set(me,"菊园传奇",9);
//		me->set("marks/kuaihuo/陆漫天",2);
		return 1;
	}
	
	if (arg == "no") {
		message_vision(YEL"
$N正色道：我受老伯重托护卫菊园，怎可容你？\n"NOR,me);
		me->kill_ob(ob);
		ob->kill_me(me);
		REWARD_D->riddle_set(me,"菊园传奇",10);
//		me->set("marks/kuaihuo/陆漫天",1);
		return 1;
	}
	me->delete_temp("zangbei/lumantian_talk");
	return 0;
}


		
void die(){
	 object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
		
		} 
        
        if (me)
        if (REWARD_D->riddle_check(me,"菊园传奇")==10)
        	REWARD_D->riddle_set(me,"菊园传奇",11);
/*        
        if(me->query("marks/kuaihuo/夜见黑影"))
        {
                me->set("marks/kuaihuo/菊园刺客",1);
        }*/
        ::die();
}	