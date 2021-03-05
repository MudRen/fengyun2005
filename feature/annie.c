// annie 07.04.2003
// dancing_faery@hotmail.com
// 注意：本函式中的temp复制段亦将改变weapon映射，建议设置flag=0取消临时映射复制。
// 注意：本函式并不移除目标源原有属性，不复制身上物件。
// 注意：对于summon出来的NPC，使用时可能有possessed等相关属性需要手动改变。
// 注意：指令复制过去后，请小心区分ID与QUERY_ID返回的不同，建议在呼叫后重设目标源NAME/ID。
// 对应指令：cpstat.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>;

//	inherit F_CLEAN_UP;
/*
void create()
{
	seteuid(ROOT_UID);
}*/

// ------------------以下为玄灵玉盒的处理文件

mapping items=([]);
/* 格式为：
items = ([
	铁剑：	5
	舍利子： 1
]);	
*/
mapping query_qitems() { return items;}

// 返回处理后该物品的剩余值
int add_qitems(string name, int amount)
{
	string *dir;
	int index;
		
    if( !mapp(items) ) {
    	items= ([ name: amount ]);
    	return amount;
    }	
    else {
    	dir = keys(items);
    	index = member_array(name,dir);
		if ( index != -1) {
//			CHANNEL_D->do_sys_channel("sys", "box = " + items[dir[index]] + " amount = "+amount+"\n");
			if (items[dir[index]]+ amount <=0){
				map_delete(items, dir[index]);
				return 0;
			}
			items[dir[index]] += amount;
			return items[dir[index]];
		}	
		else
			items[name]= amount;; 
    }	        	
}

void clear_items(){ items = ([]); }

void set_items(mapping t_items)	{		// this function is for transfering
	
	items = t_items;
	
}

// -------------------------

string ngstr(string str,int lng)
{
        int i,i2;
        string strc;
        strc=str;
        i2=lng-strwidth(str);
        for (i=0; i<i2/2; i++)
        {
                strc=strc+"　";
        }
        if (i2%2)
                strc=strc+" ";
        return strc;

}

string nrstr(string str,int lng,string prefix,string surfix,int ns)
{
        int i;
        string strc;
        string * epl;
 epl= explode(break_string(str,lng),"\n");
 strc="";
 	for (i=0;i<sizeof(epl);i++) {
 	
 	
 	strc=strc+prefix+sprintf(sprintf("%%:-%ds", lng), epl[i])+surfix+"\n";

 	}
         return strc;

}




string annie_mimic(object ob, object ob1)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text/*,*tmp, id, spec*/;
    int loop;
//	string tmp1,tmp2;
	int flag;
	mapping skl,map;
	string *sname,*mapped;

	flag = 0;	// 是否复制临时映射？1:复制 0:不复制

	seteuid(geteuid());

    list = (mapping)ob->query_entire_dbase();
    tlist = (mapping)ob->query_entire_temp_dbase();
    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return "Cpstat：复制源没有任何可读数据。\n";
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    if(!klist || !sizeof(klist))
        return "Cpstat：复制源没有任何可读数据。\n";
    
	text = HIW"物件：" + base_name(ob) + NOR"\n";
	for(loop=0; loop<sizeof(klist); loop++)
		ob1->set(klist[loop],list[ klist[loop] ]);
	text += "\n"HIW+sizeof(klist) + " 个储存的资料已复制到 " +base_name(ob1)+ NOR"\n\n";

	if (flag)
	{
		text += HIW"物件：" + base_name(ob) + NOR"\n";
		for(loop=0; loop<sizeof(tlist2); loop++)
			ob1->set_temp(tlist2[loop],tlist[ tlist2[loop] ]);
		text += "\n"HIW+sizeof(tlist2) + " 个暂存的资料已复制到 " +base_name(ob1)+ NOR"\n\n";
	}

	skl = ob->query_skills();
	if (sizeof(skl))	// 复制skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = ob->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set_skill(sname[loop],skl[sname[loop]]);	// 先复制skill表

		text += HIW+sizeof(skl) + " 个技能已复制到 " +base_name(ob1)+ NOR"\n\n";

		for(loop=0;loop<sizeof(skl); loop++)
			if (ob->query_skill_mapped(sname[loop]))
				ob1->map_skill(sname[loop],ob->query_skill_mapped(sname[loop]));	// 再复制map
	}

//	ob1->set("chat_chance_combat",ob->query("chat_chance_combat"));
//	ob1->set("chat_msg_combat",ob->query("chat_msg_combat"));

    return text;
}



