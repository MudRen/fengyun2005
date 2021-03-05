#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int test_dart();
void create_level(object me, object who,string name, int exp);

void create()
{
    	set_name("胖子",({"fatman"}));
	set("title","立地成佛");
   	set("long","
一个人若长得太胖，做的事总难免会显得有点愚蠢可笑。这胖子笨头笨脑，
正半靠在桌上打瞌睡。然而，三年前，江湖上有一个可怕的组织叫“黑手”，
干的是绑票、勒索、暗杀。一双手有五根手指，这组织也有五个首脑。这胖
子就是拇指，黑手的拇指。不过，据说他攒够了钱，就到这小镇上开了个茶
铺，过起了太平日子。
\n");
     	set("gender","男性");
    	set("age",42);
    	
    	set("reward_npc",1);
    	set("difficulty",2);
	
    	set("combat_exp",4500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
        	"强盗" : 	"镇外有强盗，镇内也有强盗，这日子可怎么过下去呀！\n",
            "镇外的强盗" : 	"还不就是龙虎寨的那些山贼么！\n",
            "镇内的强盗" : 	"哈哈，就是那胡歪瓜么，那小子可不敢惹我。\n",
			"拇指":	(: message_vision("胖子赔笑道：客官开玩笑吧，小的这儿不是修指甲的。\n",this_object()) :),
			"黑手":		"我的手很干净呀，客官想干嘛？\n",
			"escort":		(: test_dart :),
			"护送":			(: test_dart :),
			"job":			(: test_dart :),	
			"帮忙":			(: test_dart :),
			"树欲静而风不止啊":		(: test_dart :),
   		]));
    	
    	set("death_msg",CYN"\n$N懊恼地说：“报应啊报应！”\n"NOR);  	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(20) :),
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"胖子醒了，先伸了个懒腰，再倒了碗茶漱口，“噗”的把一口茶喷在地上。\n",
			"胖子一指顶着茶壶底，滴溜溜地转了个圈子，竟是滴水不溅！\n",
			"胖子望着窗外喃喃地说：树欲静而风不止啊！\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
		setup();
    	set("force",query("max_force")*2);
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/teapot")->wield();
}


int test_dart()
{
    	object me;
	
    	me=this_player();
    	if (query("marks/gived") )
    	{
        	command("say 没事儿，没事儿，天下太平。");
        	return 1;
    	}
    	
    	command("say 哎呀，这店里的事儿实在忙得走不开。");
    	command("say 今天我女儿去寺里上香，万一出了意外可怎么办。");
    	message_vision(CYN"胖子看了看$N说：这位"+ RANK_D->query_respect(me) + "，若是你也去寺里，能不能顺途照看一下我闺女儿？\n"NOR,me);
    	command("say (accept mission)");
    	add_action("do_accept", "accept");
    	return 1;
}

void reset()
{
    	delete("marks/gived");
}


int do_accept(string arg) {
		object me;
		me=this_player();
		
    	if (arg != "mission") return 0;

		if (query("marks/gived"))	{
			 command("say 啊呀，刚托付了别人，谢谢你了。");
			 return 1;
		}
		
		command("say 我有两个闺女儿，大女儿（ｌａｄｙ）调皮，小女儿（ｇｉｒｌ）文静，你想陪那个去呢？");
		me->set_temp("marks/biancheng/fatman_1",1);
		add_action("do_answer","answer");
		return 1;
}
		
	

int do_answer(string arg)
{    
    	object ob,cart,escortee;
    	object me,*team;
    	int i, exp;	
    
    	me=this_player();
    	
    	if (!me->query_temp("marks/biancheng/fatman_1"))	return 0;
    		
    	if (arg != "girl" && arg!="lady") return 0;

		if (query("marks/gived"))	{
			 command("say 啊呀，刚托付了别人，谢谢你了。");
			 return 1;
		}
    
    	
    	team=me->query_team();
    	
    	if (sizeof(team)==0) team=({me});

   		if (sizeof(team) != 0 && (team[0]!=me)) 
        	return notify_fail("只有队伍首领才能接受此任务。\n");
	
    	for (i=0;i<sizeof(team);i++)
    	{
        	if (team[i]->query("combat_exp")<3000000)
        	{
            	command("say 这位"+RANK_D->query_respect(team[i])+"功夫不行，我可不放心！");
            	return 1;
        	}
    		if (team[i]->query("combat_exp")>exp)
    		exp= team[i]->query("combat_exp");
    	} 

    	set("marks/gived",1);
    	
    	if (arg == "lady")
    		command("say 太好了，这一路上我大闺女儿就靠你照看了。");
    	else
    		command("say 太好了，这一路上我小闺女儿就靠你照看了。");
    		
   	    me->delete_temp("marks/biancheng/fatman_1");
   	    	
    	say("内屋蹦蹦跳跳地跑出个胖胖的姑娘。\n");
	
		// 产生escortee
       	escortee = new(__DIR__"fatmom");
       	escortee->move(environment());
       	
       	     	     	       	
       	// 设置 escortee 属性
    	escortee->set("combat_exp",exp*3/4);
    	"/feature/nada"->reset_npc(escortee);
    	
    	if (escortee->query("max_kee")> 9000)
    		escortee->set("max_kee",9000);
    	if (escortee->query("max_sen")>9000)
    		escortee->set("max_sen",9000);
    	if (escortee->query("max_gin")>9000)
    		escortee->set("max_gin",9000);
    		
    	escortee->full_me();
    	SMART_D->auto_npc_setup(escortee, "胖姑娘", 150, 170, 1, "/obj/weapon/", "fight_w", "thunderwhip2", 1); 
    	
    	if (arg == "lady") {
       		escortee->set("name","胖姑娘");
       		escortee->ccommand("say 爹，你忒也多事儿，凭我的功夫，谁敢动我一根头发啊！");
       		escortee->set("escortee","active");
       		
       	} else	{
       		escortee->set("name","胖小姑娘");
       		escortee->ccommand("say 爹，有这位"+RANK_D->query_respect(me)+"保护，你就放心吧。");
       		escortee->set("escortee","passive");
       		
       	}
    	
    	// 设置extra NPC escorter
/*    	ob=new(__DIR__"biaoshia");
    	ob->move(environment());
    	ob->set_leader(escortee);
    	ob->set_temp("protecting",escortee);
    	ob->set("combat_exp",exp);	
    	"/feature/nada"->reset_npc(ob);
    	SMART_D->auto_npc_setup(escortee, "胖姑娘", 200, 170, 1, "/obj/weapon/", "fight_w", "thunderwhip2", 1); */
    	    	
    	escortee->init_escort(me,exp);
    	return 1;	
}