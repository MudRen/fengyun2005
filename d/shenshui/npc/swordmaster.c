
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

string *list = ({
"白三空回剑反削，片片剑影飞起，却寂然无声，点点向$N笼去",
"白三空拔剑旋舞，一时间洒出银芒一片，如月光般流向$N",
"白三空一剑轻飘飘刺出，本来毫无变化。可是变化忽然间就来了，\n来得就像是流水那麽自然，夹带着一种奇异的力量划向$N",
"白三空手中长剑如和煦春风洒出，没有人知道风从哪里来，也就无法抵挡",
"白三空的这一剑只有刺，简单而有效地往$N的小腹刺去",
"白三空手中长剑狂风骤雨般地连攻数剑",
"白三空手中长剑光芒暴长，如雷霆万钧劈出",
"白三空手中长剑左右晃动，倏然中宫直进，径点你前胸“紫宫穴”",
"白三空手中长剑东一击，西一扫，如随意漂浮的游云，轻描淡写地击出",
"白三空真力灌注长剑，简简单单的横划出去，一招平凡的「万岳朝\n宗」，在其手中竟有如斯威力",
"白三空身形拔地而起，手中长剑舞动，满天剑气森森，罩向你的左肩",
"白三空左手轻掠划了一个半弧，右手长剑连点，淡淡的剑气忽然从四面八方掩向你",
"白三空纵身一跃，手中长剑牵动著周遭的气流，漩涡般向你右胸劈去",
"白三空高呼酣斗，越斗越狠，像是发了狂的野兽一般，长剑横扫猛击，乱劈乱戳",

"白三空手腕微微一震，长剑如柔风一般卷向你",
"白三空猛地挥动长剑向你当头击下，你退了一步，但长剑的剑气不依不饶地袭来",
"白三空一声清啸，大踏步向前走来，手中长剑平平递出，直取你的下盘",
"白三空手中长剑晃动，虚点数招，突然自影中发出一剑，刺向你的眉心",
"白三空纵身飘开数尺，手中长剑斩向你的眉心",
"白三空剑势渐缓，但内力催动，长剑竟然发出低低的鸣响，随之一\n振左臂，长剑忽发清角之音，击向你的下盘",
"白三空上身往左侧一拧，右手长剑反手向你的眉心挥去",
"白三空惊叱一声，双手并举，寒光陡飞，霎时人剑合一，凌空直向$N飞去",

});
string *list2 = ({
"黯然销魂剑法",
"冰镜七诀",
"燕十三剑法",
"清风细雨温柔剑",
"左手剑法",
"寒天吹血剑法",
"蝙蝠刀法",
"打狗棒法",
"白云杖法",
"血战枪法",
"四奇剑法",
"清风十三式",
"轩辕斧法",
"疯魔杖法",
"蝶恋花剑法",
"一刀流剑术",
"岳家中平枪法",
"断魂枪",
"雪影剑法",
"搏浪七杀",
"太极剑法",
"天雷破",
});

int go_fight();
int good_boy();

