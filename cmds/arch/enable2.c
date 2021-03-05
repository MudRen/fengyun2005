// enable.c
//      07/20/2003-- added all kinds of temp parameters
//                      -- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//              "array":        "阵法",
                "animal-training":  "训兽术",
                "axe":          "斧法",
                "blade":        "刀法",
                "dagger":       "短兵刃",
                "dodge":        "闪躲术",
                "force":        "内功",
                "fork":         "叉法",
                "hammer":       "锤法",
                "iron-cloth":   "硬功",
                "literate":     "读写",
                "magic":        "法术",
                "move":         "轻功",
                "parry":        "招架",
        //      "perception":   "听风术",
                "scratching":   "符之术",
                "cursism" :     "降头术",
                "spells":       "咒文",
                "staff":        "杖法",
                "stealing":     "妙手术",
                "sword":        "剑法",
                "throwing":     "暗器",
                "unarmed":      "拳脚",
                "whip":         "鞭法",
                "herb":         "药道",
                "spear":        "枪法",
                "musket":				"火枪",
]);

int main(object me, string arg) {
        mapping skill_map;
        string *types, *skill_o, *skill, *usr_skill, ski, map_to;
        int i, j, modify, skill_level;
        string s, skill_name,enable_skill, attack_skill;
        object weapon;
        object who;
        
        if (!arg)
			return notify_fail("格式：enable 姓名\n");

        seteuid(getuid());
        who = find_player(arg);
        if (!who)
        	who = find_living(arg);
        if (!who)
            return notify_fail("找不到耶……\n");
        
                skill_map = who->query_skill_map();
                if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
                        return notify_fail("你现在没有使用任何特殊技能。\n");
                }
                skill_o = keys(valid_types);
                skill  = sort_array( skill_o, (: strcmp :) );
                
                if (who->query_temp("apply/attack")) {
                        if (weapon = who->query_temp("weapon")) 
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
                        if(!who->query_skill(skill[i])) {
                                continue;
                        }
                        modify = who->query_skill_modifier(skill[i]);
                        if (skill[i] == attack_skill)
                                modify += who->query_temp("apply/attack");
                        
                        printf("  %-24s： %-15s  有效等级：%3d%5s\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(skill_map[skill[i]]) ? "无" : 
                                        SKILL_D(skill_map[skill[i]])->name(),
                                who->query_skill(skill[i]),
                                modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
                        );
                }
                write("\n有效等级 = 基本技能/2 + 特殊技能*武功系数\n");
                write("亮绿色或红色的数字表示来自于武器、Perform、或Advanced-skill的修正值。\n\n");
                write("——————————————————————————————————\n");
                return 1;
        
        
        return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	enable2 人名[0m
[0;1;37m────────────────────────────────[0m   
 
此命令让你检查NPC的Enable情况，以利于测试。

[0;1;37m────────────────────────────────[0m 
HELP	);
	return 1;
}