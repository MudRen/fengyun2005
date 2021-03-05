//written by Cheng Bao
// gangster.c

#include <ansi.h>
inherit NPC;
void goaway();
void create()
{
        set_name("山西劫匪", ({ "shanxi gangster","gangster" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", "这强盗满脸伤疤，虎背熊腰，一脸凶狠而霸道的样子。");
        set("attitude", "heroism");
        
        set("bellicosity", 1500 );
        set("combat_exp", 10000);
		set("no_lu_letter",1);
        set("chat_chance", 50);
        set("chat_msg", ({
		(: goaway :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              	"强盗显是以劫为生，刀刀冲要害而来。\n",
              	"强盗高喊：叫你人财两空。\n",
        }) );

        set("force_factor",20);
        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        
        set_skill("demon-steps",100);
        set_skill("demon-blade",120);
        set_skill("demon-strike",120);
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("unarmed","demon-strike");
	    setup();
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
	object ob;
	if (ob=present("li biaotou",environment()) )
	{
		command("grin");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return; 
	}
		
	message_vision("$N一声唿哨，消失得无影无踪！\n",this_object());
	destruct(this_object());
}


void unconcious()	{ die();}


void	die(){
	
	object killer;
	string deathmsg;
	string *msg = ({
		"\n山西劫匪倒在地上挣扎了几下道：完了完了，兄弟我先走一步。\n",
		"\n山西劫匪捂着胸口痛苦地说：早知道，就不当土匪了。\n",
		"\n山西劫匪尖叫道：我中弹了！我中弹了！Ｍｅｄｉｃ！\n",
		"\n山西劫匪把嘴一拧：二十年后又是一条好汉！\n",
		"\n山西劫匪惊恐地说：怎么回事，不是说护镖的是菜鸟么！\n",
	});
	
	deathmsg = msg[random(5)];
	
	if (objectp(killer = query_temp("last_damage_from"))) {
		if (killer->query("id")=="shanxi laoda")
			deathmsg = "\n山西劫匪尖叫道：老大，杀错人了！！\n";
	}		
	message_vision(HIR""+ deathmsg + "\n山西劫匪死了。\n"NOR, this_object());
	destruct(this_object());
}

