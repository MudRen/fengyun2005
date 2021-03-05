inherit SMART_NPC;

int do_exp(string arg);
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
	"刘","林" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
	"孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
	"富","万","龙","隆","祥","栋","国","亿","寿" });

void create()
{
	set_name("空白小人物", ({ "man" }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	setup();
}


int reset_strength(object who)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
	int flag,enforce,best_force=1;
	mapping skl,map;
	string *sname,*mapped;

	skl = who->query_skills();
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = who->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			if (SKILL_D(sname[loop])->valid_enable("force"))
				if (SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force)
					best_force = skl[sname[loop]];
	}

	enforce = (who->query_skill("force",1) / 2 + best_force) / 3;

	
	set("str",who->query("str"));
	set("force_factor",enforce);

	if (query("str") < 25)
		set("str",25);
	if (query("force_factor") < 60)
		set("force_factor",60);

	return 1;
}

int invocation(object who)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, name;
    int loop;
	string tmp1,tmp2;
	int flag,best_basic_skill=1,best_adv_skill=1;
	mapping skl,map;
	string *sname,*mapped;
	
	if (!who)
		return 0;


	skl = who->query_skills();
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = who->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
		{
			if (SKILL_D(sname[loop])->effective_level() == 50)
				if (skl[sname[loop]] > best_basic_skill)
					best_basic_skill = skl[sname[loop]];
			if (SKILL_D(sname[loop])->effective_level() != 50)
				if (skl[sname[loop]] > best_adv_skill)
					best_adv_skill = skl[sname[loop]];
		}

	}

	set("max_kee",who->query("max_kee"));
	set("max_sen",who->query("max_sen"));
	set("max_gin",who->query("max_gin"));

	set("combat_exp",who->query("combat_exp"));

	reset_strength(who);	// To prevent "enforce 0" trick.
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("eff_sen",query("max_sen"));
	set("sen",query("max_sen"));
	set("eff_gin",query("max_gin"));
	set("gin",query("max_gin"));
	auto_npc_setup("man",best_basic_skill,best_adv_skill,1,"/obj/weapon/","random","random",3);

	do_exp(query("combat_exp")+"");

	// 如果一个blocker被创立，其时ppl一定在线上。
//	set("title","属于"+who->name()+"的");
	set("title",who->query("private_maze/orig_name"));

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "man" }) );
	set("long", "\n");


	return 1;
}






int do_exp(string arg)
{
	// exp calc inherited from my in ^^
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

	"/feature/nada.c"->reset_npc(this_object());
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object());
	message_vision("\n",this_object());

	return 1;
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


/*

*/