string annie_itemmimic(object ob1,mapping list,mapping tlist)
{
    mixed *klist, *tlist2;
    string text/*,*tmp, id, spec*/;
    int loop;
//	string tmp1,tmp2;
	int flag;
//	mapping skl,map;
//	string *sname,*mapped;

	flag = 1;	// 是否复制临时映射？1:复制 0:不复制

	seteuid(geteuid());

    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return "Cpstat：复制源没有任何可读数据。\n";
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    if(!klist || !sizeof(klist))
        return "Cpstat：复制源没有任何可读数据。\n";
    
	text = HIW"原来源的" + NOR"";
	for(loop=0; loop<sizeof(klist); loop++)
		ob1->set(klist[loop],list[ klist[loop] ]);
	text += HIW+sizeof(klist) + " 个储存的资料已复制到 " +base_name(ob1)+ NOR"\n\n";

	if (flag)
	{
		text += HIW"原来源的" + NOR"";
		for(loop=0; loop<sizeof(tlist2); loop++)
			ob1->set_temp(tlist2[loop],tlist[ tlist2[loop] ]);
		text += HIW+sizeof(tlist2) + " 个暂存的资料已复制到 " +base_name(ob1)+ NOR"\n\n";
	}


    return text;
}

string annie_skillcp(object ob, object ob1)
{
//  mapping list,tlist;
//  mixed *klist,*tlist2;
    string text/*,*tmp, id, spec*/;
    int loop;
//	string tmp1,tmp2;
//	int flag;
	mapping skl,map;
	string *sname,*mapped;

	seteuid(geteuid());

	skl = ob->query_skills();
	if (sizeof(skl))	// 复制skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = ob->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set_skill(sname[loop],skl[sname[loop]]);	// 先复制skill表

		text = HIW+sizeof(skl) + " 个技能已复制到 " +ob1->name()+ NOR"\n\n";

		for(loop=0;loop<sizeof(skl); loop++)
			if (ob->query_skill_mapped(sname[loop]))
				ob1->map_skill(sname[loop],ob->query_skill_mapped(sname[loop]));	// 再复制map
	}
	else
		text = HIW+ob->name()+HIW"没有任何可用的技能。\n\n"NOR;

    return text;
}

string annie_attcp(object ob, object ob1)
{
	string *att = ({"str", "cor", "dur", "agi", "spi", "con", "per", "int", "kar","cps","fle", "tol",
			"max_kee","max_gin", "max_sen", "kee", "gin", "sen", "eff_kee", "eff_gin", "eff_sen",
			"max_force", "max_atman", "max_mana", "force", "atman", "mana", 
			"combat_exp" });
	int loop;
	string text;
		
	for (loop=0; loop<sizeof(att);loop++)
		ob1->set(att[loop],ob->query(att[loop]));
					
	text = HIW + ob->name() + HIW"的基本属性已经复制到" + ob1->name() + HIW"中。\n"NOR;
	return text;
}		

// 只是复制ability,没有ability的点数复制			
string annie_abilitycp(object ob, object ob1)
{
	mapping skl;
	string *sname, text;
	int loop;
	seteuid(geteuid());
	
	text = WHT""+ob->name()+"没有ABILITY\n"NOR;
	
	ob1->delete("ability");
	skl = ob->query("ability");
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set("ability/"+ sname[loop],skl[sname[loop]]);	
		text = HIW+sizeof(skl) + " 个ABILITY已复制到 " +ob1->name()+ NOR"\n";
	}
	
	ob1->delete("ability2");
	skl = ob->query("ability2");
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set("ability2/"+ sname[loop],skl[sname[loop]]);	
		text += HIW+sizeof(skl) + " 个ABILITY已复制到 " +ob1->name()+ NOR"\n\n";
	}
	
	ob1->set("Add_mana/ability", ob->query("Add_mana/ability"));
	ob1->set("Add_force/ability", ob->query("Add_force/ability"));
	ob1->set("Add_atman/ability", ob->query("Add_atman/ability"));
	
	return text;
}		
			

