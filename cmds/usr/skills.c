// skills.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 08/08/2001 by Daniel Q. Yu.
//			* Get name from skill itself.			
//
// 		- 9/22/2002 by Silencer
//			* Add -xxxx to enable single skill check.


#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_LEVEL;

string *skill_level_desc = ({
	BLU "初学乍练" NOR,
	HIB "粗通皮毛" NOR,
	HIB "半生不熟" NOR,
	HIB "马马虎虎" NOR,
	HIB "驾轻就熟" NOR,
	CYN "出类拔萃" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,
	HIC "登峰造极" NOR,
	HIC "一代宗师" NOR,
	HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,
	HIB "初窥门径" NOR,
	HIB "略知一二" NOR,
	HIB "马马虎虎" NOR,
	HIB "已有小成" NOR,
	CYN "心领神会" NOR,
	CYN "了然於胸" NOR,
	CYN "豁然贯通" NOR,
	HIC "举世无双" NOR,
	HIC "震古铄今" NOR,
	HIW "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob/*, *list*/, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target/*,cardname*/,skill_name/*, permit*/, msg;
	int i/*, marry_flag*/, skill_level;
	mapping learned_skill_points;
	int estimate,cost, amount, total, j, my_skill,req_exp;
	string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });
	mapping exp_data;
							
	seteuid(getuid());

//	==> implemented to reduce flooding when player only needs to check a single skill level -- by silencer
	if (arg)
	if (sscanf(arg,"-%s -%d",skill_name,estimate)==2 
		|| sscanf(arg,"-%s",skill_name)==1) {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("「" + skill_name + "」，有这种技能吗？\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
				skill_level = 0;
//			return notify_fail("你并没有学过这项技能或是技能等级为零。\n");
		
		learned_skill_points=me->query_learned();
		
//		return notify_fail("你没有学过任何技能，还不能察看技能的具体信息。先去学点什么吧。\n");
			
//		write( "你目前学过：\n\n");		
		write(HIG"────────────────────────────────\n"NOR);   
		
		if (mapp(learned_skill_points))
		{
			write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n\n", 
					(learned_skill_points[skill_name] >= (skill_level+1) * (skill_level+1)) ? HIM : "", 
					me->query_skill_mapped(skill_name) ? "  ": "＊",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")",
					skill_level(SKILL_D(skill_name)->type(), skill_level),
					skill_level, 
					learned_skill_points[skill_name],
			));
		} else
			write(sprintf("%s%s\n\n",
					me->query_skill_mapped(skill_name) ? "  ": "＊",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")")
					);
			
		msg = sprintf("\t【武功系数】%-6d【伤害等级】+%-6d【命中等级】+%-6d\n",
				SKILL_D(skill_name)->effective_level(me),
				SKILL_D(skill_name)->damage_level(me),
				SKILL_D(skill_name)->accuracy_level(me));
		msg += sprintf("\t【学习难度】%-6d【研究难度】+%-6d【练习级数】%-6d\n",
				SKILL_D(skill_name)->skill_difficulty(),
				SKILL_D(skill_name)->skill_difficulty_r(),
				SKILL_D(skill_name)->practice_limit());
		
		if (SKILL_D(skill_name)->eff_parry_level()!=SKILL_D(skill_name)->effective_level())
			msg += sprintf("\t【招架有效系数】%-6d\n",
				SKILL_D(skill_name)->eff_parry_level());
		if (SKILL_D(skill_name)->bounce_ratio())
			msg += sprintf("\t【金刚类有效系数】%-6d【金刚类反弹系数】%-6d\n",
				SKILL_D(skill_name)->ic_effect(),
				SKILL_D(skill_name)->bounce_ratio());
		write(WHT+msg + "\n"NOR);
		
		// Here a friendly estimation of pot cost
		
		if (mapp(learned_skill_points)){
			j = me->query_skill(skill_name,1);
			if (!estimate|| estimate<=j)	estimate = j+1;
			if (estimate>400)	estimate = 400;
		
			if (me->query_int()<=40)
				amount = (400+30*me->query_int())*2*100;
			else
				amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
						
	        if (me->query("national")=="苗族")	
	        	amount = amount + amount/20;	// 民族特性      	            	    	
	        amount = amount / SKILL_D(skill_name)->skill_difficulty();        	                 	
	       	if( amount < 1) amount = 1;		// 至少1：1 
	       	          
	        for (i=j;i<=estimate-1;i++){
	        	total = total + (i+1)*(i+1)+1;
	       	}
	       	total = total - learned_skill_points[skill_name];	
			cost = total*100/amount+1;
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill * 150/100;	
	    	req_exp = my_skill * my_skill * my_skill/10;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"【升至第%d级所需潜能】%-6d\t【所需经验等级】Ｌ%d （%d.%d％）\n" NOR,
						estimate,cost,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill;	
	    	req_exp = my_skill * my_skill * my_skill;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"【阅读有关书籍升至第%d级所需经验等级】Ｌ%d （%d.%d％）\n\n" NOR,
							estimate,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
		}
			
		if (me->query_temp("timer/check_skill_help")+2 < time())
			SKILL_D(skill_name)->help(me);
		me->set_temp("timer/check_skill_help",time());
		
		write(HIG"────────────────────────────────\n"NOR);   
		return 1;
	}
	
