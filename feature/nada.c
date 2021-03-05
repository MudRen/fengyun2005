// 通用函式存放此处。
// 此档案不被任何ＮＰＣ继承，与ＤＡＥＭＯＮ相似然又独立於外。


#include <ansi.h>
#include <dbase.h>
#include <login.h>;
#include <combat.h>

inherit F_LEVEL;
#define SNAPHP "/log/snapshot_hp"
#define SNAP_I "/log/snapshot_i"
#define SNAP_SCORE "/log/snapshot_score"
#define SNAP_SKILLS "/log/snapshot_skills"
#define SNAP_RIDDLES "/log/snapshot_riddles"

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



string *output = ({
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B",
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"
});


string *c_num= ({
"      ;'       B"+
" , ''';;'''' , B"+
",;';;';;';;';;'B"+
";' ,, ;; ,, ;' B"+
"    ,;',';,,   B"+
",,'',,,;;,,;';'B"+
"         ;'    B"+
"     ',,;'     B"+
"       ';'     B"+
"               B",
"               B"+
"               B"+
"               B"+
"               B"+
"               B"+
",,,,,,,,,,,;,  B"+
"               B"+
"               B"+
"               B"+
"               B",
"               B"+
"               B"+
"               B"+
"  ,,,,,,,,,;,  B"+
"               B"+
"             , B"+
"'''''''''''''''B"+
"               B"+
"               B"+
"               B",
"           ,   B"+
"  '''''''''''  B"+
"               B"+
"  ,,,,,,,,,;,  B"+
"               B"+
"             , B"+
"'''''''''''''''B"+
"               B"+
"               B"+
"               B",
",            , B"+
";;'';;'';;'';;'B"+
";;  ;;  ;;  ;; B"+
";;  ;;  ;;  ;; B"+
";; ;;   ;;,,;; B"+
";;,'     ''';; B"+
";;'''''''''';; B"+
"'           '  B"+
"               B"+
"               B",
" ,,,,,,,,,,,;, B"+
"     ;;        B"+
"     ;;   ,    B"+
" '''';;'';;'   B"+
"     ;;  ;;    B"+
"    ;;   ;;    B"+
"    ;;   ;;  , B"+
"'''''''''''''''B"+
"               B"+
"               B",
"     ',,       B"+
"      ';;      B"+
",,,,,,,;,,,,,;,B"+
"     ,  ,      B"+
"    ;;'  ;,    B"+
"   ,;'    ;,   B"+
"  ,;'      ;;  B"+
" ,'         ;' B"+
"               B"+
"               B",
"      ,        B"+
"      ;;       B"+
"      ;;     , B"+
"    ,,;;,,'''''B"+
"''''  ;;       B"+
"      ;;     , B"+
"      ;;,,,,,;,B"+
"       ''''''' B"+
"               B"+
"               B",
"    ,   ;,     B"+
"    ;;  ;;     B"+
"    ;;  ;;     B"+
"    ;;  ;;     B"+
"   ,;'   ;;    B"+
"  ,;'    ';,   B"+
" ,;'      ';;, B"+
",'          ';'B"+
"               B"+
"               B",
"     ;,        B"+
"     ;;   ,    B"+
" '''';;'';;'   B"+
"     ;;  ;;    B"+
"    ,;'  ;;    B"+
"   ,;'   ;;    B"+
"  ,;'    ;;  ; B"+
",''      ';;;;'B"+
"               B"+
"               B",
"      ;,       B"+
"      ;;       B"+
"      ;;       B"+
"'''''';;'''''' B"+
"      ;;       B"+
"      ;;       B"+
"      ;;       B"+
"      ;'       B"+
"               B"+
"               B"
});

string addcolor(string outstring)
{
        switch(random(10)) {
        case 0: outstring += RED; break;
        case 1: outstring += HIR; break;
        case 2: outstring += GRN; break;
        case 3: outstring += HIG; break;
        case 4: outstring += YEL; break;
        case 5: outstring += HIY; break;
        case 6: outstring += BLU; break;
        case 7: outstring += HIB; break;
        case 8: outstring += HIM; break;
        case 9: outstring += HIC; break;
        }

	return outstring;
}




