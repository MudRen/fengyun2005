#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("公子羽", ({ "gongzi yu", "yu" }) );
	set("gender", "男性" );
        set("quality","evil");
	set("nickname",HIC"一尘不染"NOR);
        set("title","世袭一等侯 小侯爷");
	set("age", 27);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"从背后看过去，他的风度优美，无懈可击。可是，他脸上却偏偏戴着个狰狞 
而丑恶的青铜面具，而冷酷的眼神，却远比面具可怕。\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 6000000);
        set("score", -16000);
        set("strategy","brave");
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("sword", 400);
	set_skill("move",200);
	
	set_skill("suiyuan-sword",300);
	set_skill("meihua-shou", 130);
	set_skill("huanhua-steps",200);
	map_skill("unarmed", "meihua-shou");
	map_skill("sword","suiyuan-sword");
	map_skill("parry","suiyuan-sword");
	map_skill("dodge","huanhua-steps");
	map_skill("move","huanhua-steps");
	set("hunting",1);
	set("chat_chance",2);
	set("chat_msg",	({
	"公子羽脸上露出讥诮之意，道：我与傅红雪这一战，让我等多久都没关系，因为
无论等多久，胜负都不会变。\n"
	})	);  
	set("w_type","sword");
/*        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.meihai":),
        }) );
*/      
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/d/wolfmount/npc/obj/softsword")->wield();
	add_money("gold",10);
}
int normal_busy(object opp)
{
	if(random(100)>90)
	{
		set("class","legend");
		command("unwield all");
		command("perform meihai "+opp->get_id());
		command("wield all");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	set("force_factor",55);
	if(random(100)>90)
	{
		set("class","shaolin");
		command("wield all");
		command("perform yiqiesuiyuan "+opp->get_id());
		if(!query_busy())
			command("perform yiqiesuiyuan "+opp->get_id());
		delete("class");
	}
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","legend");
		command("unwield all");
		command("perform meihai "+opp->get_id());
		command("wield all");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	set("force_factor",90);	
	if(random(100)>50)
	{
		set("class","shaolin");
		command("wield all");
		command("perform yiqiesuiyuan "+opp->get_id());
		if(!query_busy())
			command("perform yiqiesuiyuan "+opp->get_id());
		delete("class");
	}
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
		set("class","legend");
		command("unwield all");
		command("perform meihai "+opp->get_id());
		command("wield all");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
		set("force_factor",130);
	if(random(100)>10)	
	{
		set("class","shaolin");
		command("wield all");
		command("perform yiqiesuiyuan "+opp->get_id());
		if(!query_busy())
			command("perform yiqiesuiyuan "+opp->get_id());
		delete("class");	
	}
	return 1;
}