//	==> single skill check ends.	
	
	
	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的技能？\n");
	}
	
	target = (string) me->query("marry");	
	if(stringp(target)) couple_ob = find_player(target);
	
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
		&& !me->is_apprentice_of(ob) && ob!=couple_ob
		&& !ob->query("skill_public") )
//		&& !ob->query("skill_restrict"))
		return notify_fail("只有管理或有师徒/夫妻关系的人能察看他人的技能。\n");

/*	if (stringp(permit = ob->query("skill_restrict"))) {
		if (member_array(permit, me->query("marks/ok_skill")) == -1)
			return notify_fail("只有管理或有师徒/夫妻关系的人能察看他人的技能。\n");	
	}*/

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前共学过"+chinese_number(sizeof(skl))+"种技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		if(!find_object(SKILL_D(sname[i])) && file_size(SKILL_D(sname[i])+".c")<0) 
		{
			ob->delete_skill(sname[i]);
			write("delete obselete skill " + sname[i] + "\n");
			continue;
		}
		if (ob->prevent_shown(me,sname[i]))	continue;
		write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "", 
				(member_array(sname[i], mapped)==-1? "  ": "＊"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], 
				(int)lrn[sname[i]],
		));
	}
	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

string pet_skill(object ob)
{
	string desc;
//      object  *list,couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped/*,target,cardname*/;
        int i/*, marry_flag*/;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "目前并没有学会任何技能。\n";
                return desc;
        }
        	desc =  ob->name() +"目前所学过的技能：\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "＊"),
                        SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m   
[0;1;36m指令格式 :[0;32m 

（1） skills 

查询自己所学过的技能。

（2） skills [<某人>] 

指定一个和你有师徒/夫妻关系的对象，可以查知对方的技能状况。

（3） skills -技能英文名称

在减号“-”后跟一技能的英文名称，将只列出该技能的等级状况。

（4） skills -技能英文名称 -数字

给出一个升至第“数字”等级所需要的潜能数估算。

为了避免刷屏，技能所对应的特技信息每２秒钟最多显示一次

[0;1;37m────────────────────────────────[0m   

关于各项的说明

【升至第x级所需潜能】
【所需经验等级】
【阅读有关书籍升至第x级所需经验等级】

为了方便大家，我们根据你的属性状况，给出一个升到下一级所需
潜能数量的大致估计。对此作一些说明：

ａ．风云２００５中学习所耗费的潜能数没有随机摆动，这个数字
是比较准确的估计，由于你花费的潜能不同，在四舍五入时会有一
定差异，此估计是按照每次使用１００潜能点的公式计算的。
（具体参见ｈｅｌｐ　ｌｅａｒｎ的说明）

ｂ．此估算是按照你当前才智、民族、以及当前技能等级所对应的
学习难度所计算的，如果你的才智、或者该技能的学习难度以后变
动了，则此数字也将变动。

ｃ．读书识字（literate）牵涉到才智的提高，所以其实际所需的
比显示的要少很多。
[1;31m
ｄ．所有耗费的潜能点只在当前等级有效，即使系统显示需要20000
点升至第１００级，如果你现在只有２０级，一次用去20000点也只
能升到第２１级，而不会直接升到第１００级。慎之！！！
[0;32m

【武功系数】技能主要参数，决定该武功在某一经验段可以学到的
最高等级。武功系数和武功等级是决定武功的命中率的两大主要因素。

【伤害等级】修饰武功的伤害率，伤害力一般取决于你的力量、加力
（enforce）、武器、相对经验等级等，【伤害等级】对前两个因素
加成。100相当于来源于力量和加力的伤害力增大10％。

【命中等级】类似于上一项，对武功命中率的加成，两个其他完全
相同的技能，命中等级２００的比命中等级０的命中率高２０％

【学习难度】参看命令ｌｅａｒｎ的公式说明

【研究难度】一般来说，研究（ｒｅｓｅａｒｃｈ）所需潜能数为普
通学习所需的２０倍，研究难度是在此基础上的加权。

【练习级数】该技能能够练习（ｐｒａｃｔｉｃｅ）到的最高等级。

【招架有效系数】一般来说，【武功系数】便是技能的招架系数，唯
有一些特定的武功会有专门的招架系数。

【金刚类有效系数】对铁布衫类武功作用于护甲的修饰，系数越高，
护甲作用就越明显。

【金刚类反弹系数】用来计算铁布衫类武功的反弹伤害力。


[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}