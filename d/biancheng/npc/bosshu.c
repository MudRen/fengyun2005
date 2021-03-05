#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("胡掌柜",({"hu zhanggui","hu","zhanggui"}));
	set("title","肉铺");
   	set("long","
这人满脸横肉，留着一把大胡子，正是肉铺的胡掌柜。他围着一身油腻腻的围
裙，正在柜台后面切肉。胡掌柜今年四十多，两年前从内地买了个姑娘回来做
媳妇，虽说女人看上去死心塌地的，新近还怀了孩子，胡掌柜总是疑神疑鬼的
怕她哪天会不辞而别。\n");
     	set("gender","男性");
    	set("group","citizen");
    	
    	set("combat_exp",3700000);  
    	set("age",42);
    	 	    	 	  	
    	set("inquiry", ([
//	        	"江湖五毒"	:		(: kill_him :),
//             	"采花蜂"	:		(: kill_him :),
   		]));
   	
    	set("death_msg",CYN"\n$N说：“天哪，我那娃子没出世就没了爹！”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",
        ]) );    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"胡掌柜说：“好汉需好酒，好酒需好肉，好肉就找我老胡。”\n",
			"胡掌柜说：“我那媳妇什么都好，就是爱花钱，唉，女人。。。。”\n",
    	}) );    	    	

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(50) :),
        }) );
    	
    	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
		setup();
    	delete_skill("yijinjing");
    	carry_object("/obj/armor/cloth",([	"name": "油迹斑斑的围裙",
    						"long": "一件油迹斑斑的围裙，上面还沾着点点滴滴的肉末。\n",
    						 ]))->wear();    
    	
}


void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 		if (this_object()->is_fighting()) {
 			tell_object(me,"胡掌柜现在没空回答你。\n");
 			return 1;
 		}
        if(!me->query("marks/wanma/棺材之谜")) {
        	tell_object(me,"胡掌柜说：没听说过，这名字邪气得紧。\n");
        	return 1;
        }
        	
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现在他脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n",this_object());
        another = new(__DIR__"yunzhonghe");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}


void greeting(object ob)
{
	object hu,blade,groom;
	
	if( !ob || environment(ob) != environment() && is_fighting()) return;
	hu=this_object();
	if (REWARD_D->check_m_success( ob, "义助小媳妇")) {
		message_vision("$N抬头朝$n一看，刷地一下从架子上抽出一把明晃晃的杀猪刀。\n",hu,ob);
		if (!hu->query_temp("weapon")) {
				blade=new(__DIR__"obj/pblade");
				blade->set("value",0);
				blade->move(hu);
				command("wield blade");
		}
		if (ob->query("gender")=="女性") {
			command("say 女人家不学好，却教我媳妇儿乱花钱，快走快走。");
		}
		else {
			command("say 大胆，竟敢和我媳妇眉来眼去的勾搭，不教训你一下不成！");
			fight_ob(ob);
			ob->fight_ob(hu);
			ob->set_temp("marks/wanma/胡掌柜杀",1);
		}
	}
}



void win_enemy(object loser){
    	object groom;
    	
    	command("puke");
 //   	if (!loser->is_busy())
 //   	{
    		groom = find_object(AREA_BIANCHENG"road4");
			if(!objectp(groom)) groom = load_object(AREA_BIANCHENG"road4");
			loser->move(groom);
			loser->delete_temp("marks/wanma/胡掌柜杀");
			message_vision(HIY "\n$N被$n踢了出来！\n"NOR, loser,this_object());
//		}
}


void lose_enemy(object winner){
    	command("say 你狠，咱们骑驴看唱本，走着瞧。\n");
    	winner->delete_temp("marks/wanma/胡掌柜杀");
}
