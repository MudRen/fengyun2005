#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack();

inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("天枫十四郎", ({ "tianfeng"}) );
        set("gender", "男性" );
        set("age", 55);
        set("nickname", CYN "伊贺忍侠" NOR);
        set("long", 
"一个面色蜡黄，浓眉高颧的乌衣老者，浑身尽是杀气。他盘膝坐在山巅之上，
衣抉下露出赤足，却将一双高齿乌木的木屐端放于前，木屐上竟又放着柄乌
鞘长刀。\n");
//    	create_family("一刀流", 7, "家督");
//      set("rank_nogen",1);
//      set("ranks",({"下忍","中忍","上忍",RED"罗刹"NOR,HIR"修罗"NOR}));
//      set("rank_levels",({32000,512000,1536000,3456000 }));
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("reward_npc", 1);
		set("difficulty", 5);
	
		set("skill_public",1);
	
        set_skill("unarmed", 140);
    	set_skill("ghosty-force", 200);
    	set_skill("enmeiryu",150);
    	set_skill("ittouryu",160);
    	set_skill("ninjitsu",200);
		set_skill("dodge", 140);
		set_skill("ghosty-steps",200);
		set_skill("blade",140);
   		set_skill("force", 150);
    	set_skill("parry", 140);
    	set_skill("magic", 100);
    	
    	map_skill("magic", "ninjitsu");
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   	
   	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: smart_fight() :),    
        }) );  
      
   
		set_temp("apply/damage",100);
        set("chat_chance", 1);
		set("chat_msg",	({
			"天枫十四郎那亘古不变的死灰色的脸突然颤抖起来，哇的一声咳出口鲜血。\n",
				})  );
		set("inquiry",	([
			"李菊" : "菊子。。菊子。。你在哪里。。。\n",
			"南宫灵" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
			"无花" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
			"灵儿":  "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",	
			"东瀛浪人": 	"action天枫十四郎冷冷地看了你一眼，不发一语。\n",
		])		);
	
		setup();
		carry_object(__DIR__"obj/wucloth")->wear();
    	carry_object(__DIR__"obj/muji")->wear();
		carry_object(__DIR__"obj/blackblade")->wield();
}