void create()
{
    	set_name("白三空", ({ "bai sankong","bai" }) );
    	set("nickname", HIY"清平剑客"NOR);
    	set("gender", "男性" );
    	set("title", "清平山庄  庄主");
    	set("class","shenshui");
    	set("long", "
一个身材顾长，身穿黑丝长衫，额下五柳长须，像貌十分清奇的老人，
正是山东省武林盟主，“清平剑客”白三空。\n");
    	
 		set("guard_msg",HIW"$N对$n喝道：老夫既是神水宫的客人，就容不得你在这里撒野！\n"NOR);	
 	    
    	set("reward_npc", 1);
    	set("difficulty", 5); 
    	set("age", 64);
    	
    	set("skill_public",1);
    	set("attitude","peaceful");
    
    	set("no_busy",10);
       	set("atman",1000);
    	set("max_atman",1000);
    	set("fly_target",1);
 	   
    	set("toughness", 200);
    	
    	set("inquiry",([
    		"白衣人":		(: go_fight() :),
    		"扶桑白衣人":	(: go_fight() :),
    		"东海白衣人":	(: go_fight() :),
    		"失败":			(: good_boy() :),
    		"战死":			(: good_boy() :),
    	]));		
    			
    	 	        
    	set("chat_chance", 1);
    	set("chat_msg", ({
			"白三空摇头叹道：＂清平山庄横祸不断，人丁衰弱。。。。＂\n",	
        }) );
        
    	set("combat_exp", 3800000);
    	set("score", 200000);

    	set_skill("move", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("force", 150);
    	set_skill("sword",200);
    	set_skill("qingpingsword",200);
    	set_skill("qingpingforce",150);
    	set_skill("chaos-steps",150);
    	set_skill("bai-quan", 200);
    	set_skill("unarmed", 150);
    	
    	map_skill("unarmed", "baiquan");
    	map_skill("force", "qingpingforce");
    	map_skill("parry","qingpingsword");
    	map_skill("sword","qingpingsword");
    	map_skill("dodge","chaos-steps");
    	map_skill("move","chaos-steps"); 
    	map_skill("unarmed","bai-quan"); 
	
		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

    	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword")->wield();
    	carry_object(__DIR__"obj/shuzhi")->wield();

}

int demo(object me) {

	int k;
	k=random(sizeof(list));

	if (me->query("class")!= "shenshui")
	{
    		command("sigh");
    		command("say “我早已心灰意冷，还收什么徒弟。”\n");
			return 1;
		}
		else if (REWARD_D->check_m_success(me,"清平剑意"))
		{
    		message_vision("白三空赞赏地拍了拍你的头说：“好好努力吧。”\n", me);
			return 1;
    	} 

		if (me->query_temp("marks/shenshui/bai_ask") ==1)
			k=me->query_temp("marks/shenshui/bai_answer");

		if (me->query_temp("marks/shenshui/bai_ask") ==2)
			k=me->query_temp("marks/shenshui/bai_answer");


		if (me->query_temp("marks/shenshui/bai_ask")<=1)
		{
    		message_vision(CYN+list[k]+"。\n"NOR, me);
    		tell_object(me, WHT"白三空说：你可知这是那一门的招式武功？\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",1);
    		me->set_temp("marks/shenshui/bai_answer",k);
    	}
		else  
		{
    		message_vision(CYN+list[k]+"。\n"NOR, me);
    		tell_object(me, WHT"白三空说：你可知这又是那一门的招式武功？\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",2);
    		me->set_temp("marks/shenshui/bai_answer",k);
    	} 
    	return 1;
	
}

int do_apprentice(string arg)
{
	object me = this_player();
	
    	if (arg == "bai sankong" || arg == "bai") {
		demo(me);
	    	return 1;
	}
	return 0;
}

int do_answer(string arg){
	object me = this_player();
	int k;
	k=me->query_temp("marks/shenshui/bai_answer");
	
	if (!me->query_temp("marks/shenshui/bai_ask"))	return 0;
	if ( me->query_temp("marks/shenshui/bai_ask") == 1) {
		if (arg == list2[k])
		{
			k=random(sizeof(list));
    		message_vision(CYN+list[k]+"。\n"NOR, me);
    		tell_object(me, WHT"白三空说：你可知这又是那一门的招式武功？\n"NOR);
    		add_action("do_answer","answer");
    		me->set_temp("marks/shenshui/bai_ask",2);
    		me->set_temp("marks/shenshui/bai_answer",k);
    			return 1;
    		}
    	}
    	if ( me->query_temp("marks/shenshui/bai_ask") == 2) {
		if (arg == list2[k]) {
			message_vision(CYN"
白三空赞赏地拍了拍$N的头说：武学之道，在意不在形，你学我的清平武功，
亦不可拘泥于一招一式，而需将其融会贯通到本门武技中方有成就，切记切记！\n"NOR,me);
			me->delete_temp("marks/shenshui/bai_ask");
			REWARD_D->riddle_done( me, "清平剑意", 10, 1);
			return 1;
    		}
    	}
//	me->delete_temp("marks/shenshui/bai_ask");
	command("shake");
	return 1;
}
	

int recognize_apprentice(object ob)
{
	if(ob->query("class")=="shenshui" ) {

		if (REWARD_D->check_m_success(ob,"清平剑意"))
			return 1;
		else
			demo(ob);
	}	
	return 0;
}


void init()
{
    	object me;

    	::init();
		add_action("do_killing", "kill");
		add_action("do_apprentice","apprentice");
}


int go_fight(){
	
		object ob;
		ob = this_player();
		
		if (REWARD_D->check_m_success(ob,"清平剑魂")
			|| REWARD_D->riddle_check( ob, "清平剑魂")>2)
		{
			command("hmm");
			return 1;
		}	
			
		command("say 十年前扶桑白衣人挑战武林，四日内连杀青鹤柳松、双环赵士鸿、
八仙剑李青风、八手镖金大非，为师亦不是对手，幸有紫衣侯仗义出手方将其逐走。");
		command("say 紫衣侯已逝，白衣人复来，中原武林，何人能当其锋！");
		
		if (!REWARD_D->riddle_check(ob, "清平剑魂"))
			return 1;
		
		if (REWARD_D->riddle_check(ob,"清平剑魂")==1)
			REWARD_D->riddle_set(ob,"清平剑魂",2);
			
		command("say 你既是我白三空弟子，速赴东海与其一战，只可成功不可"YEL"失败"CYN"！");
		
		return 1;
		
}
		
int good_boy() {
	
		object ob;
		ob = this_player();
		
		if (!REWARD_D->riddle_check( ob,"清平剑魂"))
		{
			command("dunno");
			return 1;
		}
		
		if (REWARD_D->check_m_success(ob,"清平剑魂"))
		{
			command("say 学武之人，但求无愧于心，无愧于剑，这才是我清平剑之灵魂。");
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"清平剑魂") == 2
			|| REWARD_D->riddle_check(ob,"清平剑魂") == 1)
		{
			command("say 未战先言败，岂是我学武之人所为！");
			return 1;
		} 
		
		if (REWARD_D->riddle_check(ob,"清平剑魂") == 4)	// 可能么？
		{	
			command("ack");
			command("spank");
			command("say 好，不愧是我白三空的徒弟！");
			command("super");
			
			REWARD_D->riddle_done( ob,"清平剑魂",50,2);
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"清平剑魂") == 3)	// 正常结果
		{	
			command("smile");
			command("say 好徒儿。");
			command("say 学武之人，但求无愧于心，无愧于剑，");
			command("say 人生在世，有所为，有所不为，有所必为，");
			command("say 既已势在必死，只要死得有代价，死又何妨！");
			command("say 这才是我清平剑之灵魂！");
			command("super");
			REWARD_D->riddle_done( ob,"清平剑魂",50,1);
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"清平剑魂") == 5)	// 逃兵
		{
			command("puke");	
			command("say 我白三空一生英名，竟有你这贪生怕死的徒弟！");
			command("sigh");
			command("say 记住：人生在世，有所为，有所不为，有所必为，");
			command("say 这才是我清平剑之灵魂！");
			REWARD_D->riddle_done( ob,"清平剑魂",0,2);
			return 1;
		}	
		write ("hmm, please report to wizard, you shouldn't see this.\n");
		return 1;
}		
			
			
		