void reset_player_status(object ob)
{
	mapping my;
	int combat_exp/*, bonus, npc_str, npc_att*/;
//	int n,npc_force,npc_f_factor,temp_damage;
	int *extra_d, num/*,tough*/;
	mapping extra = ([]);
			
	my = ob->query_entire_dbase();
	combat_exp = my["combat_exp"];
	my["level"] = F_LEVEL->get_level(combat_exp);

		my["max_force"] = ob->query_skill("force",1) * 5 + ob->query_skill("force");
		my["max_atman"]=ob->query_skill("magic",1) * 5 + ob->query_skill("magic");
		my["max_mana"]=ob->query_skill("spells",1) * 5 + ob->query_skill("spells");
		
		if ( extra = ob->query("Add_force")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_force"] += extra_d[num];
			}	
		}
		if ( extra = ob->query("Add_atman")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_atman"] += extra_d[num];
			}
		}
		if ( extra = ob->query("Add_mana")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_mana"] += extra_d[num];
			}
		}


		
	if(userp(ob) || undefinedp(my["max_gin"])) {
		my["max_gin"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_atman"] > 0) {
			my["max_gin"] += my["max_atman"] * 2 ;
		} else
			my["max_atman"] = 0;
	
		if (my["class"]!= "moon" || !userp(ob))
			my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /600;
			
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",0) * 100;
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",3) * 100;
		
		if ( extra = ob->query("Add_gin")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_gin"] += extra_d[num];
			}
		}
		
	}
	
	if(userp(ob) || undefinedp(my["max_sen"])) {
		my["max_sen"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_mana"] > 0) {
			my["max_sen"] += my["max_mana"] * 2 ;
		} else
			my["max_mana"] = 0;
	
		if (my["class"]!= "moon" || !userp(ob))
			my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /600;
			
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",0) * 100;
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",3) * 100;
		
		if ( extra = ob->query("Add_sen")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_sen"] += extra_d[num];
			}
		}
		
	}
	
	if(userp(ob) || undefinedp(my["max_kee"])) {
		
		my["max_kee"] = my["con"]*my["con"] + my["str"] * my["str"]/4;
		
		if(my["max_force"] > 0) {
			my["max_kee"] += my["max_force"] * 2;
		} else
			my["max_force"] = 0;
		
		if (my["class"]!= "moon" || !userp(ob))
			my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /600;
		
		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",0) * 100;
		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",3) * 100;
		
		if ( extra = ob->query("Add_kee")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_kee"] += extra_d[num];
			}
		}
				
	}
	
		// 只加 force/atman/mana
		if (userp(ob)) {
			if ( extra = ob->query("Add_force_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_force"] += extra_d[num];
				}	
			}
			if ( extra = ob->query("Add_atman_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_atman"] += extra_d[num];
				}
			}
			if ( extra = ob->query("Add_mana_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_mana"] += extra_d[num];
				}
			}
	}
	
	ob->set_weight(40000 + (my["str"] - 10)* 200);
	ob->set_max_encumbrance( my["str"] * 20000 );
}


