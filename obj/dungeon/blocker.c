#include <ansi.h>
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
	set("dd",1);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int invocation(int exp)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, name;
    int loop;
	string tmp1,tmp2;
	int flag,best_basic_skill=1,best_adv_skill=1;
	mapping skl,map;
	string *sname,*mapped;
	
	if (!exp)
		exp = 10000000;

	set("combat_exp",exp);

	auto_npc_setup("bandit",200,200,1,"/obj/weapon/","random","random",query("dd"));

	do_exp(query("combat_exp")+"");
	set("title",WHT+query("maze/name")+NOR);

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "bandit" }) );
	set("long", "一个穷凶极恶的小喽罗挡住了你的去路，不把他除掉看来是没法走脱了。\n");
	set("group","standardmaze_bandit");
	return 1;
}


int do_exp(string arg)
{
	// exp calc inherited from my in ^^
	int exp;
	int pow_exp;
    int loop;
	int a_skill, b_skill;
	mapping skl,map;
	string *sname,*mapped;

	int flag,enforce,best_force=1;

	if (!arg)
		return notify_fail("[Usage]: Exp <NPC-EXP>\n");
	exp = atoi(arg);
	set("combat_exp",exp);

	b_skill = 250;

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
			
			if (sname[loop] == "xuezhan-spear") a_skill = 250;
				else 	a_skill = 200; 
				 
			// Basic skill : cap @ 300 | 按系数1.6计算.
			if (SKILL_D(sname[loop])->effective_level() == 50)
				if (skl[sname[loop]] > 300 || skl[sname[loop]] > pow_exp*100/160)
				set_skill(sname[loop],b_skill >pow_exp*100/160?pow_exp*100/160: b_skill);	

			// Advance skill : cap @ 200.
			if (SKILL_D(sname[loop])->effective_level() != 50)
				set_skill(sname[loop],a_skill>pow_exp*100/SKILL_D(sname[loop])->effective_level()?pow_exp*100/SKILL_D(sname[loop])->effective_level():a_skill);	 

			if (SKILL_D(sname[loop])->valid_enable("force"))
				if (SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force)
					best_force = skl[sname[loop]];

		}
	}

	"/feature/nada.c"->reset_npc(this_object());
	full_me();
	message_vision("\n",this_object());

	return 1;
}

void die(){
	
	object room2;
	object *env;
	int x,i;
	
	env = all_inventory(environment(this_object()));
	
	for  (i=0;i< sizeof(env);i++) {
		if (env[i]->query("group")=="standardmaze_bandit" && env[i]!=this_object())
			x = 1;
	}
	
	if (x==0)
		environment(this_object())->set("cleared",1);
	
	room2 = find_object("/obj/dungeon/standardmaze/"+ environment(this_object())->query("mark_ob")+"/entry");
	if (room2) {
		room2->add("maze/npc_killed",1);
	//	room2->check_quest(1);
	}
	
	::die();
}
