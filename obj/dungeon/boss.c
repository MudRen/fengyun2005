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
//	set("drop_rate",15);
	
	set("dd",1);	// default difficulty
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	   	(: auto_smart_fight(100) :),    
    }) );
	set("attitude", "friendly");	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void die(){
	
	object room2,book;
	int n,i;
	
	environment(this_object())->set("cleared",1);
	
	room2 = find_object("/obj/dungeon/standardmaze/"+ environment(this_object())->query("mark_ob")+"/entry");
	if (room2) {
		room2->add("maze/leader_killed",1);	// Boss 算两个
		room2->set("maze/cleared",1);
		n = room2->query("maze/type");
		if (room2->query("maze/exp")>= 6100000)
		for (i=0;i<n;i++){
			book=new("/obj/item/treasurebook");
			book->move(this_object());
		}		
//		room2->check_quest();
	}
	::die();
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
	set("title",WHT+query("maze/name")+ " 首领"NOR);

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "bandit leader","leader" }) );
	set("long", "此人看来是这儿的首领，正狠狠地瞪着你。\n");
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
//				if (skl[sname[loop]] > 300 || skl[sname[loop]] > pow_exp*100/160)
				set_skill(sname[loop],b_skill >pow_exp*100/160?pow_exp*100/160: b_skill);	// 

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
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
