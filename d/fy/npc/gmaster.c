// teacher.c
//Modified by justdoit 04/11/2001

inherit NPC;
#include <ansi.h>

int test_dart();
void create_level(object me, object who,string name, int exp);

void create()
{
        set_name("查猛", ({ "zha meng", "meng" }) );
    	set("long","
金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
凡是想向他求教的，只要为镖局[37m出力[32m，他就肯教。
（ａｓｋ　ｍｅｎｇ　ａｂｏｕｔ　ｗｏｒｋ）\n"
        );
    	set("nickname", HIY "金狮掌"NOR);
    	set("gender", "男性" );
    	set("age", 32);
    	create_family("少林", 21, "俗家弟子");
    	set("skill_public",1);
    	set("reward_npc", 1);
    	set("difficulty", 4);
    	set("attitude", "peaceful");
    	
       	set("inquiry",	([
        	"mission" : 	(: test_dart :),
        	"护镖" : 	(: test_dart :),
		 "功夫": 	"货仓里正缺人手，你去帮些忙吧，完事了我教你两手。
（ｌｅａｒｎ　ｘｘｘ　ｆｒｏｍ　ｚｈａ　ｍｅｎｇ　ｗｉｔｈ　１）\n",
		 "出力": 	"货仓里正缺人手，你去帮些忙吧，完事了我教你两手。
（ｌｅａｒｎ　ｘｘｘ　ｆｒｏｍ　ｚｈａ　ｍｅｎｇ　ｗｉｔｈ　１）\n",
		 "work": 	"货仓里正缺人手，你去帮些忙吧，完事了我教你两手。
（ｌｅａｒｎ　ｘｘｘ　ｆｒｏｍ　ｚｈａ　ｍｅｎｇ　ｗｉｔｈ　１）\n",
		 "job": 	"货仓里正缺人手，你去帮些忙吧，完事了我教你两手。
（ｌｅａｒｎ　ｘｘｘ　ｆｒｏｍ　ｚｈａ　ｍｅｎｇ　ｗｉｔｈ　１）\n",
		 "chufeng":	"学了我的罗汉拳，就能用这招雏凤展翅（ｐｅｒｆｏｒｍ　ｃｈｕｆｅｎｇ）",
		 "雏凤展翅":	"学了我的罗汉拳，就能用这招雏凤展翅（ｐｅｒｆｏｒｍ　ｃｈｕｆｅｎｇ）",
		 "罗汉拳":	"学了我的罗汉拳，就能用这招雏凤展翅（ｐｅｒｆｏｒｍ　ｃｈｕｆｅｎｇ）",
		 "悠游无尘步":   "action查猛摇摇头说，悠游无尘步虽然不俗，却没什么特殊招式。\n",
		 "wuchen-steps":   "action查猛摇摇头说，悠游无尘步虽然不俗，却没什么特殊招式。\n",
	]) );
    	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"查猛说道：这个月镖局生意不错！\n",
            	"查猛说道：护镖（ｍｉｓｓｉｏｎ）的事．．．．\n",
            	"查猛说道：这一招“雏凤展翅”（chufeng）乃是罗汉拳的精髓！\n",
            	"查猛说道：小子，看你筋骨不错，想学功夫么？\n",
            }) );
    	  
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
          (: perform_action, "unarmed.chufeng" :)
        }) );
    	
    	set_skill("unarmed", 100);
    	set_skill("literate", 100);
    	set_skill("force", 100);
    	set_skill("dodge",100);
    	set_skill("move", 100);
    	set_skill("parry",100);
    	set_skill("wuchen-steps",200);
    	set_skill("luohan-quan",200);
    	set_skill("foreknowledge",100);
    	set_skill("chanting",100);
    	set_skill("perception",100);
    	map_skill("unarmed", "luohan-quan");
    	map_skill("dodge","wuchen-steps");
    
    	set("combat_exp", 3500000);
    	setup();
    	carry_object(__DIR__"obj/jinzhuang")->wear();
}

int recognize_apprentice(object ob)
{
    	if((time() - ob->query("marks/金狮") ) > 1800  ){
        	say("查猛说道：你．．你好象很久没为镖局出过力了....\n");
        	return 0;
    	}
	return 1;
}

