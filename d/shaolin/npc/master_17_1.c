// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int leave();
int damo();
int be_guard();
int guardd();
int failit();
int dont();
int dontt();
int take_challenge(object me);
void no_answer(object me);
void create()
{
    	set_name("心湖", ({ "master hu", "master"}) );
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
    	
    	set("age", 84);
    	set("per", 35);
    	set("cps", 80);
    	
    	set("attitude","friendly");
    
    	set("long",
        	"少林寺现任掌门人，由于少林常丢经书，现在喜怒无常，经常将守经书"
        	"的弟子逐出少林。\n");
    
    	create_family("少林寺", 17, "掌门");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
		"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
		YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
		   
    	set("combat_exp", 5000000);
    	set("no_arrest", 1);
    	set("class","shaolin");
    
    	set("inquiry", ([
    		"经书被盗" : (: guardd :),
    		"易筋经" : (: damo :),
    		"yijinjing" : (: damo :),
    		"达摩" : (: damo :),
    		"damo" : (: damo :),
    		"绝技" : (: damo :), 
        	"守经楼": (: be_guard :),
        	"护经楼": (: be_guard :),
        	"护经楼失败": (: failit :),
        	"守经楼失败": (: failit :),
        	"失败": (: failit :),
        	"佳音": (: dont :),
        	"拜": (: dontt :),
        	"拜拜": (: dontt :),
        	"拜．．．拜．．．": (: dontt :),
        	"拜．．．": (: dontt :),
         	"leave" : (: leave :),
    	]));
        
        set_skill("chanting", 160);
		set_skill("move", 160);
		set_skill("dodge", 160);
		set_skill("force", 180);
		set_skill("unarmed", 180);
		set_skill("parry",160);
	
		set_skill("perception",100);
		set_skill("foreknowledge",100);
		set_skill("literate", 100);
	
		set_skill("zen", 160);
		set_skill("xiaochengforce",150);
	    set_skill("iron-cloth",100);
	    set_skill("yijinjing",90);     
		set_skill("puti-steps",150);
		set_skill("yizhichan",150);
		set_skill("dabei-strike",150);
		set_skill("duanhun-spear",150);
		set_skill("fumostaff",150);
		set_skill("liuxing-hammer",150);
		set_skill("wuche-axe",150);
		set_skill("lianxin-blade",150);
		
		set_skill("blade", 200);
		set_skill("hammer",200);
		set_skill("staff",200);
		set_skill("spear",200);
		set_skill("axe",200);
	    map_skill("iron-cloth","yijinjing");	
    	map_skill("unarmed","yizhichan");			
		map_skill("blade","lianxin-blade");
		map_skill("hammer","liuxing-hammer");
		map_skill("staff","fumostaff");
		map_skill("spear","duanhun-spear");
		map_skill("force","xiaochengforce");
		map_skill("dodge","puti-steps");
		map_skill("axe","wuche-axe");

    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}

int dontt()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 11)  
	{
		ccommand("yawn "+me->query("id"));
		return 1;
	}
	ccommand("hmm");
	ccommand("say 拜拜？．．．．");
	ccommand("say 这是在说供佛之事，一种暗号还是．．．什么人的名字呢？");
	REWARD_D->riddle_set(me,"多事之秋",12);
	return 1;
}

int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 4 || !REWARD_D->check_m_success(me,"守经楼"))  
	{
		ccommand("tidu "+me->query("id"));
		return 1;
	}
	ccommand("spank "+me->query("id"));
	ccommand("hmm");
	ccommand("say 此事委实可疑．．．七师弟本就可于藏经阁来去自由，为何"YEL"窃书"CYN"？");
	ccommand("say 请施主代老衲上报天峰大师，以释此疑。");
	REWARD_D->riddle_set(me,"多事之秋",5);

	return 1;
}