int mutant()
// 使gold robot的对象异变
{
	int rate;
	int seed = random(7)+1;
//	mapping buff;

	rate = query("mutant_rate");

	if (random(100) > rate)
		return 0;
	
	set("mutant",seed);

	if (query("mutant_name"))
		set("name",HIB+query("name")+NOR);
	
	switch (seed)
	{
	case 1:	// Extra Life
		set("max_kee",query("max_kee") * 20);
		set("eff_kee",query("max_kee"));
		set("kee",query("max_kee"));
		set("max_sen",query("max_sen") * 20);
		set("eff_sen",query("max_sen"));
		set("sen",query("max_sen"));
		set("max_gin",query("max_gin") * 20);
		set("eff_gin",query("max_gin"));
		set("gin",query("max_gin"));
		return 1;
		break;
	case 2:	// Immune to Physics Attack
		set("resistance/kee",100);
		return 1;
		break;
	case 3: // Super Shield
		set("resistance/sen",100);
		set("resistance/gin",100);
		set("max_mana",20000);
		set("mana",20000);
		set_temp("shield_force/type","mana");
		set_temp("shield_force/ratio",10000);
		set_temp("shield_force/msg",
			MAG"$N"MAG"招式甫及$n"MAG"身前三尺之外，便如泥牛入海，消失在紫气中。\n"NOR);
		return 1;
		break;
	case 4: // Immune to Busy
//		set_temp("no_busy",100);
		set("immune_busy",4);
		return 1;
		break;
	case 5: // Extra Strength
		set("str",query("str")*(150+random(100))/100);
		set("force_factor",query("force_factor")*(150+random(100))/100);
		return 1;
		break;
	case 6: // Extra Combat Exp
		set("combat_exp",query("combat_exp")/150*(100+random(100)));
		return 1;
		break;
	case 7: // Damage Shield
		set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",query("str") * query("str") * query("str") /100 * query("str") / 32);
		set_temp("damage_shield/msg",HIW"$n一触$N衣衫，忽然如遭电击。\n"NOR);
		return 1;
		break;
	}
	
	return 1;
}

void tell_team(object who,string what)
{
	object *team;
	int i; 
//	object ob,me=who;
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			tell_object(team[i],what);
		}
	}
	return ;
	
}

object team_check(object who,string what,int flag,mixed dat)
{
	object *team;
	int i; 
	object /*ob,*/me=who;

	// flag = 0: 只作用于同环境与可见team mate，含自身
	// flag = 1: 作用于所有teammate，含自身
	// flag = 2: 只作用于同环境与可见team mate，不含自身
	// flag = 3: 作用于所有team mate，不含自身
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			if (team[i] == me && flag >= 2) continue;
			if ( (flag == 0 || flag == 2) 
				&&	(environment(team[i]) != environment(me) || ( !me->visible(team[i])) )) 
				continue;

//			message_vision(team[i]->query(what)+"|||"+dat,team[i]);

			if (team[i]->query(what) == dat)
				return team[i];
		}
	}
	return 0;
}

mapping mapping_copy(mapping map)
{
	mapping dest = ([ ]);
    mixed *klist;

    if (sizeof(map))
        klist = keys(map);
	else
		return 0;
    
    if(!klist || !sizeof(klist))
        return 0;
    
	for(int loop=0; loop<sizeof(klist); loop++)
		dest[klist[loop]] = map[ klist[loop] ];

	return dest;
}

int get_highest_skill_level(object me,int i)
{
    int loop;
	int /*flag,*/lv=0;
	mapping skl,map;
	string *sname,*mapped;
	
	skl = me->query_skills();
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = me->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			if (skl[sname[loop]] > lv)
				lv = skl[sname[loop]];
	}
	return lv;
}

int block_account(object me)
{
//	object ob;
	tell_object(me,HIW"你的帐号数据异常，将被系统暂时禁止使用。\n请联系Silencer@Fengyun.com予以解决。\n"NOR);
	"/cmds/adm/block"->main(this_object(),me->query("id"));

	return 1;
}


int check_legitimate_state(object me)
{
	// 此函式只针对4.1在2003年10月时的design.

	if (wizardp(me) && me->query("env/debug"))
		return 1;
	
	// 1. Attributes
	if (me->query("str") >= 100)	// Unarmed 300+?
	{
		block_account(me);
		return 0;
	}

	if (me->query("int") > 100)	// Without Enhance(Removed in 4.1), int capped @ 30
	{
		block_account(me);
		return 0;
	}

	if (me->query("agi") > 100 || me->query("con") > 100 
		|| me->query("cps") > 100 || me->query("kar") > 100 )	// Limit dur,agi,con,cps,kar,fle,spi.
	{
		block_account(me);
		return 0;
	}

	if (me->query("force_factor") > 150)
	{
		block_account(me);
		return 0;
	}
	
	// 2. Combat Exp
	if (me->query("combat_exp") > 12000000)
	{
		block_account(me);
		return 0;
	}

	// 3. Skill level
	if (get_highest_skill_level(me,0) > 450)
	{
		block_account(me);
		return 0;
	}

	// 4. Max gin/kee/sen, Could player reach/over 40K in 4.1?
	if (me->query("max_gin") > 30000 
		|| me->query("max_kee") > 40000 
		|| me->query("max_sen") > 30000)
	{
		block_account(me);
		return 0;
	}

	return 1;
}