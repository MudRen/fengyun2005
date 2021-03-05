#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;
int give_mission();

void create()
{
	set_name("哈哈儿",({"haha er", "haha"}));
    	set("nickname","笑里藏刀");
	set("long", "这人矮矮胖胖，笑脸圆圆，活脱是个和气生财的酒店掌柜。。\n");
	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 8000000);
			
	set("inquiry", ([
        	"胖子" : (: give_mission :),
        	"帮忙" : (: give_mission :),
        	"生意" : (: give_mission :),
        	"原料" : (: give_mission :),
        	"豆腐胖子" : (: give_mission :),
          	"欧阳豆腐铺" : (: give_mission :),
           	"欧阳丁" : (: give_mission :),
           	"欧阳当" : (: give_mission :),
          	"ouyang ding" : (: give_mission :),
          	"ouyang dang" : (: give_mission :),
	   		"轩辕三光": "他输的只剩下那间当铺了。",
	   		"小鸟的舌头": "到处都是啊，不过，要上等的会唱歌的鸟儿的舌头才行。",
	   		"烤山猪肉": "知道我还要你帮忙？",
	   		"沙虫肝": "祖传机密，不可外传。",
	   		"熊掌": "要新鲜的才行，找头熊杀了就是了",
	   		"火辣辣的吻":	"action哈哈儿看看你，摇摇头不说话。\n",
	   		"乱棍打死猪八戒":	"action哈哈儿看看你，摇摇头不说话。\n",
	   		"穿过你的黑发我的手":	"action哈哈儿看看你，摇摇头不说话。\n",
   			"山珍海味":		"小店都有、都有，客官请坐。\n",
   	]));

   	  	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"圆脸胖子笑道：“兄台远来，想必饿了，快请用些酒莱，再谈正事。”\n",
        	"哈哈儿皮笑肉不笑地道，“哈哈，哈哈，我哈，你哈？”\n", 
        	"哈哈儿愁眉苦脸地说，最近客人少了好多，都是那两个该死的豆腐胖子。”\n",       	      	   	
        }) );
        
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );
		
	auto_npc_setup("guardian",250,200,0,"/obj/weapon/","fighter_w","demon-strike",2);
	set("smartnpc_busy",1);
	setup();
	carry_object("/obj/armor/hat",([	"name": "小毡帽",
    						"long": "一顶生意人常戴的小毡帽。\n",
    						 ]))->wear();    
    carry_object("/obj/armor/cloth")->wear();
	
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !ob || !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	message_vision("$N笑嘻嘻走了过来，拱手笑道：“兄台远来辛苦了。”\n", this_object() );
   	return;
}