int failit()
{
	object me;
	int combat_exp,combat_exp_lost;
	mapping combat_level;
	
	int num, current_apply;
	string *attr1= ({ "strength","composure","agility", "intelligence","karma", "constitution" });
	string *attr2= ({ "str", "cps", "agi", "int", "kar", "con" });
	string *attr3= ({ "力量", "定力", "速度", "才智", "运气", "体质" });
	
	
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 3) 
	{
		ccommand("dapp "+me->query("id"));
		return 1;
	}
	if (!REWARD_D->riddle_check(me,"守经楼") || REWARD_D->check_m_success(me,"守经楼")) 
	{
		ccommand("dapp "+me->query("id"));
		return 1;
	}
	ccommand("sigh");
	no_answer(me);
	ccommand("emote 看上去一瞬间就苍老了六十岁．．．");
	set("age",144);	// snicker annie

	
	combat_exp = me->query("combat_exp");
	combat_level = F_LEVEL->exp_to_level(combat_exp);
/*	combat_exp_lost = combat_level["next_level"]/20;

	if (((F_LEVEL->exp_to_level(combat_exp-combat_exp_lost))["level"]) < combat_level["level"])
	// 降级了。
	tell_object(me,HIR"\n糟了，你的等级降低了！\n"NOR);
	me->add("combat_exp", - combat_exp_lost);	*/
	
		
	CHANNEL_D->do_sys_channel(
		"info",sprintf("%s，少林经楼再度失窃，%s受杖刑五十，元气大伤。", NATURE_D->game_time(),
			me->name(1)));
	
	// 改为属性损失		
			num = random(6);			
			if (combat_level["level"] >= 10) {
				current_apply = me->query("attr_apply/"+attr1[num]);
				if (me->query(attr2[num]) + current_apply>10){
					tell_object (me, WHT"\n		你的" + attr3[num] + "受到损伤降低了。\n\n\n"NOR);
					me->add("attr_apply/"+attr1[num],-5);
				}
			}	
			
	me->unconcious();		
	
	me->add("annie/failed_守经楼",1);
	me->add("annie/failed_守经楼_exp",combat_exp_lost);
	REWARD_D->riddle_clear(me,"守经楼");
	return 1;
}

int guardd()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 1) 
	{
		message_vision("$N皱眉道：你怎知此事？莫非你与那盗书贼有所牵连？\n",this_object());	
		return 1;
	}
	ccommand("sigh");
	message_vision("$N叹道：经书一丢再丢，谁还肯去"YEL"守经楼"NOR"？\n",this_object());	
	REWARD_D->riddle_set(me,"多事之秋",2);
	return 1;
}

int be_guard(){
	object me;
	int num;
	me = this_player();
	if ( num = me->query("vendetta/shaolin")){
		message_vision("$N狠狠地瞪了$n一眼：杀了少林子弟" + chinese_number(num) 
			+ "人，还想来骗少林经书？\n", this_object(),me);
		return 1;
	}
	if (REWARD_D->riddle_check(me,"多事之秋") != 2 && REWARD_D->riddle_check(me,"多事之秋") != 3)  
	{
		message_vision("$N摇头道：此事与你无关。\n",this_object());	
		return 1;
	}

	message_vision("$N道：“你想协助本寺查出藏经楼失窃的疑案？....嗯....你不怕贼人下毒手吗？”（answer）\n",this_object());	
	add_action("do_answer", "answer");
	REWARD_D->riddle_set(me,"多事之秋",3);
	return 1;
}

int damo(){
	object me;
	int explvl, budlvl;
	me = this_player();
	explvl = me->query("combat_exp");
	budlvl = me->query_skill("zen",1);

	if(this_object()->is_fighting()){
		return notify_fail("心湖似乎正在忙！\n");
	}
		
	if(me->query("marks/面壁领悟")
		|| REWARD_D->check_m_success(me,"少林面壁")){
		message_vision("$N盘弄着手中的佛珠,低声咏道：“ 众生无我，并缘业所转，苦乐齐受，皆从缘生。”\n",
				this_object()); 
				
		return 1;
	}
	message_vision("$N微微一耸眉说道：易筋经乃少林至宝，一向只传有缘之人。。。\n", this_object()); 
	if(me->query("class") != "shaolin") {
		message_vision("$N笑道：你既非我少林，还是不要多问了。\n", this_object());
		return 1;
	} else if(explvl > 2400000 && budlvl >= 160){
		message_vision(YEL"\n$N看了看$n，惊异的啊了一声。"NOR, this_object(), me);
		message_vision(YEL"长叹一声：原来如此，善哉，善哉。\n"NOR, this_object());
		message_vision(YEL"$N看着$n说道：要学易筋经，为师我先要考考你武学上的修为，可否？\n"NOR, 
				this_object(), me);
		message_vision(YEL"（ａｃｃｅｐｔ　ｙｅｓ／ｎｏ）\n"NOR, this_object());  
		add_action("do_accept", "accept");
		me->set_temp("marks/问心湖", 1);
		call_out("no_answer", 60, me);	
	} else {
		message_vision("$N看了看$n：徒儿，你修行未够，不可强求。。。", this_object(), me); 
		tell_object(me, "（需160级禅道）\n");
	}	
	return 1;
}