int test_dart()
{
    	object me;
	
    	me=this_player();
    	if (query("marks/gived")+600> time() )
    	{
        	command("say 我们镖局现在没有你要护的镖。");
        	return 1;
    	}
    	command("say 现在南宫钱庄有一笔镖银需要运到沉香镇，你可愿意协助我们？(accept mission)");
    	add_action("do_accept", "accept");
    	return 1;
}

int do_accept(string arg)
{    
    	object ob,cart,biaotou;
    	object me,*team;
    	int i, exp;	
    
    	if (arg != "mission") return 0;
    
    	me=this_player();
    	team=me->query_team();
    	if (sizeof(team)==0) team=({me});

   		if (sizeof(team) != 0 && (team[0]!=me)) 
        	return notify_fail("只有队伍首领才能提出接镖。\n");
	
    	for (i=0;i<sizeof(team);i++)
    	{
        	if (!intp(team[i]->query("deposit")) 
        		|| team[i]->query("deposit")<200000)
        	{
            		command("say 护镖是危险的事，我看"+RANK_D->query_respect(team[i])+"没有赔偿能力。");
            		return 1;
        	}
    		if (team[i]->query("combat_exp")>exp)
    		exp= team[i]->query("combat_exp");
    	} 

		if (exp < 1000000){
            command("say 护镖路途危险，我看这位小朋友似乎不宜！（队伍中最高经验需要28级以上）");
            return 1;
        }
			
//begin: modified by justdoit
	if (query("marks/gived")+ 600 > time())	{
		 command("say 你来晚了，已经有人接下这支镖了。");
		 return 1;
	}
//end: modified by justdoit

    	set("marks/gived",time());
    	command("say 好吧。跟着李镖头走吧。");
    	command("say 丢镖可是要赔双份的，一路小心。");
    
    	me->set("marks/接镖",time());	
    	say("一队镖车从内院驶出。\n");
	
    	ob=new(__DIR__"obj/cart");
    	ob->move(environment());
    	cart=ob;
	
    	biaotou=new(__DIR__"biaotou");
    	biaotou->move(environment());
    	biaotou->get_quest("/d/fy/cartway1");
    	biaotou->set_cart(cart);
    	biaotou->set_protector(team);
    	biaotou->set("combat_exp",exp);
    	create_level(me,biaotou,"biaotou",exp);
	
    	ob=new("/d/fy/obj/biaoyin");
    	ob->set_amount(10+random(10));
    	ob->move(cart);
	
    	ob=new(__DIR__"biaoshia");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);	
    	create_level(me, ob,"biao",3*exp/4);
 
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);		
	
    	ob=new(__DIR__"biaoshi1a");
    	ob->move(environment());
    	ob->set_leader(biaotou);
    	ob->set_temp("protecting",cart);
    	ob->set("combat_exp",exp/2);
    	create_level(me, ob,"biao",3*exp/4);	
    
    	for(i=0;i<sizeof(team);i++)
       		team[i]->set_temp("protecting",cart);
    	
    	me->set_temp("protecting",cart);
    	me->set_leader(biaotou);
    	biaotou->go_now();
    	return 1;	
}

void reset()
{
    	delete("marks/gived");
}



void create_level(object me, object who,string name, int exp)
{
 	int level;
 	level=100+130*(exp-1000000)/5500000;
 	if (exp<1000000) level=100;
 	if (exp>6400000) level=230;
 	level=level*level/100;
 	if (name=="biaotou") {
	 	who->set("toughness",200);
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")/2);
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	} 	
 	if (name=="biao") {
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi"));
    	who->set("str",who->query("str"));
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
		return;
	}
	if (name=="gangster" || name == "gangsterboss") {
		who->set("toughness",70);
    	"/feature/nada"->reset_npc(who);
    	who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")*3/4);
    	who->full_me();		
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("blade",70+random(level/2));
		who->set_skill("demon-steps",70+random(level/2));
		who->set_skill("unarmed",70+ random(level/2));
		who->set_skill("demon-strike",50+random(level/8));
		who->set_skill("demon-blade",50+random(level/8));
		return;
	}

}