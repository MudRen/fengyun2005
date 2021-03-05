#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("花满天",({"hua mantian","hua"}));
    	set("title","白衣人");
    	set("long","
他在这里已经站了很久了，雪白的衣服上积满沙土，头发也已被染黄，
可是他的脸却是苍白的，苍白得全无一丝血色。\n");
     	set("gender","男性");
    	set("age",42);
    	 	
    	set("combat_exp",8000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",10);
    	
    	set("inquiry", ([
        		"万马堂" : 	(: show_me :),
             	"马空群" :	 (: show_me :),
   		]));
    	
    	set("death_msg", CYN"\n$N说：功亏一篑，我不甘心啊！ \n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"花满天还站在昨夜同样的地方，甚至连姿势都没有改变过。\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","musician",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("obj/weapon/sword/sword_hua")->wield();    
}


int show_me(){
	object me,ob;
	int norm;
	
	me=this_player();
	ob=this_object();	
	
	if (me->get_id()=="yekai" || me->get_id()=="fu hongxue") {
		command("puke");
		command("say 你以为名气是用面具戴出来的？");
		return 1;
	}
	
	norm = (REWARD_D->check_m_success(me,"义助宋富贵")
			+ REWARD_D->check_m_success(me,"义助小媳妇")
			+ REWARD_D->check_m_success(me,"义助张老实")
			+ REWARD_D->check_m_success(me,"义助陶氏")
			+ REWARD_D->check_m_success(me,"情深似海")
			+ REWARD_D->check_m_success(me,"扫荡僵尸"));
	// 一共有6个途径增加声誉，完成其中6个则能进入万马堂。
	if (norm < 5) {
		command("hmm");
		command("say 我好像没听说过你，三老板请的人，个个都是有头有脸的人物。");
		command("say 你还是先想法子提高你的声誉再来找我吧。");
		tell_object(me,WHT"受万马堂邀请需要五点声誉，你现在在边城的声誉为"+chinese_number(norm)+"点。\n"NOR);
		return 1;
	}
	
	REWARD_D->riddle_done( me, "名扬边城", 100, 1);
		
	message_vision(CYN"$N对$n一拱手：“久仰阁下大名，请至北街口，万马堂有车接迎。”\n"NOR,ob,me);
	return 1;
}