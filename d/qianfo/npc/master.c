// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void smart_fight();
int leave();
void create()
{
    set_name("兴国大师", ({ "master xing", "master", "xing" }) );
    set("gender", "男性");
    set("nickname", HIY "佛法无边"NOR);
    set("long", "兴国禅寺住持，百年来不世出的有道高僧。\n");
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3);

    create_family("兴国禅寺", 3, "住持");
    set("rank_nogen",1);
	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
	set("ranks",({"小沙弥","小和尚","守山僧","布衣僧","麻衣僧","白衣僧","灰衣僧","黑衣僧",
		"护寺大师","护法罗汉","护国金刚","护寺神僧",YEL"护法圣僧"NOR,YEL"护国活佛"NOR,
		YEL"净土宗传人"NOR,HIY"净土宗宗主"NOR}));				
    set("reward_npc", 1);
    set("difficulty", 10);

    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
	(: smart_fight() :),
      }) );
    set("fly_target",1);

    set("combat_exp", 20000000);
    set("guard_msg",HIW"$N喝道：阿弥陀佛,出家人与世无争，却也不任人欺侮，施主请了！！\n"NOR);

    set_temp("apply/haste",400);
    set_temp("apply/armor", 200);
    set_temp("apply/damage", 200);
    set("score", 9000);

    set_skill("force", 180);
    set_skill("chanting", 200);
    set_skill("magic", 200);
    set_skill("unarmed", 170);
    set_skill("literate", 150);	
    
    set_skill("parry", 160);
    set_skill("staff", 250);
    set_skill("dodge", 160);
    set_skill("move",160);
    
    set_skill("foreknowledge", 100);
    set_skill("perception", 100);

    set_skill("cloudstaff", 180);
    set_skill("lotusforce", 150);
    set_skill("buddhism", 220);
    set_skill("essencemagic", 220);
    set_skill("nodust-steps",200);
    set_skill("dabei-strike",180);

    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");
    map_skill("force", "lotusforce");
    map_skill("magic", "essencemagic");
    map_skill("dodge","nodust-steps");
    map_skill("unarmed","dabei-strike");
    map_skill("move","nodust-steps");

    set("inquiry", ([
	"leave" : (: leave :),
      ]));   	

    setup();
    carry_object(__DIR__"obj/buddha_staff")->wield();
    carry_object("/obj/armor/cloth")->wear();

}

void attempt_apprentice(object ob)
{
    if(ob->query("marry") && !ob->query("jiebai")){
	message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
	  this_object(), ob);
	return;
    }	
    if( (string)ob->query("gender") != "男性" ) {
	command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
	return;
    }
    if (ob->query("family/master_id")!="master can"
      || ob->query("family/master_name") != "参机大师"
      || ob->query("class") != "bonze") {
	command("shake");
	command("say 老衲不轻易收徒。");
	return;
    }

    command("say 阿弥陀佛，善哉！善哉！");
    if (ob->query_skill("buddhism",1)<150) {
		command("say 你的佛法修为太低，还是再去多修炼几年吧。（需１５０级）");
		return;
    }

	if (!REWARD_D->check_m_success( ob,"吃面")) {
		command("say 老僧尚有一事相托，两日前好友楚香帅"WHT"飞鸽传书"CYN"，你可替老僧前去。");
		ob->set_temp("marks/xg_master",1);
		return;
	}	
		
    command("say 既然是参机大师推荐了你，老衲就破例收你为徒。");
    command("recruit " + ob->query("id") );

}


int accept_fight(object me)
{
    if( (string)me->query("class")=="bonze" )
	command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
    else
	command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");

    return 0;
}

void init()
{	
    ::init();
    add_action("do_killing", "kill");

}


int leave() {
    if (this_player()->query("class")!="bonze") return 0;
    message_vision(CYN"$N合掌道：阿弥陀佛，既是无缘，何必再留，以后也不要再回来了。\n"NOR, this_object(),this_player());
    message_vision(CYN"$N说：佛门的神通术和心法非弟子不能使用。\n"NOR,this_object(),this_player());
    return 1;
}

smart_fight()
{
    int i;
    object *enemy, who;
    who = this_object();
    enemy = this_object()->query_enemy();
    i = sizeof(enemy);
    if (i>3) {
	command("conjure light_sense");
	return;
    }
    who->perform_action("staff.longxianyuye"); 
    return;
} 
