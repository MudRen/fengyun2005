#include <ansi.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	set_name("凝轻", ({"in"}) );
	set("gender", "女性" );
	set("combat_exp", 10000000);
	set("attitude", "peaceful");
	set("age",32);

	set("n_type",2);
	set("accept_npc_fight",0);
   
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
		(: 	smart_fight() :),
    }) );
	

	auto_npc_setup("in",300,220,1,"/obj/weapon/","random","random",query("n_type"));
	setup();
}

int init()
{
	add_action("do_exp","exp");
	add_action("do_ccc","ccc");
	add_action("do_ref","ref");
	add_action("do_lev","lev");
	add_action("do_npc","npc");
}

int do_npc(string arg)
{
	if (query("accept_npc_fight"))
		delete("accept_npc_fight");
	else
		set("accept_npc_fight",1);

	ccommand("say Done. set my npc-fight mode to "HIC+query("accept_npc_fight")+NOR".\n");
	return 1;
}

int do_lev(string arg)
{
	if (!arg)
		return notify_fail("[Usage]: Lev <Npc List-Index>\n");
	if (atoi(arg) < 1 || atoi(arg) > 5 )
		return notify_fail("[Usage]: Lev <Npc List-Index>\n");
	set("n_type",atoi(arg));
	ccommand("say Done. set my list to "HIW+arg+NOR".\n");
	return 1;
}

int do_ref(string arg)
{
	mapping skl;
	string *sname;

	ccommand("drop all");

	skl = query_skills();
	while (sizeof(skl) > 0)
	{
		skl = query_skills();
		sname  = sort_array( keys(skl), (: strcmp :) );
		delete_skill(sname[0]);
	}


	if (arg)
		auto_npc_setup("in",300,220,1,"/obj/weapon/","random",arg,query("n_type"));
	else
		auto_npc_setup("in",300,220,1,"/obj/weapon/","random","random",query("n_type"));
	
	this_player()->ccommand("exp "+query("combat_exp"));

	if (query("npc") == "smallguy")
		ccommand("say No such type npc. set to default random type.");

	return 1;
}

int do_ccc(string arg)
{
	if (!arg)
		return notify_fail("[Usage]: CCC <Perform chance>\n");
	set("chat_chance_combat",atoi(arg));
	ccommand("say Done. Set my perform chance to "HIG+ atoi(arg)+NOR".\n");
	return 1;
}

void setup_human() {
	mapping my;
	int combat_exp, bonus, npc_str, npc_att;
	int n, npc_force, npc_f_factor;
	int *extra_d, num;
	mapping extra = ([]);
		
	my = query_entire_dbase();
	
	if (!my["combat_exp"] || my["combat_exp"]< 2000) my["combat_exp"] = 2000;
	combat_exp = my["combat_exp"];
	
		if (combat_exp<100000) {
			npc_str = 10 + random(10) + combat_exp/20000; 			// 10-15 (+15)
			npc_att = 10 + random(5) + combat_exp/20000;    		// 10-15  (+5)
			npc_force = (combat_exp <= 10000)? 0: combat_exp*350/100000;	// 450 
		}
	
		n= combat_exp/100000;	// 10
		if (n<=10 && n>=1) {
			npc_force = 450 + combat_exp/1200;  // 450-1300
			npc_str= 15+ random(10) + n;	    // 16-25 (+9) Also should apply to con.
			npc_att = 10+ random(15)+ n;	    // 10-20 (+14)
			npc_f_factor = 40 + n*4;	    // 40 -80	
		}
	
		if (n<=30 && n>10) {
			npc_force = 1200;			// full guyupai etc
			npc_str = 21 + random(6) + n/2; 	// 21- 36 (+6)
			npc_att=  20+ n/6+ random(10);		// 20 -30 (+9)
			npc_f_factor = 60 + n/2 + random(10);	// 60 - 75 (+9)
		}
		if (n<=50 && n>30) {
			npc_force = 1400+ n*6;			// full guyupai etc 1400-1700
			npc_str = 36 + random(n/6); 	 	// 36 (+9)
			npc_att=  20+ n/6 + random(10);		// 25 -30 (+9)
			npc_f_factor = 90 + n/6 + random(n);	// 95 - 99 (+50)
		}
		if (n>50) {
			npc_force = 1500 + 40 * n;		// 3500- 5500
			npc_str= 40 + random(n/6);		// 40 (+25)
			npc_att= 40 + random(10);		// 35 (+9)
			npc_f_factor = 100 + random(50)+ n/10;	// 100-115 (+50)
		}
	
		my["age"] = 15 + random(50); 
		my["per"] = 15 + random(20);
		
		my["cor"] = npc_str;
		my["con"] = npc_str;
		my["dur"] = npc_str;
		
		my["int"] = npc_att;
		my["spi"] = npc_att;
		
		my["cps"] = npc_att;
		my["kar"] = npc_att;
		my["agi"] = npc_att;
		my["fle"] = npc_att;
		my["tol"] = npc_att;
		
		my["max_force"]= npc_force;
		my["force"]= npc_force;
		my["max_mana"]= npc_force*3/5;
		my["mana"]= npc_force*3/5;
		my["max_atman"]= npc_force*3/5;
		my["atman"]= npc_force*3/5;	
	

		if(my["age"] <= 14) {
			my["max_gin"] = 100 + my["spi"]*10;
		} else if( my["age"] <= 20 ) {
			my["max_gin"] = 100 + (my["age"] - 14) * 20  + my["spi"]*10;
		} else if( my["age"] <= 30 ) {
			 my["max_gin"] = 220  + my["spi"]*10;
		} else if( my["age"] <= 60 ) {
			my["max_gin"] = 220 - (my["age"] - 30) * 5  + my["spi"]*10;
		} else {
			my["max_gin"] = 70  + my["spi"]*10;
		}
		if(my["max_atman"] > 0) {
			my["max_gin"] += my["max_atman"]*3/2 ;
		}
		my["max_gin"] += my["dur"]*my["dur"];
		my["max_gin"] += (my["max_gin"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));


		if(my["age"] <= 14) {
			my["max_kee"] = 100 + my["con"]*10;
		} else if(my["age"] <= 20) {
			my["max_kee"] = 100 + (my["age"] - 14) * 20 + my["con"]*10;
		} else {
			my["max_kee"] = 220 + my["con"]*10;
		}
		if(my["max_force"] > 0) {
			my["max_kee"] += my["max_force"]*2;
		}
		my["max_kee"] += my["dur"]*my["dur"];
		my["max_kee"] += 2*(my["max_kee"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));

		if(my["age"] <= 30) {
			my["max_sen"] = 100 + my["int"]*10;
		} else {
			my["max_sen"] = 100 + (my["age"] - 30) * 5 + my["int"]*10;
		}
		if(my["max_mana"] > 0) {
			my["max_sen"] += my["max_mana"]*3/2 ;
		}
		my["max_sen"] += my["dur"]*my["dur"];
		my["max_sen"] += (my["max_sen"]*(combat_exp/1000000))/(10+6000000/(combat_exp+10));

}