int give_mission() {
	object me,ob;
	
	ob=this_object();
	me=this_player();
		
	tell_object(me, CYN"
哈哈儿叹了口气说：生意不好做哈，自古只听说过豆腐西施，没想到
豆腐胖子也这么厉害哈，我这儿顾客越来越少了，客官是否能帮小的
哈一个小忙？
	
哈哈儿说：要盖过豆腐胖子，就得做三道我祖传的名菜。

哈哈儿扳着手指开始数落，那就是

（a）"HIR"火辣辣的吻"NOR"

（b）"WHT"乱棍打死猪八戒"NOR"

（c）"HIM"穿过你的黑发我的手"NOR+CYN"

不过，这儿穷乡僻壤，只有些辅料，没有主料啊！看来客官是个好心
人，你想帮我做哪道菜呢？（answer a/b/c）\n"NOR);
	me->set_temp("marks/eren/haha_1",1);
	add_action("do_answer","answer");
	return 1;
}


int do_answer(string arg){
	
	object me;
	me = this_player();
	
	if (!me->query_temp("marks/eren/haha_1"))	return 0;
		
	if (!arg || (arg!="a" && arg!="b" && arg!="c")) {
		tell_object(me,"回答格式：answer a/b/c\n");
		return 1;
	}
	
	me->delete_temp("marks/eren/haha_1");
	
	switch (arg) {
		case "a": tell_object(me,CYN"哈哈儿说：这道菜我缺的是小鸟的舌头。\n"NOR);
					break;
		case "b": tell_object(me,CYN"哈哈儿说：这道菜我缺的是烤山猪肉。\n"NOR);
					break;
		case "c": tell_object(me,CYN"哈哈儿说：这道菜我缺的是熊掌。\n"NOR);
					break;
	}
	tell_object(me,CYN"哈哈儿说：你把原料找到，交给我的厨师做个样品尝尝。\n"NOR);
	if (!REWARD_D->riddle_check(me,"山珍海味"))
		REWARD_D->riddle_set(me,"山珍海味",1);
	
	return 1;
}

		
/*
火辣辣的吻			辣椒炒百灵鸟舌	easy bird, 2k
乱棍打死猪八戒		豆芽炒猪头肉	easy pickup in chuenyu 10k
穿过你的黑发我的手 熊掌拌海带		can be given by others, easy as well.	
*/	
	
int accept_object(object me, object obj)
{
		string *material_names=({ HIR"火辣辣的吻"NOR,WHT"乱棍打死猪八戒"NOR,HIM"穿过你的黑发我的手"NOR });
		string ob_name;
		int success, makeup_ok,i;
		object book;
			
		if (!REWARD_D->riddle_check(me,"山珍海味")) {
			command("say 这是什么东西，是豆腐胖子让你来骗我的么！");
			return 0;
		}
					
		ob_name= obj->query("name");
		success=1;
		makeup_ok=0;
		for(i=0;i<3;i++)
		{
			if(ob_name==material_names[i])
			{
				if(me->query("marks/eren/haha"+ob_name))
				{
					command("say 这道菜你已经给过我了。”\n");
					return 0;
				}
				me->set("marks/eren/haha/"+ob_name,1);
				message_vision(CYN"哈哈儿拿起"+obj->name()+CYN"细细地品了品了品，半晌儿才回过神来。\n"NOR,me);
				command("say 好，不错不错，正是我哈家帮的祖传风味。");
				makeup_ok=1;
			}
			success=success*me->query("marks/eren/haha/"+material_names[i]);
		}
		if(!success) return makeup_ok; 
			
		me->delete("marks/eren/haha");	
		
		tell_object(me,CYN"
哈哈儿热泪盈眶地说：啊呀呀，你竟然都办成了，好极、好极。
瞧我打出这祖传招牌名菜，把豆腐胖子的生意统统拉过来！		

哈哈儿说：你帮了我这么大忙，我该如何谢你呢。。。

哈哈儿悄悄塞给你一本小册子说：看你也是个学武的人，这本入门
的东西是我年轻时的，现在用不着了，你拿去看看吧。\n"NOR);
		
		book = new(BOOKS"magic_75");
		book->move(me);
		
		REWARD_D->riddle_done(me,"山珍海味",20,1);       
        QUESTS_D->special_reward(me,"山珍海味");		
        return 1;
}


/*
int accept_object(object who, object ob)
{	
	if (ob->query("name")=="烤山猪肉" && who->query_temp("eren/haha_1"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_1")) {
			who->add("potential",100);
			who->set("eren/haha_1",1);
			tell_object(who,WHT"你被奖励了！一百潜能！\n"NOR);
		}
		message_vision("$N说:再替我搞些山雀舌吧。\n",this_object());
		who->set_temp("eren/haha_2",1);
		return 1;
	}
	if (ob->query("name")==HIG"山雀舌"NOR && who->query_temp("eren/haha_2")
		&& who->query("eren/haha_1"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_2")) {
			who->add("potential",100);
			who->set("eren/haha_2",1);
			tell_object(who,WHT"你被奖励了！一百潜能！\n"NOR);
		}
		message_vision("$N说:再替我搞些"+YEL"熊掌"NOR+"吧。\n",this_object());
		who->set_temp("eren/haha_3",1);
		return 1;
	}
	if (ob->query("name")==YEL"熊掌"NOR && who->query_temp("eren/haha_3")
		&& who->query("eren/haha_1") && who->query("eren/haha_2"))
	{
		ccommand("spank "+who->query("id"));
		if (!who->query("eren/haha_3")) {
			who->add("potential",100);
			who->set("eren/haha_3",1);
			tell_object(who,WHT"你被奖励了！一百潜能！\n"NOR);
		}
		message_vision("$N说:好，好，若你能搞到沙虫肝，我一定能把胖子比下去。\n",this_object());
		message_vision("$N说：我必有重谢！。。。$N向$n挥了挥手。\n",this_object(),who);
		who->set_temp("eren/haha_4",1);
		return 1;
	}	
	if (ob->query("name")==YEL"沙虫肝"NOR && who->query_temp("eren/haha_4")
		&& who->query("eren/haha_1") && who->query("eren/haha_2")
		&& who->query("eren/haha_3"))
	{
		ccommand("ack "+who->query("id"));
		message_vision("$N结结巴巴地说：你你你哈，活着哈。。。。\n",this_object());
		who->set("marks/恶人窟",1);
		who->delete_temp("eren/haha",1);
		who->delete_temp("eren/haha",2);
		who->delete_temp("eren/haha",3);
		who->delete_temp("eren/haha",4);
		tell_object(who,"哈哈儿凑在你耳边说：告诉你个天大的机密，村里的铁像下埋着宝物，都归你了。\n",this_object());
		ccommand("grin");
		return 1;
	}	
	return 0;	
}
*/