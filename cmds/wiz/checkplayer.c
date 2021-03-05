#include <ansi.h>

inherit F_CLEAN_UP;
int get_highest_skill_level(object me, int i);

int main(object obj)
{

	object me, *players, *inv, weapon;
	int num, flag, ji_times, weapon_ji, i;
	string arg;
	
	players = filter_array(objects(), (: userp($1) :));
	num = sizeof (players);
	
	log_file("CHECKPLAYER",sprintf("%s，%s对在线玩家数据进行例行检查。\n",ctime(time()),geteuid(obj)));
	
	while (num--) {
		me = players[num];
		// 1. Attributes
//	if (wizardp(me))	continue;
		arg = "";
		if (me->query("str") >= 60)	// Unarmed 300+?
		{
			arg = me->query("id")+"的力量超过正常范围(60)。\n";
			
		}
	
		if (me->query("int") >= 60)	// 15+24+3 +10 == 52
		{
			arg += me->query("id")+"的才智超过正常范围(60)。\n";
		}
	
		if ( me->query("agi") >= 60 
			|| me->query("con") >= 60 || me->query("cps") >= 60 
			|| me->query("kar") >= 60)	// Limit dur,agi,con,cps,kar,fle,spi.
		{
			arg += me->query("id")+"的人物其他属性超过正常范围(60)。\n";
		}
	
		if (me->query("force_factor") > 140)
		{
			arg += me->query("id")+"的enforce超过正常范围(140)。\n";
		}
	
		if (me->query("attr_apply/strength") > 10)	// Yes,I think that all attr_apply should be a negative number till now
		{
			arg += me->query("id")+"的attr_apply/strength超过正常范围(10)。\n";
		}
	
		// 2. Combat Exp
		if (me->query("combat_exp") > 10000000)
		{
			arg += me->query("id")+"的经验超过正常范围(10M)。\n";
		}
	
		// 3. Skill level
		if (get_highest_skill_level(me,0) > 300)
		{
			arg += me->query("id")+"的最高技能超过正常范围(300)。\n";
		}
	
		// 4. Max gin/kee/sen, Could player reach/over 40K in 4.1?
		if (me->query("max_gin") > 20000 || me->query("max_kee") > 25000 
			|| me->query("max_sen") > 20000)
		{
			arg += me->query("id")+"的精气神超过正常范围(25000/20000)。\n";
		}

		if (me->query_temp("apply/attack")> 200 || me->query_temp("apply/damage")> 200
			|| me->query_temp("apply/dodge") || me->query_temp("apply/parry")>200 )
		{
			arg += me->query("id")+"的攻击力/伤害力等超过正常范围（可能由于Perform的BUG引起）。\n";
		}
		
		// ji bug check
		
		if (me->query("created_item")) {
			if (mapp(me->query("ji")))
				ji_times = sizeof(me->query("ji"));
			inv = all_inventory(me);
//			write(sprintf("%O\n", inv));
			for (i=0;i<sizeof(inv);i++){
				if (inv[i]->query("base_damage") && inv[i]->query("owner")) {
					weapon = inv[i];	
					if (objectp(weapon)) {
						weapon_ji = weapon->query("ji_times");
						if (ji_times != weapon_ji)
							arg += me->query("id")+"的武器祭次数"+ji_times+"与武器伤害力"+weapon_ji+"不符合。\n";
					}
				}
			}	
		}
	
		if (sizeof(arg)) {
			write(arg);
			log_file("CHECKPLAYER",arg);
			flag = 1;
		}
	}			
	if (!flag)	{
		write("检查通过，未发现异常。\n");
		log_file("CHECKPLAYER","检查通过，未发现异常。\n");
	}
	return 1;
}


int get_highest_skill_level(object me, int i)
{
    int loop;
	int flag,lv=0;
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


int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	checkplayer[0m
[0;1;37m────────────────────────────────[0m   
 
本命令对当前在线的玩家做一个很基本的检索，
将检查属性、精气神、攻击力、技能等，并记录在案。
至于如何对异常情况做出判断，便是巫师的职责了。
此命令耗损资源，慎用。

[0;1;37m────────────────────────────────[0m   
 
HELP
);
        return 1;
}
