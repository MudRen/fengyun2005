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
	object ob, *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname,skill_name;
	int i, marry_flag;

	mapping learned_skill_points;
	int skill_level;

	seteuid(getuid());

//	==> implemented to reduce flooding when player only needs to check a single skill level -- by silencer
	if (arg)
	if (sscanf(arg,"-%s",skill_name)==1) {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("「" + skill_name + "」，有这种技能吗？\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
			return notify_fail("你并没有学过这项技能或是技能等级为零。\n");
		
		learned_skill_points=me->query_learned();
		write( "你目前学过：\n\n");		
		write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n\n", 
				(learned_skill_points[skill_name] >= (skill_level+1) * (skill_level+1)) ? HIM : "", 
				me->query_skill_mapped(skill_name) ? "  ": "＊",
				SKILL_D(skill_name)->name() + " (" + skill_name + ")",
				skill_level(SKILL_D(skill_name)->type(), skill_level),
				skill_level, 
				learned_skill_points[skill_name],
		));
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
/*	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public") )
		return notify_fail("只有管理或有师徒/夫妻关系的人能察看他人的技能。\n");*/

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
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
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
指令格式 : 

（1） skills 

查询自己所学过的技能。

（2） skills [<某人>] 

指定一个和你有师徒/夫妻关系的对象，可以查知对方的技能状况。

（3） skills -技能英文名称

在减号“-”后跟一技能的英文名称，将只列出该技能的等级状况。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