mixed my_number()
{
 string outstring;
 int out;
 int orinum;
 int num = random(100000000);
 mixed alle;
 string *out8,*out7,*out6,*out5,*out4,*out3,*out2,*out1;
	orinum = num;
	switch(random(10)) {
	case 0: outstring = RED"\n"; break;
        case 1: outstring = HIR"\n"; break;
        case 2: outstring = GRN"\n"; break;
        case 3: outstring = HIG"\n"; break;
        case 4: outstring = YEL"\n"; break;
        case 5: outstring = HIY"\n"; break;
        case 6: outstring = BLU"\n"; break;
        case 7: outstring = HIB"\n"; break;
        case 8: outstring = HIM"\n"; break;
        case 9: outstring = HIC"\n"; break;
	}
	if(num>99999999) num =99999999;
	if(num >= 10000000) 
	{
	out = num/10000000;
	out8 = explode(c_num[out],"B");
	num = num%10000000;
	}
	else
	if(orinum > num)	
	out8 = explode(c_num[0],"B");
	else
	out8 = explode(output[0],"B");

        if(num >= 1000000) 
        {
        out = num/1000000;
        out7 = explode(c_num[out],"B");
        num = num%1000000;
        }
        else
        if(orinum > num)
        out7 = explode(c_num[0],"B");
        else
        out7 = explode(output[0],"B");


        if(num >= 100000) 
        {
        out = num/100000;
        out6= explode(c_num[out],"B");
        num = num%100000;
        }
        else
        if(orinum > num)
        out6 = explode(c_num[0],"B");
        else
        out6 = explode(output[0],"B");

        if(num >= 10000) 
        {
        out = num/10000;
        out5 = explode(c_num[out],"B");
        num = num%10000;
        }
        else
        if(orinum > num)
        out5 = explode(c_num[0],"B");
        else
        out5 = explode(output[0],"B");


        if(num >= 1000) 
        {
        out = num/1000;
        out4 = explode(c_num[out],"B");
        num = num%1000;
        }
        else
        if(orinum > num)
        out4 = explode(c_num[0],"B");
        else
        out4 = explode(output[0],"B");

        if(num >= 100) 
        {
        out = num/100;
        out3 = explode(c_num[out],"B");
        num = num%100;
        }
        else
        if(orinum > num)
        out3 = explode(c_num[0],"B");
        else
        out3 = explode(output[0],"B");


        if(num >= 10) 
        {
        out = num/10;
        out2 = explode(c_num[out],"B");
        num = num%10;
        }
        else
        if(orinum > num)
        out2 = explode(c_num[0],"B");
        else
        out2 = explode(output[0],"B");

        out1 = explode(c_num[num],"B");

	for(out=0;out<sizeof(out8);out++)
		outstring += addcolor(out8[out])+"  "+addcolor(out7[out])+"  "+
				addcolor(out6[out])+"  "+addcolor(out5[out])+"\n";
	outstring += "\n";
        for(out=0;out<sizeof(out4);out++)
                outstring += addcolor(out4[out])+"  "+addcolor(out3[out])+"  "+
			addcolor(out2[out])+"  "+addcolor(out1[out])+"\n";

	alle = ({ outstring + NOR, orinum });
				

return alle;


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

// 	Eventually.. this should be directly quoted from COMBAT_D.
int basic_damage(object attacker)
{
	int str, damage/*, force_factor, bounce, att_combat_exp, weapon_damage*/;
	int /*d0,*/d1,d2,d3,d3x/*,d4,d5,d6*/,d7,d_race, d_1/*, d_2*/, d_3;		// Debug message.
	string /*force_skill,*/ attack_skill, martial_skill;
	object attweapon;
//	mixed tmp;
	function f;

	attweapon = attacker->query_temp("weapon");
	
	// Strength damage bonus. --- this is the combined effect of str + enforce.
	// if use weapon, effectiveness only 4/5
	str = attacker->query_str();
	if (str<= 90)
		d1 = str*str/10;
	else
		d1 = 810 + (str-90)* 9;
	
	d1 = d1 *3/4;	// Weapon or not..damage all reduced by 1/4
		
	// Let race factor take effect. 
	d_race = d1 /10;
		if (attacker->query("national")=="蒙古族")	d1 += d_race;
		if (attacker->query("national")=="满族")	d1 -= d_race;
				
	// Weapon damage consists of weapon_prop/damage + apply_temp/damage.
	d2 = attacker->query_temp("apply/damage") + 2;	
		
	// skill damage -- this is defined in individual skill.
	if(objectp(attweapon)) {
		attack_skill = attweapon->query("skill_type");
	} else {
		attack_skill = "unarmed";
	}
	if(stringp(martial_skill = attacker->query_skill_mapped(attack_skill) )) {
		d3 = SKILL_D(martial_skill)->damage_level(attacker);
		d3 = d3 * (d1 + d2) / 1000;	
	}
	
		// Quest_buff
	if (ANNIE_D->check_buff(attacker,"quest_dmg")) {
		d3x = (d1+d2) * attacker->query_temp("apply/quest_dmg")/100;
	}
		
	// Let combat exp take effect
	d7 = attacker->query("level");

	// Add damage bonus.
	d_1 = d1 + d2 + d3 + d3x + d7;

	if (ANNIE_D->check_buff(attacker,"damagecurse") < 1)
	{
		d_3 = d_1 *3/4;		// normally average = 75% 
	}
	else
	{
		if ((attacker->query_temp("buff/"+ANNIE_D->check_buff(attacker,"damagecurse")))["att"] == "curse")
		{
			d_3 = d_1/2;	// curse type curse, 50%,-25%
		}
		else			
		{
			d_3 = d_1; 	// blessing type damage curse, 100%,+25%
		}
	}
	
	if (ANNIE_D->check_buff(attacker,"weaken") >= 1)
		d_3-=d_3*attacker->query_temp("buffup/weakened")/100;
		
	damage = d_3;
	
	if(damage < 0) damage = 0;
	
	return damage;
}

int basic_armor(object victim){
	
	int /*armor,*/ eff_ness, absorb_vic;
	string absorb_skill;
	
	if(victim->query_skill("iron-cloth")) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if (absorb_skill) {
			if (!(eff_ness = SKILL_D(absorb_skill)->ic_effect()))
				eff_ness = 100;	
			absorb_vic = victim->query_skill("iron-cloth",1) /2
					+ victim->query_skill(absorb_skill) * eff_ness/200
					+ victim->query_temp("apply/iron-cloth");
		}else
		{
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1) /2
							+ victim->query_temp("apply/iron-cloth");
		}
	} else
			absorb_vic = victim->query_temp("apply/iron-cloth");
	
	return absorb_vic;
}