int do_accept(string arg) {
	object me;
	
	me = this_player();
	if(!arg || (arg != "yes" && arg != "no")){
		return 0;
	}
	if(me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	if(!me->query_temp("marks/问心湖")){
		return 0;
	}
	if(this_object()->is_fighting() || this_object()->is_busy()){
		command("say 我现在正忙，等会吧。。。");
		return 1;
	}
	if(arg == "no"){
		remove_call_out("no_answer");
		message_vision("$N点了点头，闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n",
			this_object());
	} else if(arg == "yes"){
		remove_call_out("no_answer");
		message_vision("$N道：出招吧。（ｆｉｇｈｔ）\n", this_object());
		me->set("marks/challenge_xinhu", 1);
	}
	me->delete_temp("marks/问心湖"); 
	return 1;
}


int accept_fight(object me){
	if (me->query("class")!= "shaolin")
		return 0;
		
	if(this_object()->is_fighting()){
		command("say 我现在正忙，等会吧。。。");
	} else if(!me->query("marks/challenge_xinhu")) {
		message_vision("$N闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n", this_object());
		return 0;
	} else if (me->query("marks/面壁领悟") == 1) {
		message_vision(YEL"$N沉声吟到：欲得净土，当净其心，随其心净，即佛土净，汝能明否？\n"NOR,
				this_object());
	} else if (me->query("marks/面壁领悟") == 2) {	
		message_vision(YEL"$N点点头说：善哉，善哉。。。。。。\n"NOR, this_object()); 
		message_vision(YEL"$N疾声喝到：未来事未至，莫愿莫求，未来心自绝，即名无未来事。，汝能解否！\n"NOR, 
				this_object());
	} else if (me->query("marks/面壁领悟") == 3) {	
		message_vision(YEL"$N双手合十，微笑到：恭喜，恭喜，你终于应证了大道！\n"NOR, this_object());
		message_vision(YEL"$N双手合十，恭身谢道：多谢师傅指点迷津。\n"NOR, me); 
		message_vision("\n$N问道：只如佛之与法，为是佛在先？为是法在先？若法在先，法是何佛所说？\n",
				this_object());
		message_vision("若是佛在先，承何教而成道？\n", this_object()); 
		message_vision("$N郎声回答：佛亦在法先，亦在法后。\n", me); 
		message_vision("\n$N又问到：因何佛法先后？\n", me); 
		message_vision("$N欣然曰：一切诸佛，皆因寂灭法而得成佛，即是法先佛后。然始广说十二部经，\n",
				me);
		message_vision("引化众生。众生承佛法教，修行得成佛，即是佛先法后也。\n", me); 
		message_vision("$N和$n相对会心的一笑。\n", me, this_object());
		message_vision(HIY"\n$N说：你要寻找的东西我已经指引给你了，你还不快去？\n"NOR, this_object());
		me->delete("marks/面壁领悟");
		me->delete("marks/challenge_xinhu");
		REWARD_D->riddle_done(me,"少林面壁", 50, 1);
//		me->set("marks/少林_面壁成功", 1);
		return 0;
	}
	message_vision("\n$N道：“接招。。。。”\n", this_object());
	return 1;
}

void win_enemy(object obj){
	message_vision("$N摇了摇头，自言自语道：“可惜，可惜。”\n", this_object());	
}

void lose_enemy(object me) {
	object room;
	
	if (!me->query("marks/challenge_xinhu"))	return;
		
	me->delete_temp("marks/fi_m_17");
		
	if(!me->query("marks/面壁领悟")) {
		message_vision(HIR"\n$N勃然大怒：”孽徒，和师傅过招也下这么重的手”，$N伸出左手无名指
在$n胸前一晃。\n"NOR, this_object(), me);
		tell_object(me, HIR"\n你觉得膻中一热，就失去了知觉。\n"NOR);
		me->set("marks/少林面壁", 1);		
		me->unconcious();
	} else if(me->query("marks/面壁领悟") == 1){
		message_vision(HIR"\n心湖大喝一声：“给我回去！”右手掌心向外平推，左手食指凌空虚点。\n"NOR, this_object());
		tell_object(me, HIR"你觉得胸口气血翻涌，眼前一黑，晕了过去。\n"NOR);
		me->set("marks/少林面壁", 1);
		me->unconcious();
	} else if(me->query("marks/面壁领悟") == 2) {
		message_vision(HIR"\n只见$N身形掠起，双手拇指同时按向$n太阳穴。$n大惊失色，躲闪不及。\n"NOR, 
				this_object(), me);
		tell_object(me, HIR"只觉额头两侧一阵灼热，眼前一黑，晕了过去。\n"NOR); 
		me->set("marks/少林面壁", 1);
		me->unconcious();
	} 
	message("vision", "两个小沙弥走来把" + me->name()+ "抬了出去。\n", environment(me), me);
	room = find_object("/d/songshan/damocave");
	if(!objectp(room)){
		room = load_object("/d/songshan/damocave");
	}
	me->move(room);
	message("vision", "两个小沙弥把" + me->name() + "抬进来放到了地上。\n", room);
	me->delete_temp("marks/问心湖");
}

void no_answer(object me)
{

	message_vision("$N点了点头，闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n",
			this_object()); 
	if(me->query_temp("marks/问心湖")){
		me->delete_temp("marks/问心湖");
	}
	delete("asking");	
}

void attempt_apprentice(object me)
{
    
	if(me->query_temp("won_master_yi"))
	{
		command("smile");
        	command("recruit " + me->query("id") );
		message_vision(CYN"
$N说：达摩院的几位师叔各擅绝技，你若有心可逐一"YEL"请教"CYN"。
只是宏扬佛法乃是少林寺的根本，万万不可因贪学武功而耽误了
禅道修为，切记切记。\n"NOR, this_object());
        	me->delete_temp("won_master_yi");

        	return;
    	}
    	else
    	{
		command("shake");
    	}
}

int do_answer(string arg)
{
    	object ob;
    	object shouyu;
	object me = this_player();

		if (REWARD_D->riddle_check(me,"多事之秋") != 3) 
		{
			command("emote 皱眉道：你说什么？老衲听不清楚。\n");
        	return 1;
        }   
		if (REWARD_D->riddle_check(me,"守经楼") || REWARD_D->check_m_success(me,"守经楼")) 
		{
			command("emote 皱眉道：你不是已经去守经楼了么？\n");
        	return 1;
        }   
		if (arg == "怕" || arg == "no")
		{
			no_answer(me);
			REWARD_D->riddle_set(me,"多事之秋",2);
			return 1;
		}

    	if(arg == "不怕" || arg == "yes")
    	{        
    		if (shouyu=present("shouyu",this_player())) 
			{
        	command("say 好吧，你已经有了我的手谕，你（wave）它就可以上藏经楼。\n");
			if (!REWARD_D->check_m_success(me,"守经楼")) 
				REWARD_D->riddle_set(me,"守经楼",1);
        	return 1;
	        }   
			command("say 好，你去吧！\n");
			command("say 这里是我的手谕，你用（wave）它才可以上藏经楼。\n");
			command("say 老衲在此恭候"YEL"佳音"CYN"，\n");
			command("say 若尔不幸"YEL"失败"CYN"，也请尽快告知老衲．．．\n");
			ob = new(__DIR__"obj/shouyu");
			if(!ob->move(this_player()))        	
				destruct(ob);
			if (!REWARD_D->check_m_success(me,"守经楼")) 
				REWARD_D->riddle_set(me,"守经楼",1);
			return 1;
	    }
	command("emote 皱眉道：你说什么？老衲听不清楚。\n");
	return 1;
}


void die(){
	message_vision("$N退后几步微一凝气，脸色又恢复了红润。\n", this_object());
	full_me();
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shaolin") return 0;
	message_vision(CYN"$N合掌道：既是无缘，何必再留,以后也不要再回来了。\n"NOR, this_object(),this_player());
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


