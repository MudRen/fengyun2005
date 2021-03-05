#include <ansi.h>
inherit SMART_NPC;
int randommove();
int do_exp(string arg);

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
	"刘","林" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
	"孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
	"富","万","龙","隆","祥","栋","国","亿","寿" });

void create()
{
	object ob;
	set_name("空白小人物", ({ "tasker" }) );
	set("str",40);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
  }) );
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
	object ob;
		
	if (!exp)
		exp = 10000000;

	set("combat_exp",exp);
	set("tasker",1);
	auto_npc_setup("bandit",200,200,1,"/obj/weapon/","random","random",2);

       set("chat_chance", 100);
       set("chat_msg", ({
                (: randommove :),	
       }) );
        
	do_exp(query("combat_exp")+"");

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "tasker" }) );

	if (exp>9500000)	set("title",HIR"魔教圣使"NOR);
	else if (exp>9000000)	set("title",HIY"魔教巡行使"NOR);
	else set("title",HIW"魔教抚慰使"NOR);
		
		
	set("long", "一个黑衣人，忙忙碌碌地在赶路。\n");
	ob = carry_object("/obj/money/gold");
	ob->set_amount(3+random(3));
	return 1;
}


int random_move()
{
	mapping exits;
	string *dirs, direction, dest, last_room;
	object env;
	int i;
	
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	last_room = query("last_room");
	dirs = keys (exits);
	if(!sizeof(dirs)) return 0;
	dest = last_room;
	i=0;
	while(dest==last_room&&i<20)
	{
		direction = dirs[random(sizeof(dirs))];
		dest = environment()->query("exits/"+direction);
		i++;
	}
//	if(i==5)
//		return 0;
	set("last_room",file_name(environment()));			
	command("go " + direction);
	return 1;
}

int randommove()
{
		string *msg;
		int chance, rnd;
		string new_room;
		object room,old_room;

		if( !environment() ) return 0;
		if( query_temp("is_unconcious") ) return 0;
		        
    if(environment()->query_doors())
			command("open door");
		
		if (query("kee")<query("max_kee")				// 没养好伤不许走
					|| query("gin")<query("max_gin")
					|| query("sen")<query("max_sen"))
					return	0;
		
		if (random(100)>85)
		{
			if (random(100)>98 || !this_object()->random_move())
			{
				old_room=environment(this_object());
				new_room=TASK_D->random_room();
				if(!room=find_object(new_room))
					room=load_object(new_room);
				this_object()->move(room);
				tell_room(old_room,this_object()->query("name")+"长啸一声，纵身而去。\n");
				tell_room(room,"人影一闪，"+this_object()->query("name")+"出现在你面前。\n");
			} 
		}
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

int self_destruct(){
	
		if (is_fighting() || is_busy()) {
			call_out("self_destruct",30);
			message_vision(CYN"$N叹道：晚了、晚了，居然被屑小之辈误了我的大事！"NOR,this_object());
			return 1;
		}	
		message_vision(WHT"$N叹了口气，纵身一跃，转瞬间消失的无踪无影。\n"NOR,this_object());
		destruct(this_object());
		return 1;
}


void init()
{
    object ob;
    int chance;
    string where; 
    
    ::init();
    	
    if (!ob=environment(this_object()))	return;
        	
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        if (ob->query("combat_exp") <4100000 || ob->query_temp("is_unconcious"))	return;		// 不杀无反抗之力者

			  where = file_name(ob);
 				if (where && where[0..5] == "/d/fy/")	return;
   
        chance = ob->query("TASK")/200;
				if (random(100)< chance) {        
            remove_call_out("greeting");
        		call_out("greeting", 1, ob);
    		}
    }
}

void greeting(object ob)
{   
	string where, location;
	if( !interactive(ob) || environment(ob) != environment() )		return;
  message_vision("$N嘿嘿道：够胆量！居然敢跟圣教争抢使命，拿命来吧！\n", this_object() );
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}
