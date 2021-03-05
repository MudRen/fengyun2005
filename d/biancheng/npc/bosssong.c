#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();
int kill_him();

void create()
{
    	set_name("宋富贵",({"song fugui","fugui","song"}));
	set("title","棉花行老板");
   	set("long","
宋富贵本来只是个马夫，三十岁那年被棉花行老板的闺女相中作了上门女婿，
这么多年来勤勤勉勉，把个棉花行的生意越做越红，越做越大。\n");
     	
     	set("gender","男性");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",1800000);  
    	set("age",42);
	 	   	
    	set("inquiry", ([
    	    	"山贼" : 	(: show_me :),
             	"bandit" :	(: show_me :),
             	"江湖五毒":	(: kill_him :),
             	"花花道长":	(: kill_him :),
   		]));

    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",

        ]) );    	
    
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
    
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"愁眉苦脸地说：“山贼一天比一天猖獗，我这店怎么还开得下去呵？”\n",
		name()+"拿起棒槌，咚咚地弹了几下棉花。\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","xingyi-stick",1);
	
	setup();
   	carry_object("/obj/armor/cloth")->wear();    
	carry_object("/obj/weapon/staff",([	"name": "棒槌",
    						"long": "一个一头大一头小的棒槌。\n",
    						"value": 0,
    						 ]))->wield();    
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"宋富贵现在没空回答你。\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/棺材之谜")) {
        	tell_object(me,"宋富贵说：没听说过，这名字邪气得紧。\n");
        	return 1;
        }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现在他脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n"NOR,this_object());
        another = new(__DIR__"huahua");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}


int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	
	if (REWARD_D->riddle_check(me,"义助宋福贵")) {
		command("say 唉，山贼不灭，我还有什么可说的呢？");
		return 1;
	}

	command("say 半年前，不知从哪儿来了一伙强人，每到天黑时就在镇口打劫。");
	command("say 镇上的生意一天不如一天，强盗们却越发变本加厉，几天前把我从内地运来的棉籽都抢了。");
	command("sigh");
	command("say 这棉花行看来是开不下去了，这位"+RANK_D->query_respect(me)+"能不能救我一命？(answer)");
	me->set_temp("marks/wanma/answer_song",1);
	return 1;
}


int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(!me->query_temp("marks/wanma/answer_song")) return 0;
	if(arg=="yes" || arg == "能") {
		message_vision(YEL"$N笑着说：宋老板不必烦恼，此事包在咱家身上便是。\n\n"NOR,me);
		command("say 好，好，这伙山贼总是在夜晚出没于镇外，据说有三个首领。");
		command("say 希望你能将他们一举铲除，并找回我的货物。");
		me->delete_temp("marks/wanma/answer_song");
		REWARD_D->riddle_set(me, "义助宋福贵",1);
		return 1;	
	}
	if(arg=="no"|| arg == "不能"){
		message_vision(CYN"$N赶紧摇了摇头说：“在下武艺低微，你还是另请高明吧。”\n"NOR,me);
		message_vision(YEL"$N叹了口气说：“唉，完了！完了！”\n"NOR,ob);
		me->delete_temp("marks/wanma/answer_song");
		return 1;
	}
	tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
	return 1;
}


int accept_object(object who, object ob)
{
	if (ob->name()=="棉籽") {
		if ( sizeof (who->query("marks/longhuzhai"))<3) {
			command("say 谢谢你替我找回了货物，不过，如果不杀尽那几个山贼头子，他们肯定还会回来的。");
			command("sigh");
			return 0;
		} else {
			who->delete("marks/longhuzhai");
			command("touch "+who->get_id());
			command("say 太感谢了，我决不会忘记英雄的大恩大德的！");
			
			REWARD_D->riddle_done(who,"义助宋福贵",20,1);
			
			if (!who->query("marks/e_wanma/义助宋福贵")) {
				who->set("marks/e_wanma/义助宋福贵",1);
				tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
			} 
			
			QUESTS_D->special_reward(who,"义助宋福贵");
			return 1;
		}	
	}
	return 0;
}			

			 

