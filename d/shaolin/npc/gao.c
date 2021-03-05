// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之紧那罗王 众妙莲华 高猛 
// EXP 8M KEE 80K GIN/SEN 60K RESIST/ALL 50
// STR 95 DMG 988 ATTACK 752K DODGE 730K PARRY 490K
// 分身化影(4x)，Counter-Attack，极小机率PERFORM YAOZHAN(almost 1hit gone)。

// A/D/P：标准8M状态。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("高猛", ({ "gao meng","gao"}) );
	set("gender", "男性" );
	set("title",YEL"大光明教 "NOR CYN"紧那罗王"NOR);
	set("nickname",HIY"众妙莲华"NOR);
	set("age", 30+random(10));

	set("attitude","friendly");

	set("long",
		"高猛原非中土人士。来自东瀛的他，本是为了寻回天枫带走的一\n刀流密印而涉足中原，却在踏上东土之后醉痴于中原武学的博大\n精深，四处拜投各派而屡屡碰壁。此后他就在中原消失，人们也\n渐渐将他遗忘，仿佛他从来未曾出现；然而却没有人知道，他已\n找到唯一肯接纳他，看重他的魔教。\n"
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

	set("chat_chance", 1);
        set("chat_msg", ({
                "高猛打量着柱子上的名字，连连点头：汉人能人辈出，果然名不虚传！\n",
                "高猛嘿嘿冷笑道：只是汉人不思长进，排斥异己，固步自封的本事，也是名不虚传。\n",
                "高猛皱眉思索道：那"YEL"形意六合棍法"NOR"，以我忍术分身诀来施展的话．．．\n",
                "高猛惊讶的看了你一眼，咦道：你是谁？怎么过的了铜人阵？\n",
                "高猛对掌中吹了口气，叹道：北平高家的义父，也该找个时候去探望一下了。\n",
                }) );

    set("inquiry", ([
        "形意六合棍法": "紧那罗王的形意六合棍法，配上我东瀛忍术，天下无敌。",
        "xingyi stick": "紧那罗王的形意六合棍法，配上我东瀛忍术，天下无敌。",
        "xingyi-stick": "紧那罗王的形意六合棍法，配上我东瀛忍术，天下无敌。",
        "少林派":   "少林和尚，武功好，心眼不好。",
        "少林":   "少林和尚，武功好，心眼不好。",
        "shaolin":   "少林和尚，武功好，心眼不好。",
        "教主":   "action高猛摇摇头道：不要问，不要问。",
        "魔教":   "action高猛摇摇头道：不要问，不要问。",
        "demon":   "action高猛摇摇头道：不要问，不要问。",
        "大光明教":   "action高猛摇摇头道：不要问，不要问。",
        "西方神教":   "action高猛摇摇头道：不要问，不要问。",
        "百晓生":   "少林和尚，武功好，心眼不好，百晓生尤其不好。\n高猛又说道：不过他既然愿意帮我，我就不说他哪里不好。",
        "拜":   "少林和尚，武功好，心眼不好，百晓生尤其不好。\n高猛又说道：不过他既然愿意帮我，我就不说他哪里不好。",
        "拜拜":   "少林和尚，武功好，心眼不好，百晓生尤其不好。\n高猛又说道：不过他既然愿意帮我，我就不说他哪里不好。",
        "bai":   "少林和尚，武功好，心眼不好，百晓生尤其不好。\n高猛又说道：不过他既然愿意帮我，我就不说他哪里不好。",
        "经书":   "百晓生答应把经书给我，怎么到现在还没来？",
        "book":   "百晓生答应把经书给我，怎么到现在还没来？",
        "盗经书":   "百晓生答应把经书给我，怎么到现在还没来？",
        "贼":   "贼？什么贼？我不知道。",
        "thief":   "贼？什么贼？我不知道。",
         ]) );

		
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
               (: smart_fight(this_object()) :),
        }) );


	setup();
	set_temp("counter_action_extra",1);
	set_temp("counter_msg",CYN"$N看准破绽，倏然一跃而过，出手反击！\n"NOR);

	carry_object(__DIR__"obj/gaoarmor")->wear();
	carry_object(__DIR__"obj/paper1");
}

int kill_ob(object who)
{
	object me,mirrorimage;
	int i,j;
	message_vision(HIY"高猛冷笑一声，身形一晃，化作一模一样的四个人影。\n\n"NOR,this_object());
	i = random(4);
	for (j=0;j<4;j++)
	{
		mirrorimage = new(__DIR__"gao_mirrorimage");
		if (i == j)
		{
		    mirrorimage->set("reward_npc", 1);
			mirrorimage->set("difficulty",7);
		}
		mirrorimage->move(environment());
		mirrorimage->set("eff_gin",query("eff_gin"));
		mirrorimage->set("eff_kee",query("eff_kee"));
		mirrorimage->set("eff_sen",query("eff_sen"));
		mirrorimage->set("gin",query("gin"));
		mirrorimage->set("kee",query("kee"));
		mirrorimage->set("sen",query("sen"));
		mirrorimage->kill_ob(who);
		who->kill_ob(mirrorimage);
	}
	destruct(this_object());
	return 1;
}

void dispel_mi()
{
	int i;
	object mi;
	for (i=0;i<4 ; i++)
	{
		mi=present("mirror image",environment());
		if (mi)
			destruct(mi);
	}
	return;
}

void rebuild_images(object * enemy)
{
	object me,mirrorimage;
	int i,j,k;
	dispel_mi();
	message_vision(HIY"高猛长吸一口真气，身形再展，化作四重幻影。\n\n"NOR,this_object());
//	ccommand("say "+sizeof(enemy)); 	// debug,by annie 07.2003
	i = random(4);
	for (j=0;j<4;j++)
	{
		mirrorimage = new(__DIR__"gao_mirrorimage");
		if (i == j)
		{
		    mirrorimage->set("reward_npc", 1);
			mirrorimage->set("difficulty",7);

			// dispel but copy GKS
			mirrorimage->set("eff_gin",query("eff_gin"));
			mirrorimage->set("eff_kee",query("eff_kee"));
			mirrorimage->set("eff_sen",query("eff_sen"));
			mirrorimage->set("gin",query("gin"));
			mirrorimage->set("kee",query("kee"));
			mirrorimage->set("sen",query("sen"));
		}
		mirrorimage->move(environment());
		for (k=0; k<sizeof(enemy); k++)
		{
/*			ccommand("say k="+k);
			ccommand("say enemy[k]="+enemy[k]->name());
			ccommand("say 123");*/	// debug,by annie 07.2003
			mirrorimage->kill_ob(enemy[k]);
			enemy[k]->kill_ob(mirrorimage);
		}
	}
	destruct(this_object());
	return;
}

