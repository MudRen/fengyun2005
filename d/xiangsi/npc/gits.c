// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int leave();

void create()
{
        set_name("铜板", ({"master tongban", "tongban","master" }) );
		set("class","moon");

		create_family("皓月宫", 3, "");
		set("nickname",CYN"曾是三清宫真人的"NOR);
		set("title","皓月天宫");

        set("gender", "男性");
        set("apprentice_available", 3);

		set("max_force",2000);
		set("force",2000);

		set("fly_target",3);	// 限飞3次....

        set("reward_npc", 1);
		set("difficulty", 2);
		set("per", 32);
		set("age",20);
		set("attitude","peaceful");

        set("combat_exp", 1000000);
        
		set("long","铜板坐在桌边，手中执一盏凉茶，正半阖双眼，享受清风。\n");

		set("chat_chance", 1);
		set("chat_msg", ({
		CYN"铜板微一凝神，闭著眼睛念了几句咒语，施展「阴阳眼」法术。\n"NOR,
		CYN"铜板笑道：当年的技艺，我也还略记得一些。\n"NOR,
		CYN"铜板说道：想当年我三清宫 真人 铜板(Tongban)，天下第一，地上无敌。\n"NOR,
		CYN"铜板自豪地说道：“想当年，我玉树临风一表人才，追我的女孩从西南华山上排到北疆神水宫．．．”\n"NOR,
		}) );


		set("inquiry",([
       		"月神": 	"不求杀业，不罪情缘，拜入月神门下，感觉却也不错。\n",
            "leave": (: leave :),
    	]) );

		set("guard_msg",CYN"$N喝道：莫以为我退隐多年，便可容得你们在此放肆！\n"NOR);

		set("chat_chance_combat", 100);
		set("chat_msg_combat", ({
			   (: smart_fight() :),
		}) );

        set("rank_nogen",1); 
//		set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));
                
		set_skill("force", 140);    
		set_skill("dodge", 100);    
		set_skill("move", 100);    
		set_skill("parry", 120);    
		set_skill("literate", 100);
		set_skill("blade", 120);    
		set_skill("perception",100);
		set_skill("chanting",80);
		set_skill("spells", 100);
		set_skill("foreknowledge", 80);

		set_skill("snowforce",90);
		set_skill("chillblade",100);
		set_skill("stormdance",90);

	    map_skill("force","snowforce");
	    map_skill("blade","chillblade");
	    map_skill("parry","chillblade");
	    map_skill("move","stormdance");
	    map_skill("dodge","stormdance");
     	setup();

		carry_object(__DIR__"obj/fapao")->wear();
		carry_object(__DIR__"obj/snakeblade")->wield();

}

void reset()
{
	set("apprentice_available", 3);
	set("fly_target",3);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) 
	{
		if( find_call_out("do_recruit") != -1 )
				command("say 慢著，一个一个来。\n");
		else
				call_out("do_recruit", 2, ob);
	} 
	else
		command("mian tongban");
}

int do_flatter(string arg)
{
	object me;
	me = this_player();
	if (!userp(me))
		return 0;
	if (arg != "tongban" && arg != "master tongban" && arg!="master")
		return 0;
	if (!me->query_temp("annie/flatter"))
		return 0;

	message_vision(CYN+me->name()+"指着铜板赞颂道：“铜板武功当世固然无人可比，就连放个屁也需大声呼吸，衷心赞颂！”\n"NOR,me);
	command("flatter master tongban");
	command("say 也罢，也罢，看你还是一片真心．．．今天可是你自愿拜我。");
	command("recruit " + me->query("id") );
	command("pat " + me->query("id") );
	command("mapi " + me->query("id") );
	me->delete_temp("annie/flatter");
	return 1;
}

void do_recruit(object me)
{
		command("hmm " + me->query("id") );
		command("mapi master tongban" );
		command("say 拍了马屁（flatter tongban）你就是我徒弟了，可不要随便乱拍！");
		command("say 这月神门下，混混日子尚可，做任务就不行了，日后不要太多抱怨。");
		command("flatter" );
		me->set_temp("annie/flatter",1);

}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_flatter", "flatter");
    if( !query_heart_beat(this_object()) )
		set_heart_beat(1); 
	if (!this_player()->query_temp("annie/gits") && userp(this_player()))
	{
		if (query("fly_target"))
			add("fly_target",-1);
		if (query("fly_target"))
			ccommand("noairport");
		else
			ccommand("noairport master tongban");
	}
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy))
		return 0;
	clean_up_enemy();
	if(!sizeof(enemy))
		return 0;
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}


int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object target;
	int i;
	target = select_opponent();
	i = query("combat_exp") * 100 / target->query("combat_exp") ;

	ccommand("exert yinlingkouming");
	ccommand("exert bingpojingbi");
	ccommand("perform dodge.shuangtianxuewu");
	set("force",2000);

	if (!query_temp("weapon"))
		if (ccommand("get twilight blade"))
			if (ccommand("wield twilight blade"))
				stop_busy();
	
	if (i > 180 && (userp(target) || query("test")))
		SKILL_D("chillblade")->perform_target(this_object(),"leidianjiaohong",target);
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N淡淡的扫了$n一眼。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：既然你一心要走，我也不想勉强。\n"NOR,this_object(),this_player());
	message_vision(CYN"$N说：只是门中各艺的精髓，你是都无法再用的了。\n"NOR,this_object(),this_player());
    return 1;
}


/*
铜板目前共学过十二种技能：

  基本刀法 (blade)                         - 神乎其技 120/    0
＊冰镜七诀 (chillblade)                    - 出类拔萃 100/    0
  纵跃闪躲之术 (dodge)                     - 出类拔萃 100/    0
  内功心法 (force)                         - 出神入化 140/    0
  占卜学 (foreknowledge)                   - 已有小成  80/    0  <-- 16kar,去清平练5级move.... *doubt mingyue
  读书识字 (literate)                      - 了然於胸 120/    0
  基本轻功 (move)                          - 驾轻就熟  95/    0　<-- 下个master需要100lv
  拆招卸力之法 (parry)                     - 神乎其技 120/    0
  听风辨器之术 (perception)                - 出类拔萃 100/    0
＊冷雪心经 (snowforce)                     - 出类拔萃 100/    0
  咒术 (spells)                            - 出类拔萃 100/    0	<-- 铜板笑道：当年的技艺，我也还略记得一些。
＊天岚凝舞 (stormdance)                    - 驾轻就熟  90/    0  



*/