string status_color(int a, int b)
{
	return "";
}

string display_attr(int gift, int value)
{
return sprintf("%3d /%3d", value,gift);
}


string ngstr(string str)
{
//      int i,i2;
        string strc;
        strc=str;
        // filter color-code
		// annie 10.7.2004
        str=replace_string(str,CSI,"");
        
        str=replace_string(str,"2;37;0m","");

        str=replace_string(str,"41;","");
        str=replace_string(str,"42;","");
        str=replace_string(str,"43;","");
        str=replace_string(str,"44;","");
        str=replace_string(str,"45;","");
        str=replace_string(str,"46;","");
        str=replace_string(str,"47;","");
        str=replace_string(str,"1;","");
        str=replace_string(str,"30m","");
        str=replace_string(str,"31m","");
        str=replace_string(str,"32m","");
        str=replace_string(str,"33m","");
        str=replace_string(str,"34m","");
        str=replace_string(str,"35m","");
        str=replace_string(str,"36m","");
        str=replace_string(str,"37m","");
        str=replace_string(str,"38m","");
        str=replace_string(str,"40m","");
        str=replace_string(str,"41m","");
        str=replace_string(str,"42m","");
        str=replace_string(str,"43m","");
        str=replace_string(str,"44m","");
        str=replace_string(str,"45m","");
        str=replace_string(str,"46m","");
        str=replace_string(str,"47m","");
        str=replace_string(str,"1m","");

		strc=str;

        return strc;
}


string inventory_desc(object obj) {
	return sprintf("  %s%s", obj->query("equipped")? HIC "√" NOR: "  ",
			obj->short());
}

