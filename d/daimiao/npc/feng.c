// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之龙王 紫皓星辰 凤秋官 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 80K DODGE 75K PARRY 71K
// 依靠4个SEAL攻击。

// A：高于标准8M。D：等于标准8M。P:低于标准8M。此人可TK。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("凤秋官", ({ "feng qiuguan","feng"}) );
	set("gender", "男性" );
	set("title",YEL"大光明教 "NOR CYN"龙王"NOR);
	set("nickname",MAG"紫皓星辰"NOR);

	set("age",30+random(10));

	set("attitude","friendly");

	set("long",	"凤秋官目光温莹晶润，显见内功修为已臻化境。\n");

	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("str",40);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("dragonwhip",250);
	set_skill("xiaohun-whip",320);
	set_skill("whip",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

//	set_skill("huoyan-dao", 250);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",600);

	set_skill("divineforce",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "huoyan-dao");
	map_skill("force", "divineforce");
    	map_skill("dodge","fall-steps");
    	map_skill("move","anxiang-steps");
    	map_skill("whip","dragonwhip");
    	map_skill("parry","xiaohun-whip");
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );


	setup();

    set("reward_npc", 1);
	set("difficulty",7);

	carry_object(__DIR__"obj/fengwhip")->wield();
	carry_object(__DIR__"obj/fengcloth")->wield();
	carry_object(__DIR__"obj/paper4");

}


void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
	message_vision(CYN"凤秋官摇头轻叹，声音里带着一丝笑意：我就知道那小子成事不足败\n事有余，果然又把事情弄砸一次。\n"NOR,ob);
	return;
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}



int kill_ob(object who)
{
	::kill_ob(who);
	stop_busy();
	smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target,*enemy;
	int i=0,flag=10;
	me = this_object();
	target = select_opponent();
	enemy = query_enemy();
	for (i=0;i<sizeof(enemy) ; i++)
		if (enemy[i]->query_busy() < flag)
			flag = enemy[i]->query_busy();
	i=0;
	if (me->query_temp("weapon"))
	{
		if (flag > 2)
			i=ccommand("perform firestorm");
		else
			i=ccommand("perform thousandfeather");

		if (i)
			start_busy(2);	// thousandfeather is a 2+random(2) pfm. lets cheat a bit
	}


	return;
}

void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;
	me = this_object();
	
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	
	if (environment(me)->query("short") == "小屋" || !REWARD_D->check_m_success(enemy,"探流追源"))
	{
		set("reward_npc", 0);
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}

	message_vision(CYN"\n凤秋官抹去嘴角的鲜血，微笑道：果然是好武艺。我神教八众之中，除去我不
甚了解的阿修罗王，恐怕只有君山才制得住你。

凤秋官道：迦楼罗王现在正在明霞之山，你可有这个胆量，与他一战？\n\n"NOR,me,enemy);
//		REWARD_D->riddle_done(enemy,"欺骗",100,1);
	enemy->set("annie/demon_killed_feng",1);
	::die();
	return;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/