void win_enemy(object loser)
{
    	message_vision(HIC "天枫十四郎仰天长叹一声，良久。。\n"NOR,loser);
    	message_vision(HIR "天枫十四郎突然哇地一声喷出口鲜血，发狂一般仰天长嘶：
菊子啊，你。。。你。。在何方。。\n"NOR,loser);
		loser->set("天枫_quest1",time());
}

void lose_enemy( object winner)
{
		object blade;
		if(!winner->query_temp("marks/fight_tf"))
            	return;
/*		if (REWARD_D->check_m_success(winner, "浪人的悲哀"))	
				return;*/
		if (REWARD_D->check_riddle(winner,"浪人的悲哀")>0)
			return;
//		winner->set("天枫_quest1","成功");
		REWARD_D->riddle_set( winner, "浪人的悲哀",1);
		winner ->delete("天枫_quest1");
//		If you lost/couldn't get the blade, just kill TF14 to loot it.		
		if(blade = present("black blade",this_object())) 
		{
			message_vision(HIR"天枫十四郎死灰般的眼睛突然亮了起来，双手将乌鞘长刀交给$N，
双膝跪地肃然道：你，好汉。此刀请你转交给我子灵儿。。拜托了。。\n"NOR,winner);
			if (!blade->move(winner))
				destruct(blade);
		}
		
}

int accept_fight(object me)
{
	int count;
	object /*blade,*/who;
	who=this_object();
	
	if (this_object()->is_fighting() || this_object()->is_busy())
        	return notify_fail("天枫十四郎正在忙着呢，没空和你搭话！\n");
	
	if(!present("black blade",this_object())) return 0;
	
	if (REWARD_D->riddle_check( me, "浪人的悲哀")) {
//	if(me->query("天枫_quest1")=="成功")
			message_vision(HIW"天枫十四郎问道：“我拜托你的事情，帮我做到了吗？”\n"NOR,me);
			return 0;
	}
	
	if( me->query("天枫_quest1")&&me->query("天枫_quest1")+600>time())
	{
		message_vision(HIR"天枫十四郎不屑的看着$N说道：“手下败将，还来做甚？”\n"NOR,me);
		return 0;
	}

	if (REWARD_D->riddle_check(me,"多事之秋") == 10)
//	if (REWARD_D->riddle_check(me,"多事之秋") != 9)
	{
		message_vision(HIR"天枫十四郎冷冷地撇了$N一眼，不置可否。\n"NOR,me);
		return 0;
	}

	count=me->query_temp("天枫_挑战次数");
	
	if(me->query("combat_exp")<2500000 || me->query("score")<2000)
	{
		if(count==0)
			message_vision(HIY"天枫十四郎霍然睁开双眸，扫了$N一眼，微叹一声，闭目无语。\n"NOR,me);
		
		else if(count==1)
			message_vision(HIY"天枫十四郎哼了一声低喝道：吾乃东瀛天枫十四郎，不战阁下这等碌碌无为之辈。
（需等级５８，评价２０００）\n"NOR,me);
		else if(count==2)
		{
			message_vision(HIW"天枫十四郎眉头微皱，“呛”的一声，刀光乍现。\n"NOR,me);
			kill_ob(me);
			me->delete_temp("天枫_挑战次数");
			return 2;
		}
		me->add_temp("天枫_挑战次数",1);
			return 0;
	}
	
	if (who->query("kee")<who->query("max_kee") || who->query("eff_kee")<who->query("max_kee")
		|| who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
		|| who->query("gin")<who->query("max_gin") || who->query("eff_gin")<who->query("max_gin"))
		{
			tell_object(this_player(),"天枫十四郎正在疗伤,没空理你.\n");
			return 0;
		}
	message_vision(HIY"天枫十四郎长吸一口气,霍然睁开双眸，目光如电盯着$N，冷冷道：你，出招！\n"NOR,me);
    me->set_temp("marks/fight_tf",1);
	return 1;
}
	
	
int accept_object(object who, object ob)
{
	if(!ob->query("saki")) return 0;
	message_vision(HIC"天枫十四郎双手紧握这瓶清酒，如获重宝。\n"NOR,who);
	call_out("be_poisoned",5+random(5),who);
	return 1;
}

int be_poisoned(object who)
{
    delete_temp("last_damage_from");
    message_vision(HIR"\n天枫十四郎颤抖着捧起清酒，老泪纵横，一仰而尽。\n
天枫十四郎的脸色突然变得惨白，嘴边流下了紫黑色的鲜血。\n
天枫十四郎浑身颤抖，大汗淋漓，凄然道：菊子，你。。你。。唉。。
这位"+RANK_D->query_respect(who)+"，吾身中奇毒，即便能逼出，也必功力尽废，但有一事相求，
不知你可否答应？\n"NOR,who);
	tell_object(who,MAG"你忽然记起似乎曾在哪里看过此种毒性．．．\n"NOR);
	if (REWARD_D->riddle_check( who, "浪人的悲哀") != 4)
//	if(who->query("天枫_quest4")!="成功")
	{
		die();
		return 1;
	}
    tell_object(who,HIY"answer yes/no \n"NOR);
	who->set_temp("answer_person",1);
	return 1;
}

int do_answer(string arg)
{
	object skinmask,who;
	
	who=this_player();
	if(!who->query_temp("answer_person")) return 0;
	if(arg=="yes")
	{
		message_vision("$N神色凝重地点了一下头。\n",who);
		message_vision(HIB"天枫十四郎仰天狂笑道：好，我今日约战了中原一点红，你就代我
一战吧。大恩必当涌泉相报。\n"NOR,who);
		skinmask=new(__DIR__"obj/skinmask");	// If you lose it, just borrow it from others. 
		skinmask->move(who);
		message_vision("天枫十四郎给$N一件装束。\n",who);
		REWARD_D->riddle_set( who, "浪人的悲哀", 5);
//		who->set("天枫_quest5","成功");
		who->delete_temp("answer_person");
		return 1;
		
	}
	if(arg=="no")
	{
		message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,who);
		die();
		return 1;
	}
	return 0;
}



void imbue_event(object me){
    object obj/*, weapon, *inv*/;
//  string prop;
//  int i;
    mapping data;
    
    if(!me || environment(me) != environment(this_object())) {
            return;
    }
	
	obj = me->query_temp("weapon");
	
	if (obj) {
		message_vision(HIG"\n泪水溅到了$N的" + obj->name() + HIG"上，又顺着"
            		+ obj->name() + HIG"落到了地上。\n"NOR, me);	
	} else
		message_vision(HIG"\n泪水溅到$N身上，滚到地上，一会儿就消失了。。。\n"NOR, me);
		
	data = ([
		"name":		"浪人的悲哀",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);
	return;	
}
	
	
void init()
{	object ob;
	::init();
	add_action("do_answer","answer");
	add_action("do_accept", "accept");
	add_action("do_killing", "kill");
	if( interactive(ob = this_player()) && !is_fighting() ) 
        if (REWARD_D->riddle_check( ob, "浪人的悲哀" ) == 6 )
        {
	        remove_call_out("recruiting");
                call_out("recruiting", 1, ob);
        }

}


void recruiting(object ob)
{
	
	if (!ob)	return;
	if (environment(ob)!= environment(this_object()))	return;
		
	if(ob->query("天枫_quest6")=="失败")
	{
		message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,ob);
		ob->delete("天枫_quest6");
		die();
		return;
	}
	if (REWARD_D->riddle_check( ob, "浪人的悲哀" ) == 6 )
	{
		tell_object(ob,WHT"\n天枫十四郎睁开无力的双眼，微微笑道：好，好，不愧是仁义武者，我虽中毒已深，命在
旦夕，但此番中原之行心愿已了，却也无憾。\n\n"NOR);
		tell_object(ob,YEL"两滴浑浊的泪水从天枫十四郎脸颊上滚落下来。\n"NOR);
		
		// reward time
		imbue_event(ob);
        REWARD_D->riddle_done(ob,"浪人的悲哀",100,1);
		
		tell_object(ob,WHT"\n沉默片刻，天枫十四郎又道，我一身武功尚无传人，你资质上乘，可任选一门学习。\n"NOR);
		return;
	}
}

int recognize_apprentice(object ob)
{
    if (REWARD_D->check_m_success( ob, "浪人的悲哀" )) return 1;
	return 0;
}


int prevent_learn(object me, string skill){
	string *slist = ({ "enmeiryu", "ittouryu", "ghosty-force","ghosty-steps","ittouryu","ninjitsu" });
	int i,amount;
	
	if(REWARD_D->check_m_success(me, "浪人的悲哀")){
		if (member_array(skill,slist)==-1)	return 0;
		amount = 0;	
		for (i=0;i<sizeof(slist);i++){
			if (skill != slist[i]) 
			if ((amount = me->query_skill(slist[i],1))>0) { 
				tell_object(me,"你现在已经学会了一门天枫十四郎的武功："+SKILL_D(slist[i])->name()+"（"+amount+"）。\n");
				tell_object(me,"你不能同时拥有多门天枫武功，如果你想学新的，请先去ｒｅｆｕｎｄ已经学得的。\n");
				return 1;
			}
		}			
		return 0;	
	}	
}

smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_temp("weapon")&& !random(5))
			{
				command("wield all");
				this_object()->smart_busy();
			} else 
			{	if (this_object()->query_temp("weapon"))
					command("say 好,我不用兵器!");
				command("unwield all");
				this_object()->smart_attack();
			} 
		}
	}
}

smart_busy() {
	this_object()->perform_action("blade.gobankiri");
}
smart_attack() {
	this_object()->perform_action("unarmed.shiden");	
}


int do_killing(string arg)
{
    object player, victim;
//  string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
       	if(victim->query("id")=="tianfeng")
        {
            this_object()->remove_all_enemy();
            command ("say 好，先杀你!");
            return 0;
        } 
    }
    return 0;
}
