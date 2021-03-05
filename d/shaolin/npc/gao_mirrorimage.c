// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之紧那罗王 众妙莲华 高猛 
// EXP 8M KEE 80K GIN/SEN 60K RESIST/ALL 50
// STR 95 DMG 988 ATTACK 752K DODGE 730K PARRY 490K
// 分身化影(4x)，Counter-Attack，极小机率PERFORM YAOZHAN(almost 1hit gone)。

// A/D/P：标准8M状态。此人可TK，但方法难。通常情况下为solo。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();
void dispel_mi();

void create()
{
	object armor,weapon;
	set_name("高猛", ({ "gao meng","gao","mirror image"}) );
	set("gender", "男性" );
	set("title",YEL"大光明教 "NOR CYN"紧那罗王"NOR);
	set("nickname",HIY"众妙莲华"NOR);

	set("age", 30+random(10));

	set("attitude","friendly");

	set("long",
		"\n"
		);
	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
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
		
	set("resistance/gin",50);
	set("resistance/kee",50);
	set("resistance/sen",50);

	set("max_kee",80000);
	set("max_gin",60000);
	set("max_sen",60000);
	
	set_skill("demon-blade",200);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",280);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);
    set_skill("stormdance",320);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 400);
	set_skill("force", 200);

	set_skill("kongshoudao", 400);
	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("parry", "lingxi-zhi");
	map_skill("unarmed", "kongshoudao");
	map_skill("force", "bolomiduo");
    	map_skill("dodge","cloud-dance");
    	map_skill("move","stormdance");
    	map_skill("blade","demon-blade");
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
               (: dispel_mi() :),
        }) );


	setup();

	set_temp("counter_action_extra",1);
	set_temp("counter_msg",CYN"$N看准破绽，倏然一跃而过，出手反击！\n"NOR);

	carry_object(__DIR__"obj/gaoarmor")->wear();
	carry_object(__DIR__"obj/paper1");
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

void dispel_m()
{
	int i;
	object mi;
	for (i=0;i<4 ; i++)
	{
		mi=present("mirror image "+(i+1),environment());
		if (mi)
		{
			mi->remove_all_killer();
			mi->set("NO_KILL","那只不过是一个幻像而已。\n");
		}
	}
	return;
}

void mirror_images()
{
	object gao;
	int k;
	object * enemy,*t;
	enemy = query_enemy();
	gao = new(__DIR__"gao");
	gao->set("eff_gin",query("eff_gin"));
	gao->set("eff_kee",query("eff_kee"));
	gao->set("eff_sen",query("eff_sen"));
	gao->set("gin",query("gin"));
	gao->set("kee",query("kee"));
	gao->set("sen",query("sen"));
	gao->move(environment());
	message_vision(HIY"\n高猛的幻影渐渐收拢，变回孤身一人。\n"NOR,gao);
/*
// 证实mudos存在一个奇怪的bug: object"量"在作为组使用时其实是一个pointer?!
	ccommand("say a"+enemy[0]->name());
	t = enemy[0];
	ccommand("say c"+t->name());
	dispel_m();
	ccommand("say d"+t->name());
	ccommand("say b"+enemy[0]->name());

高猛说道：a孤松先生
高猛说道：c孤松先生
高猛说道：d孤松先生

执行时段错误：*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.

程式：d/shaolin/npc/gao_mirrorimage.c 第 148 行
*/
// 在得知错误根源后，我们可以设法解决：
/*
	ccommand("say a"+enemy[0]->name());
	t = enemy;
	ccommand("say c"+t[0]->name());
	dispel_m();
	ccommand("say d"+t[0]->name());
	ccommand("say b"+enemy[0]->name());
	这段程式依然不能给我我想要的结果>"<
	一样在	ccommand("say d"+t[0]->name());这行取到0
*/
/*
	ccommand("say a"+enemy[0]->name());
	t = ({ });
	for (k=0;k<sizeof(enemy) ;k++)
		t += ({ enemy[k] });
	ccommand("say c"+t[0]->name());
	dispel_m();
	ccommand("say d"+t[0]->name());
	ccommand("say b"+enemy[0]->name());

	hmm....总算弄好了,天啊,这素什么方法啊..
	用t=enemy会指向enemy的给值语句:enemy=query_enemy()
	而非要用t=,t+=的方法一个个搬过去才正常....爆,太狗血了>"<
	
	这个古怪的问题会不会是其他一些悬而未决的bug的根源?
	; annie 07.2003

	ps,为修正query_rival()问题,attack.c line98附近的remove_killer()函式需要改成：
	// Stop killing ob.
	int remove_killer(object ob) {
	if(is_killing(ob->query("id"))) {
		killer -= ({ ob->query("id") });
		rival -= ({ ob });
	}
***	rival -= ({ 0 });
	return remove_enemy(ob);
}

*/
	t = ({ });
	for (k=0;k<sizeof(enemy) ;k++)
		t += ({ enemy[k] });
	dispel_m();
	gao->rebuild_images(t);
	return;
}


void smart_fight()
{
	if (!random(8) && query("reward_npc"))
		mirror_images();
	else if (!random(60))
		ccommand("perform yaozhan");
	
	return;
}

void dispel_mi()
{
	object gao;
	if (query("reward_npc"))
	{
		gao = new(__DIR__"gao");
			gao->set("eff_gin",query("eff_gin"));
			gao->set("eff_kee",query("eff_kee"));
			gao->set("eff_sen",query("eff_sen"));
			gao->set("gin",query("gin"));
			gao->set("kee",query("kee"));
			gao->set("sen",query("sen"));

		gao->move(environment());
		message_vision(HIY"\n高猛叹了口气，收拢身形归于一体。\n\n"NOR,gao);
		gao->dispel_mi();
	}
	else
	{
		message_vision(CYN"\n高猛的分身化影在空中慢慢散去．．．\n\n"NOR,this_object());
		destruct(this_object());		
	}
	return;
}


void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;

	if (!query("reward_npc"))
	{
		message_vision(CYN"\n高猛化作一缕烟气，渐渐散开消逝无痕。\n\n"NOR,this_object());
		destruct(this_object());
		return;
	}
	message_vision(CYN"\n高猛叹道：好，很好。\n高猛向在场的人道别：走咯！我会想你们的．．．\n"NOR,this_object());
	dispel_m();

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
	

	if (environment(me)->query("short") != "高寒殿" || !REWARD_D->check_m_success(enemy,"多事之秋"))
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

	enemy->set("annie/demon_killed_gao",1);
//	REWARD_D->riddle_done(enemy,"利益",100,1);
	::die();
	return;
}


void killed_enemy(object who)
{
    command("sigh");
    command("comfort "+who->query("id"));
    command("say Tomorrow is another day.");
    command("wave "+who->query("id"));
	message_vision("\n",who);
}
