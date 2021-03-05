/*	ABILITY2
	mapping pfm_r1_data = ([
		"jichulianhuanjue":	([
			"e_id":	"jichulianhuan",
			"c_id":	"计出连环",
			"fixed_atk":	500,	// Enable = 500	
			"fixed_dmg":	640,	// str = 80
			"self_busy":	4,
			"cdt":			180,	// individual_cdt
			"g_cdt":		60,		// global_cdt
			"weapon":		1,
		]),
	]);

	绝招名	pfm_r1_data[pfm_name[i]]["c_id"]
	英文名	pfm_name[i]
	熟练度	me->query("pfm_r1/"+pfm_name[i]+"/expertise");
	记忆数	me->query("pfm_r1/"+pfm_name[i]+"/memorized");
		
	时限	
	dur1 = ob->query("timer/pfm/pfm_r1") + r1_pfm_data[pfm_name[i]]["g_cdt"] -time();		// global timer
	dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + r1_pfm_data[pfm_name[i]]["cdt"] -time();	// individual timer

	dur = dur1>dur2 ? dur1: dur2
	dur = dur>0: dur: 0;	


*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *pfm_name = ({"tiandirenmojue","jichulianhuanjue","tianwaifeixianjue","luorijue","hantianjue","miwujue",
						"soulflamejue", "jixingjue", "jiemaijue", "mengyanjue" });
	mapping pfm_details = ([
		"tiandirenmojue":
"全名『天地人魔连环八刀』，当年魔教羽天白凭此叱咤武林二十年。此招一
经施展，则无尽无休，刀刀相连，一刀快过一刀。

使用：perform tiandirenmojue
说明：自我忙乱三轮，CDT300秒\n",

		"jichulianhuanjue":
"又名『神机八刀』，谢掌柜所创，昔日风云有云：“为人不识神机刀，纵是
天骄也枉然”，一时满城少年，人手一刀。

使用：perform jichulianhuanjue
说明：自我忙乱三轮，CDT300秒，不受对方灵犀指影响\n",

		"tianwaifeixianjue":
"月圆之夜，紫禁之颠，一剑西来，天外飞仙，便为这一句话，不知有多少人
拜在白云城主叶孤城门下。

使用：perform tianwaifeixianjue
说明：自我忙乱三轮，CDT300秒，不受对方护体神功阻隔\n",

		"luorijue":
"长河落日圆，~长~~河~~~~落~~~~~日~~~~~~圆，只有见过楚香帅这一招的人，
才能想见大沙漠中的壮丽。

使用：perform luorijue
说明：自我忙乱两轮，CDT300秒。\n",

		"hantianjue":
"剑何在？人即是剑，只要人在，天地万物，皆为剑。西门吹雪的剑法已至巅
峰，可在任一招式中递出。

使用：perform hantianjue
说明：自我忙乱一轮，CDT300秒。\n",

		"miwujue":
"十里迷雾，江山如画，余音袅袅，声景交融，李玉函的武功远远不是天下第
一，但有许多自以为天下第一的人进了黄山剑庐就没有再活着出来。

使用：perform miwujue
说明：空手忙乱技，CDT180秒。\n",

		"soulflamejue":
"青魔日哭，赤魔夜哭，二魔齐哭，天地变色。若百晓生的兵器谱上列的不仅
是武器还是武技的话，伊哭的魔火炼魂排名只怕还在他的青魔手之上。

使用：cast soulflamejue
说明：同时攻击所有对手的精力和心神，自我忙乱一轮，CDT180秒。\n",

		"jixingjue":
"施方仪道典，借玉衡、摇光辉芒，上聚九天之气，下及十地之精。当年武当
老掌门在真武帝君像前叩拜七日七夜方得传授。

使用：cast jixingjue
说明：提高所有法术、魔术、咒法的攻击力，持续20秒，CDT180秒。\n",

		"jiemaijue":
"江湖上道：燕南天的剑，万春流的手。前者当者披靡，没有杀不死的恶徒，
后者可白骨生肌，没有救不回的病人。

使用：perform jiemaijue
说明：战斗外治疗精力、气血、心神的损伤，自我忙乱一轮，CDT300秒。\n",

		"mengyanjue":
"丁白云身世坎坷，在她生存的世界里，一向都认为报复远比宽恕更正确，直
到她见到叶开，才知道，仇恨便如梦魇，原是应该遗忘的。

使用：cast mengyanjue
说明：召唤梦魇之兽来辅助战斗，持续20秒，CDT300秒。\n",

		]);
				
			
	string p_name,id,msg;
	int i,num, dur1, dur2, dur;
	object ob;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("你要察看谁的风云绝技？\n");			
		} else
			ob = me;					
	} else
		ob = me;
			
	if (arg && member_array(arg, pfm_name)!=-1) {
		
		if (ob->query("pfm_r1/"+arg+"/expertise")
				|| ob->query("pfm_r1/"+arg+"/memorized"))
		{
			write(HIG"\t　　		"+pfm_r1_data[arg]["c_id"]+"\n"NOR);
			write(HIR BLK"─────────────────────────────────\n"NOR);
			write(pfm_details[arg]);
			write(HIR BLK"─────────────────────────────────\n"NOR);
			return 1;
		}
	}
		
	num = sizeof(pfm_name);
		
	write(HIG"\t　　		风云绝技进阶\n"NOR);
	write(HIR BLK"─────────────────────────────────\n"NOR);
	write(WHT    "序号	绝招名		英文名		熟练度	 记忆	 时限	\n"NOR);	
	write(HIR BLK"─────────────────────────────────\n"NOR);
	
	for(i=0; i<num; i++) {
		if (ob->query("pfm_r1/"+pfm_name[i]+"/expertise")
				|| ob->query("pfm_r1/"+pfm_name[i]+"/memorized"))
		{		
			dur1 = ob->query("timer/pfm/pfm_r1") + pfm_r1_data[pfm_name[i]]["g_cdt"] -time();		// global timer
			dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + pfm_r1_data[pfm_name[i]]["cdt"] -time();	// individual timer
			dur = dur1>dur2 ? dur1: dur2;
			dur = dur>0? dur: 0;			
			msg = sprintf(WHT"%d"GRN"	%-12s"NOR" %-20s%d	（%d/3）	%3d	\n"NOR,
				i+1,
				pfm_r1_data[pfm_name[i]]["c_id"],
				pfm_name[i],
				ob->query("pfm_r1/"+pfm_name[i]+"/expertise"),
				ob->query("pfm_r1/"+pfm_name[i]+"/memorized"),
				dur,
				);
		} else
			msg = sprintf(WHT"%d\n"NOR,i+1);
		write(msg);
	}
				
	write(HIR BLK"─────────────────────────────────\n"NOR);


	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	ability2 [0m
[0;1;37m────────────────────────────────[0m   

ability2 			你现在掌握的风云绝招			
ability2 绝招英文名	关于该绝招的一些具体说明

熟练度：每使用一次熟练度提高1点，一开始这些绝招也许并不起眼，随着
熟练度的增加威力会逐步提高，当增长到100后不再需要请教口诀。
	
记忆：括号中前值为当前记忆的口诀数，也就是你可以使用该绝招的次数
括号中后职为可同时记忆的最多口诀数

时限：下一次使用该绝招的间隔，不同绝招有自己的时间限制，不同绝招
之间的间隔为60秒。

使用风云绝技需等级100以上。

[0;1;37m────────────────────────────────[0m  
HELP
    );

    return 1;
}
 