int do_exp(string arg)
{
	int exp;
	int pow_exp;

    int loop;
	mapping skl,map;
	string *sname,*mapped;

	int flag,enforce,best_force=1;

	if (!arg)
		return notify_fail("[Usage]: Exp <NPC-EXP>\n");
	exp = atoi(arg);
	set("combat_exp",exp);

	pow_exp = to_int(pow(to_float(exp*10),0.3334));


	skl = query_skills();
	if (sizeof(skl))	// 设置skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		map = query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
		{
			// Basic skill : cap @ 300 | 按系数1.6计算.
			if (SKILL_D(sname[loop])->effective_level() == 50)
//				if (skl[sname[loop]] > 300 || skl[sname[loop]] > pow_exp*100/160)
				set_skill(sname[loop],300>pow_exp*100/160?pow_exp*100/160:300);	// 

			// Advance skill : cap @ 250.
			if (SKILL_D(sname[loop])->effective_level() != 50)
//				if (skl[sname[loop]] > 250 || skl[sname[loop]] > pow_exp*100/SKILL_D(sname[loop])->effective_level())
				set_skill(sname[loop],250>pow_exp*100/SKILL_D(sname[loop])->effective_level()?pow_exp*100/SKILL_D(sname[loop])->effective_level():250);	// 

			if (SKILL_D(sname[loop])->valid_enable("force"))
				if (SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force)
					best_force = skl[sname[loop]];


		}
	}

	// Reset my force and hp.
	enforce = (query_skill("force",1) / 2 + best_force) / 3;
	set("force_factor",enforce);
	set("str",query_skill("unarmed",1)/5>60?60:query_skill("unarmed",1)/5);

	set("resistance/kee",exp/333333);
	set("resistance/gin",exp/333333);
	set("resistance/sen",exp/333333);

	setup_human();
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object());
	message_vision("\n",this_object());
	
	ccommand("say Done. Set my exp to "HIG+ exp+NOR" ,my npc-type is "HIW+query("npc")+NOR" .\n");
	ccommand("say kee = "+HIR+query("kee")+NOR+" ,str = "HIC+query_str()+NOR" ,resist = "HIY+exp/333333+NOR" .\n");

	return 1;
}

void unconcious()
{
	die();
	return;
}

void die()
{
	remove_all_killer();
	remove_all_enemy();
	message_vision("\n",this_object());
	ccommand("inn");
	ccommand("qifume");
	ccommand("qifume in");
	ccommand("sob");
	ccommand("goodbye");
	message_vision("\n",this_object());
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object());
	return;
}

void win()
{
	remove_all_killer();
	remove_all_enemy();
	message_vision("\n",this_object());
	ccommand("hug in");
	ccommand("haoren in");
	ccommand("wrong in");
	message_vision("\n",this_object());
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
			if (enemy[i]->query("kee") > 0 && enemy[i]->query("gin") > 0 && enemy[i]->query("sen") > 0)
				return enemy[i]; // focus user. ; annie 6.25.03
	if (query("accept_npc_fight"))
		return enemy[0];
	else
		return 0;	// 从0杀起
}

void smart_fight()
{
	object *enemyswarm;
	if (is_busy())
		return;
	
	if (!select_opponent())
	{
		win();
		return;
	}
	
	auto_smart_fight(100);	// rascal design :p

	if (!select_opponent())
	{
		win();
		return;
	}

}

/*
fengyun-
奁镜朱颜辞流水，年华不识花自飞……
dancing_faery@hotmail.com
annie.01.01.2004
*/

// update here;clone /d/bashan/npc/yawnboy;update /adm/daemons/smartd;update /std/char/npc_ann;update /d/bashan/npc/in;clone;npc;lev 5;ref leadership;call sinny->ccommand(kill in)
// update /d/bashan/npc/in;clone;npc;lev 5;ref leadership;