void snapshot(object ob)
{
		// HP; I; SCORE; SKILLS; BALANCE; POTS USED

		string str,msg,line,*list,*mapped;
		mapping my,riddle,map;
		mapping exp_data;
		int uin,i/*,n*/;
		object /**obj,*/*inv;
		string  skill_type, parry_type, dodge_type, wptype;
		object weapon;
		int attack_points, dodge_points, parry_points, magic_points;

		uin=random(1000000);
		
		seteuid(getuid());
    	my = ob->query_entire_dbase();

		str = "==============================================================="+"\n\n";
		str += " "+ob->query("name")+"("+ob->query("id")+")"+" 于 "+ctime(time())+"    INDEX:"+uin+"\n\n";

		str+=sprintf(" 【精力】%s%5d/ %5d %s(%3d%%)    【食物】%s%3d%%\n" ,
	           	"",my["gin"],	my["eff_gin"],
	           "",my["eff_gin"] * 100 / my["max_gin"],
	           "",
	           my["food"] * 100/ob->max_food_capacity()	
	        );

		str+=sprintf(" 【气血】%s%5d/ %5d %s(%3d%%)" NOR "    【饮水】%s%3d%%\n" NOR,
	           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
	           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
	           status_color(my["water"], ob->max_water_capacity()),
	           my["water"] * 100/ob->max_water_capacity()
	        );

		str+=sprintf(" 【心神】%s%5d/ %5d %s(%3d%%)" HIW "    【评价】 %d\n" NOR,
	           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
	           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
	           my["score"]
	        );
		str+=sprintf(" 【灵力】%s%5d/ %5d (%4d)" HIR "    【杀气】 %d\n" NOR,
	           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
	           my["atman_factor"],
	           my["bellicosity"]
	        );

		str+=sprintf(" 【内力】%s%5d/ %5d (%4d)"  HIG "    【潜能】 %d\n" NOR,
	           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
	           my["force_factor"],
	           (my["potential"] - my["learned_points"])
	        );
	
		exp_data = exp_to_level(my["combat_exp"]); 
		str+=sprintf(" 【法力】%s%5d/ %5d (%4d)"HIM "    【等级】 Ｌ%d （%d.%d％）\n" NOR,
		           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		           my["mana_factor"],
				exp_data["level"],
		    		exp_data["sub"]/10,
		    		exp_data["sub"]%10,
		    	);

		str=ngstr(str);

		str += "\n===============================================================";

		write_file(SNAPHP,str+"\n\n\n",0);

		str = "==============================================================="+"\n\n";
		str += " "+ob->query("name")+"("+ob->query("id")+")"+" 于 "+ctime(time())+"    INDEX:"+uin+"\n\n";


		inv = all_inventory(ob);

		msg = "%s身上带著下列这些东西(负重 %d%%, 携带量 %d/26 )：";
		msg += "\n%s\n";

		str+=sprintf(msg,
		ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		sizeof(inv),
		implode(map_array(inv, "inventory_desc", this_object()), "\n") );

		str += "\n"+ob->query("name")+"共有存款"+MONEY_D->money_str(ob->query("deposit"))+"。\n";

		str=ngstr(str);

		str += "\n===============================================================";

		write_file(SNAP_I,str+"\n\n\n",0);

		str = "==============================================================="+"\n\n";
		str += " "+ob->query("name")+"("+ob->query("id")+")"+" 于 "+ctime(time())+"    INDEX:"+uin+"\n\n";



		line =  sprintf(" 【力量】%-8s\t【民族】%-10s【杀死人数】 %-12d \n",
	           display_attr(my["str"], ob->query_str()),(ob->query("national")? ob->query("national") : "无"),my["MKS"]
	        );
	line += sprintf(" 【速度】%-8s\t【性别】%-10s【杀死玩家】 %-12d \n",
	           display_attr(my["agi"], ob->query_agi()),ob->query("gender"),my["PKS"]
	        );
	line += sprintf(" 【体质】%-8s\t【年龄】%-10s【被杀次数】 %-12d \n",
	           display_attr(my["con"], ob->query_con()),chinese_number(ob->query("age")),my["KILLED"]
	        );
	line += sprintf(" 【才智】%-8s\t【门派】%-10s【杀死天骄】 %-12d \n",
	           display_attr(my["int"], ob->query_int()),
	           (my["family"]?(my["family"]["family_name"]? my["family"]["family_name"]:"无"):"无")
	           + (my["betrayer"]? sprintf("*%d",my["betrayer"]):""),
	           sizeof(my["m_killer"])
	        );
	line += sprintf(" 【定力】%-8s\t【师父】%-10s【ＴＡＳＫ】 %-12d \n",
	           display_attr(my["cps"], ob->query_cps()),
	           (my["family"]?(my["family"]["master_name"]? my["family"]["master_name"]:"无"):"无"),
	           my["TASK"]
	        );
	if ( !my["marry"]) 
	{
		line += sprintf(" 【运气】%-8s\t【婚姻】%-10s【ＱＳＴ。】 %-12d \n",
	           display_attr(my["kar"], ob->query_kar()),
	           (my["divorced"]?(ob->query("gender") == "女性" ? "寡居":"鳏居"):"未婚")
	           	+ (my["divorced"]? sprintf("*%d",my["divorced"]):""),
	            my["FINISH_QUEST"]
	        );
	} else
	{
		line += sprintf(" 【运气】%-8s\t【%s】%-10s【ＱＳＴ。】 %-12d \n",
	           display_attr(my["kar"], ob->query_kar()),
	           (ob->query("gender") == "女性" ? "丈夫":"妻子"),
	            my["marry_name"],
	            my["FINISH_QUEST"]		
	        );
	}
		
	/*
	                
        line += sprintf("\n 自造物品： " HIR "%d\t\t" NOR, ob->query("created_item") );
        line += sprintf("自造房间： " HIR "%d\n" NOR, ob->query("created_room") );*/
	
	wptype = objectp(weapon = ob->query_temp("weapon"))?
			weapon->query("skill_type"): "unarmed";
	skill_type = ob->query_skill_mapped(wptype);
	
	parry_type = ob->query_skill_mapped("parry");
	if (!stringp(parry_type))
		parry_type = "parry";
	if (wptype == "unarmed" 
		&& (parry_type == "parry" || SKILL_D(parry_type)->type()!= "unarmed")
		&& ob->query_skill_mapped("unarmed"))
		parry_type = ob->query_skill_mapped("unarmed");
	
	dodge_type = ob->query_skill_mapped("dodge");
	if (!stringp(dodge_type))
		dodge_type = "dodge";
			
	attack_points = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY);
	dodge_points = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
	magic_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PERCEPTION);
	
	if (!stringp(skill_type)){
		skill_type = wptype;		
		line += sprintf(YEL"\n 【攻击：%|12s】 %-14d"WHT"【杀伤】 %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));
	}
	else
		line += sprintf(HIG"\n 【攻击：%|12s】 %-14d"WHT"【杀伤】 %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));	
	if (SKILL_D(parry_type)->type() == wptype)
		line += sprintf(HIG" 【招架：%|12s】 %-14d"WHT"【护甲】 %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	else
		line += sprintf(YEL" 【招架：%|12s】 %-14d"WHT"【护甲】 %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	if (dodge_type== "dodge")
		line += sprintf(YEL" 【闪躲：%|12s】 %-14d"WHT"【护法】 %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
	else
		line += sprintf(HIG" 【闪躲：%|12s】 %-14d"WHT"【护法】 %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
			       
		str+=line;
		str=ngstr(str);

		str += "\n===============================================================";

		write_file(SNAP_SCORE,str+"\n\n\n",0);





		str = "==============================================================="+"\n\n";
		str += " "+ob->query("name")+"("+ob->query("id")+")"+" 于 "+ctime(time())+"    INDEX:"+uin+"\n\n";



	
	riddle = ob->query_skills();
	if(!sizeof(riddle)) 
		str+=ngstr( ob->name() + "目前并没有学会任何技能。\n");
	else
	{

	str+=ngstr( ob->name() +"目前共学过"+chinese_number(sizeof(riddle))+"种技能：\n\n");
	list  = sort_array( keys(riddle), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	exp_data = ob->query_learned();
	if( !mapp(exp_data) ) exp_data = ([]);
	
	for(i=0; i<sizeof(riddle); i++) {
		if(!find_object(SKILL_D(list[i])) && file_size(SKILL_D(list[i])+".c")<0) 
		{
			ob->delete_skill(list[i]);
			str+=ngstr("delete obselete skill " + list[i] + "\n");
			continue;
		}

		str+=ngstr(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d    - %d\n", 
				(exp_data[list[i]] >= (riddle[list[i]]+1) * (riddle[list[i]]+1)) ? HIM : "", 
				(member_array(list[i], mapped)==-1? "  ": "＊"),
				SKILL_D(list[i])->name() + " (" + list[i] + ")",
				skill_level(SKILL_D(list[i])->type(), riddle[list[i]]),
				riddle[list[i]], 
				(int)exp_data[list[i]],
				ob->query("annie/skill_cost/"+list[i]),
		));
	}
	}
	str+=ngstr("\n");



		str=ngstr(str);

		str += "\n===============================================================";

		write_file(SNAP_SKILLS,str+"\n\n\n",0);





		str = "==============================================================="+"\n\n";
		str += " "+ob->query("name")+"("+ob->query("id")+")"+" 于 "+ctime(time())+"    INDEX:"+uin+"\n\n";


    riddle = ob->query("m_success");

    str+=ngstr(WHT"\t　　" + ob->name()+ "解开的谜题\n"NOR);
    str+=ngstr(HIR BLK"─────────────────────\n"NOR);

    if (!riddle)	str+=ngstr (HIR "无\n"NOR);
    else
    {
	list = keys(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    if(i%3!=2) 
		str+=ngstr(sprintf(HIR"%-16s"NOR,list[i]));
	    else
		str+=ngstr(HIR + list[i] + "\n"NOR);   
	}
    }
    str+=ngstr(HIR BLK"\n─────────────────────\n"NOR);


    riddle = ob->query("riddle");

    str+=ngstr(WHT"\t　　" + ob->name()+ "正在解的谜题\n"NOR);
    str+=ngstr(HIR BLK"─────────────────────\n"NOR);

    if (!riddle)	str+=ngstr (HIR "无\n"NOR);
    else
    {
	list = keys(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    if(i%3!=2) 
		str+=ngstr(sprintf(HIR"%-16s"NOR,list[i]));
	    else 
		str+=ngstr(HIR + list[i] + "\n"NOR);   
	}
    }
    str+=ngstr(HIR BLK"\n─────────────────────\n"NOR);


		str=ngstr(str);

		str += "\n===============================================================";

		write_file(SNAP_RIDDLES,str+"\n\n\n",0);


		



}

void reset_npc(object ob)
{

	mapping my;
	int combat_exp/*, bonus*/, npc_str, npc_att;
	int n, npc_force, npc_f_factor/*, temp_damage*/;
	int *extra_d, num,tough;
	mapping extra = ([]);
			
	my = ob->query_entire_dbase();
			
//	Setting up char EXP as well as corresponding level
	if (!my["combat_exp"] || my["combat_exp"]< 2000) my["combat_exp"] = 2000;
	combat_exp = my["combat_exp"];
	my["level"] = F_LEVEL->get_level(combat_exp);
		
	if (!userp(ob)) {
		n= combat_exp/100000;	// 10
	//	<100k, NPC is in fact weaker than PC,
		if (combat_exp<100000) {
			npc_str = 10 + random(5); 			
			npc_att = 10 + random(5);    			
			npc_force = (combat_exp <= 10000)? 0: combat_exp*250/100000;	// 250 
			npc_f_factor = npc_force/20;
		}	
		
	//	100k-1M, PC should have finished 45-100force, and 100-120 unarmed. 
		else if (n<=10 && n>=1) {
			npc_str= 13 + n*12/10 + random(n); 	// 11-23 (+10)
			npc_att= 10 + n*12/10 + random(n/2);  	// 11-22 (+5).
			npc_force = 200 + 50*n ;				// 250-700
			npc_f_factor = 20 + n*3 + random(n);	// 23 - 50 +(10)				
		}
			
	//	1-3M, PC should have 160 unarmed, 120-170 force, and full menpai force
		else if (n<=30 && n>10) {
			npc_force = 600 + n*20;								// 800-1200 full guyupai etc
			npc_str = 34 + (n-10)/2 + n/10 + random(n-10)/4;	// 35- 47 (+5)
			npc_att=  20 + (n-10)/2 + random(n-10)/2;			// 20 -30 (+10)
			npc_f_factor = 40 + n + random(10);					// 50 -80 (+9)			
		}
		
	//	3-5M, PC should have 180 unarmed, 200 force, and full menpai force
	//	NPC starts to be better than PC.	
		else if (n<=50 && n>30) {
			npc_force = 1200+ n*7;					// full guyupai etc 1410-1550
			npc_str = 45 + n/10 +random(n-30)/4;	// 48-50 (+5)
			npc_att=  35 + random(n-30)/2;			// 35 	 (+10)
			npc_f_factor = 90 + n/6 + random(n);	// 95 - 99 (+50)			
		}
		
	//	5M-10M NPC will have longer gin/kee/sen, this is by design
		else if (n>50 && n< 120) {							// count up to 10M for PCs below
			npc_force =  500 + 20*n;						// 1500 - 2900
			npc_str= 45 + (n-50)/5 + random(n-50)/7 + n/10;	// 50-70 + random(10)
			npc_att= 35 + (n-50)/5 + random(n-50)/5;		// 35-45 + random(15)
			npc_f_factor = 100 + random(n-50);				// 100 (+50)
	
	//	此类ＮＰＣ最好就是单独在文件里定义了		
		} else {
			npc_force =  3000;			
			npc_str= 60 + random (10) + n/10;			// 70+
			npc_att= 45 + random(30);					// 45 +30
			npc_f_factor = 140 + random(30);			// 140 +30
			
		}
		
	
//	Adding attributes bonus to NPCs

		if(npc_f_factor)
			my["force_factor"] = npc_f_factor> 150 ? 150 : npc_f_factor;
		
		my["str"] = npc_str;
		
		my["con"] = npc_att+1;
		my["int"] = npc_att;
		my["cps"] = npc_att;
		my["kar"] = npc_att;
		my["agi"] = npc_att;
		
		my["cor"] = npc_att;
		my["dur"] = npc_att;
		my["spi"] = npc_att;
		my["fle"] = npc_att;
		my["tol"] = npc_att;
		
		my["max_force"]= npc_force;
		my["force"]= npc_force;
		my["max_mana"]= npc_force;
		my["mana"]= npc_force;
		my["max_atman"]= npc_force;
		my["atman"]= npc_force;		
		
		my["score"] = random(90000);
	
	}

//	Setting NPC and PC Gin/Kee/Sen,
	
	if (!userp(ob))
	{
		tough = ob->query("toughness");
		if ((my["level"]>80 && !tough)) {
			tough = my["level"] + 20;
			my["innate_tough"] = tough;
		}
	} 	
	
		// Gin
		my["max_gin"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_atman"] > 0) {
			my["max_gin"] += my["max_atman"] * 2 ;
		} else
			my["max_atman"] = 0;
	
		my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
			
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",0) * 100;
		
		if ( extra = ob->query("Add_gin")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_gin"] += extra_d[num];
			}
		}
		
		if (!userp(ob) && tough)	my["max_gin"] = my["max_gin"] * tough /100;
		
		// Sen
		my["max_sen"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_mana"] > 0) {
			my["max_sen"] += my["max_mana"] * 2 ;
		} else
			my["max_mana"] = 0;
	
		my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
			
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",0) * 100;
		
		if ( extra = ob->query("Add_sen")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_sen"] += extra_d[num];
			}
		}
		
		if (!userp(ob) && tough) 	my["max_sen"] = my["max_sen"] * tough /100;
		
	
		// Kee
		my["max_kee"] = my["con"]*my["con"] + my["str"] * my["str"]/4;
		
		if(my["max_force"] > 0) {
			my["max_kee"] += my["max_force"] * 2;
		} else
			my["max_force"] = 0;
		
		my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /300;

		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",0) * 100;
		
		if ( extra = ob->query("Add_kee")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_kee"] += extra_d[num];
			}
		}
				
		if (!userp(ob) && tough)	my["max_kee"] = my["max_kee"] * tough /100;
			
	
	
	return;
}



/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/