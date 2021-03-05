#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("陶保义",({"tao baoyi","tao","baoyi"}));
		set("title","忧心忡忡");
   		set("long","陶保义是赶车的把式，自从前年媳妇得了种怪病，到处投医，家里变得越来越穷。\n");
     	
     	set("gender","男性");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",600000);  
    	set("age",42);
    	   	
    	set("inquiry", ([
        	"陶氏" : 	(: show_me :),
             	"媳妇" :	 (: show_me :),
             	"怪病" :	 (: show_me :),
             	"病" :		 (: show_me :),
             	"新药" :	 (: show_me :),
             	"药" :	 	(: show_me :),
             	"药方" :	"这药方要龙鲤鱼作药引子，我上哪儿去找呀？\n",
             	"龙鲤鱼" :	"我上哪儿去找龙鲤鱼呀？\n",
             	"药引子" :	"我上哪儿去找龙鲤鱼呀？\n",
             	"赛华佗" :  "风云城里的医生，你没听说过？\n",
   		]));

    	set("death_msg",CYN"\n$N恨恨地说：“你的心真狠，连穷人都不放过。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"叫道：“来人啊，强盗上门抢劫啦！”\n",

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
//		name()+"捶着脑袋长呼短吁地说：“看来孩子他娘是熬不过这个大年了。。”\n",
    	}) );    	    	
    	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
}



int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	if (REWARD_D->check_m_success( me, "义助陶氏")) {
		command("say 多亏你找来了药引子，我媳妇现在病好多了，赶明儿咱们再添个大胖小子。");
		return 1;
	}
	command("say 自从我媳妇得了这病，也不知看了多少名医，吃了多少方子，却没什么用处。");
	command("say 我到内地跑了一次，终于在风云城找到了“赛华佗”，他给了我一张药方。");
	command("say 不过，这药方要龙鲤鱼作药引子，我上哪儿去找呀？");
	command("cry tao baoyi");
	return 1;
}



int accept_object(object who, object ob)
{

	string *mbook = ({"hammer_50","throwing_50","axe_50","staff_50","whip_50" });
	object book;
	
	if (ob->name()==HIY"龙鲤鱼"NOR) {
		command("touch "+who->get_id());
		command("say 太感谢了，我决不会忘记英雄的大恩大德的！");
	
		book = new(BOOKS+mbook[random(5)]);
		if (objectp(book)) {
			if (sizeof(all_inventory(who))<14){
				book->move(who);
				ccommand("say 这本我家传的健身要诀就给你吧。\n");
				tell_object(who,"陶保义从箱子里拿出一本旧旧的小册子给你。\n");
			} else
				destruct(book);
		}			
			
		REWARD_D->riddle_done( who, "义助陶氏",20, 1);
		
		if (!who->query("marks/e_wanma/义助陶氏"))
		{
			who->set("marks/e_wanma/义助陶氏",1);
			tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
		}
		
		
		QUESTS_D->special_reward(who,"义助陶氏");
		return 1;		
	}
	return 0;
}			

			 

