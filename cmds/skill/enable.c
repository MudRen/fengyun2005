// enable.c
//	07/20/2003-- added all kinds of temp parameters
//			-- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//		"array":        "阵法",
		"animal-training":  "训兽术",
		"axe":     	"斧法",
		"blade":        "刀法",
		"dagger":       "短兵刃",
		"dodge":        "闪躲术",
		"force":        "内功",
		"fork":         "叉法",
		"hammer":       "锤法",
		"iron-cloth": 	"硬功",
		"literate": 	"读写",
		"magic":        "法术",
		"move":         "轻功",
		"parry":        "招架",
	//	"perception":   "听风术",
		"scratching":   "符之术",
		"cursism" :	"降头术",
		"spells":       "咒文",
		"staff":        "杖法",
		"stealing":     "妙手术",
		"sword":        "剑法",
		"throwing":     "暗器",
		"unarmed":      "拳脚",
		"whip":     	"鞭法",
		"herb":		"药道",
		"spear":        "枪法",
		"musket":				"火枪",

		"theorem":        "无有之术",

]);

int main(object me, string arg) {
	mapping skill_map;
	string /**types,*/ *skill_o, *skill, *usr_skill, ski, map_to;
	int i, j, modify, skill_level;
	string s, skill_name,enable_skill, attack_skill;
	object weapon;
	
	seteuid(getuid());
	
	if(!arg) {
		skill_map = me->query_skill_map();
		if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
			return notify_fail("你现在没有使用任何特殊技能。\n");
		}
		skill_o = keys(valid_types);
		skill  = sort_array( skill_o, (: strcmp :) );
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
		}
				
		write("以下是你目前使用中的特殊技能。\n");
		write("——————————————————————————————————\n");
		for(i=0; i<sizeof(skill); i++) {
			if(undefinedp(valid_types[skill[i]])) {
			    	map_delete(skill_map, skill[i]);
			    	continue;
			}
			if(!me->query_skill(skill[i])) {
				continue;
			}
			modify = me->query_skill_modifier(skill[i]);
			if (skill[i] == attack_skill)
				modify += me->query_temp("apply/attack");
			
			printf("  %-24s： %-15s  有效等级：%3d%5s\n" NOR, 
		    		valid_types[skill[i]] + " (" + skill[i] + ")",
		    		undefinedp(skill_map[skill[i]]) ? "无" : 
					SKILL_D(skill_map[skill[i]])->name(),
				me->query_skill(skill[i]),
		    		modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		}
		write("\n有效等级 = 基本技能/2 + 特殊技能*武功系数\n");
		write("亮绿色或红色的数字表示来自于武器、Perform、或Advanced-skill的修正值。\n\n");
		write("——————————————————————————————————\n");
		return 1;
	}
	
	if(arg=="?") {
		write("以下是可以使用特殊技能的种类和你会的特殊技能：\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		if (me->query_skills())
			usr_skill = keys(me->query_skills());
		for(i=0; i<sizeof(skill); i++) {
			s = sprintf("%6s (%s)", valid_types[skill[i]], skill[i]);
			if (me->query_skills())
				usr_skill = filter_array(keys(me->query_skills()), (: SKILL_D($1)->valid_enable($2) :), skill[i]);
			if(sizeof(usr_skill)) {
				for(j=0; j<sizeof(usr_skill); j++) {
					printf("  %-20s : %s (%s)\n", s, SKILL_D(usr_skill[j])->name(), usr_skill[j]);
					s = " ";
				}  
			} else {
				printf("  %-20s\n", s);	
			}
		}
		return 1;
	}

	if (arg)
	if (sscanf(arg, "%s %s", ski, map_to)!=2)
	if (sscanf(arg,"%s",skill_name)==1 && skill_name!="none") {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("「" + skill_name + "」，有这种技能吗？\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
			return notify_fail("你并没有学过这项技能或是技能等级为零。\n");
		
		if(undefinedp(valid_types[skill_name])) 
			return notify_fail("此项技能不是基本技能种类，用 enable ? 可以查看有哪些种类。\n");
		enable_skill=me->query_skill_mapped(skill_name);
					
		write("以下是你查询的特殊技能状况。\n\n");
		modify = me->query_skill_modifier(skill_name);
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
			if ( skill_name == attack_skill)
				modify += me->query_temp("apply/attack");
		}
		
		printf("  %-24s： %-15s  有效等级：%3d%5s\n\n" NOR, 
		    		valid_types[skill_name] + " (" + skill_name + ")",
		    		(!me->query_skill_mapped(skill_name)) ? "无" : 
					SKILL_D(enable_skill)->name(),
				me->query_skill(skill_name),
				modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		return 1;
	}

	
	if(sscanf(arg, "%s %s", ski, map_to)!=2) {
		return notify_fail("指令格式：enable <技能种类> <技能名称>|none\n");
	}
	
	if(undefinedp(valid_types[ski])) {
		return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");
	}
	
	if(map_to=="none") {
		me->map_skill(ski);
		me->reset_action();
		write("停止使用「" + valid_types[ski] + "」的特殊技能。\n");
		return 1;
	} else if(map_to==ski) {
		write("「" + SKILL_D(ski)->name() + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
		return 1;
	}
	
	if(!find_object(SKILL_D(map_to)) && !load_object(SKILL_D(map_to))) {
		return notify_fail("「" + map_to + "」，有这种技能吗？\n");	
	}

	if(!me->query_skill(map_to, 1)) {
		return notify_fail("你不会特殊技能「" + SKILL_D(map_to)->name() + "」。\n");
	}

	if(!me->query_skill(ski, 1)) {
		return notify_fail("你连「" + SKILL_D(ski)->name() + "」都没学会，如何使用特殊技能「" + SKILL_D(map_to)->name() + "」？\n");
	}
/*	if (map_to == "tanzhi-shentong" && ski=="parry" && !me->query("fy41/hs_tz_parry") ) {
		return notify_fail("你现在还未曾领悟把弹指神通运用在招架上的口诀。\n");
	}*/
	if(!SKILL_D(map_to)->valid_enable(ski)) {
		return notify_fail("特殊技能「" + SKILL_D(map_to)->name() + "」不能用在「" + valid_types[ski] + "」上。\n");
	}
		
	if(ski=="dodge" && ANNIE_D->check_buff(me,"dodgeup"))
		return notify_fail("你正在使用闪躲术的特殊技能，必须等其效果消失后才能转换此武功。\n");
	
	if(ski=="parry" && ANNIE_D->check_buff(me,"parryup"))
		return notify_fail("你正在使用招架的特殊技能，必须等其效果消失后才能转换此武功。\n");
	
	if(ski=="iron-cloth" && ANNIE_D->check_buff(me,"ironup"))
		return notify_fail("你正在使用硬功的特殊技能，必须等其效果消失后才能转换此武功。\n");
	
	if(ski=="force" && (ANNIE_D->check_buff(me,"gks") || ANNIE_D->check_buff(me,"powerup")))
		return notify_fail("你正在使用内功的特殊技能，必须等其效果消失后才能转换此武功。\n");

	if (ski == "theorem")
	{
		if(me->query("timer/last_theorem") + 1800 > time())
			return notify_fail(CYN"无有之术每三十分钟只能切换一次。\n"NOR);
		me->set("timer/last_theorem",time());
	}
		
	me->map_skill(ski, map_to);
	me->reset_action();
	write("开始使用「" + valid_types[ski] + "」的特殊技能「" + SKILL_D(map_to)->name() + "」。\n");
	
	if( ski=="magic" ) {
		write("你改用另一种魔法系，灵力必须重新锻炼。\n");
		me->set("atman", 0);
		me->force_status_msg("atman");
	} else if( ski=="force" ) {
		write("你改用另一种内功，内力必须重新锻炼。\n");
		me->set("force_factor",0);
		me->set("force", 0);
		me->force_status_msg("force");
	} else if( ski=="spells" ) {
		write("你改用另一种咒文系，法力必须重新修炼。\n");
		me->set("mana", 0);
		me->force_status_msg("mana");
	}
	
	return 1;
}



int help(object me) {
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	enable
		enable ?
		enable <技能种类>
		enable <技能种类> <技能名称> | none[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你指定所要用的技能，需指明技能种类和技能名称。
如果不加参数则会显示出技能种类及你目前所使用的技能名称 ，
如果加一个 ? 会列出所有能使用特殊技能的技能种类，
如果直接跟技能种类会列出目前该技能的ｅｎａｂｌｅ状态。
 
[0;1;37m────────────────────────────────[0m   
 
HELP
        );
        return 1;
}
 