inherit SMART_NPC;
#include <ansi.h>


int do_exp(string arg);

string *first_name = ({ 
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","梁丘","左丘","东门","西门",	});
string *name_words = ({ "藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候", });

void create()
{
	set_name("空白人物", ({ "boss" }) );
	set("long", "一个脸上画着个大大的问号的、没有面目的人。\n");
	set("drop_rate",15);
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

	// 根据角色强度设置能力，此处silencer决定．．．
	set("max_kee",who->query("max_kee"));
	set("max_sen",who->query("max_sen"));
	set("max_gin",who->query("max_gin"));

	set("combat_exp",who->query("combat_exp"));

	reset_strength(who);	// To prevent "enforce 0" trick.
	// Str +
	set("str",query("str")*13/10);
	set("force_factor",query("force_factor")*13/10);
	// Exp + 
	set("combat_exp",query("combat_exp") / 10 * 13);
	// GKS +
	set("max_kee",query("max_kee") * 4);
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("max_sen",query("max_sen") * 3);
	set("eff_sen",query("max_sen"));
	set("sen",query("max_sen"));
	set("max_gin",query("max_gin") * 3);
	set("eff_gin",query("max_gin"));
	set("gin",query("max_gin"));
	// Resistance +
	set("resistance/kee",query("resistance/kee")+35);
	set("resistance/gin",query("resistance/gin")+35);
	set("resistance/sen",query("resistance/sen")+35);



	auto_npc_setup("man",best_basic_skill+50,best_adv_skill+50,1,"/obj/weapon/","random","random",3);

	do_exp(query("combat_exp")+"");

	// 如果一个blocker被创立，其时ppl一定在线上。
	set("title",who->query("private_maze/orig_name"));
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "boss" }) );
	set("long", "\n");

	return 1;
}


void die()
{
	object env=environment(),killer=query_temp("last_damage_from"),book;
	object who,sic;
	int exp,reward;

string *list=({
	__DIR__"pq_reward/force_scroll",
	__DIR__"pq_reward/atman_scroll",
	__DIR__"pq_reward/mana_scroll",
	__DIR__"pq_reward/kee_scroll",
	__DIR__"pq_reward/gin_scroll",
	__DIR__"pq_reward/sen_scroll",
	__DIR__"pq_reward/parry_scroll",
	__DIR__"pq_reward/dodge_scroll",
	__DIR__"pq_reward/no_busy_scroll",
	__DIR__"pq_reward/damage_scroll",
	__DIR__"pq_reward/protect_scroll",
} );
	seteuid(getuid());

	if (killer)
	{
//		ccommand("say "+killer->name());
//		ccommand("say "+base_name(killer->query_temp("maze_entry"))+".c");
		
		if (who=team_check(killer,"private_maze/destination",1,base_name(killer->query_temp("maze_entry"))+".c"))
		{
//			ccommand("say "+who->name());
			// quest的获取人是否还在线上？
			// 如果是，

			// remove quest data
			who->delete("private_maze/destination");
			sic=find_player(env->query("mark_ob"));
				
			if ( QUESTS_D->verify_quest(who,"私人迷宫" ))
				QUESTS_D->special_reward(who,"私人迷宫");

			// Private Quest Special Reward.
			if (random(100) < query("drop_rate"))
			{
				book = new(list[random(sizeof(list))]);
				book->move(who);
				tell_object(who, WHT"你得到了一本"+book->name()+WHT"！\n"NOR);

			}
		}
	}


	env->destruct_maze();
	// 当殺死boss時，毀滅maze
	if (sic)
		sic->delete("private_maze/maze");
	::die();
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
