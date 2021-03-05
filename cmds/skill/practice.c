// practice.c 所有武功的Practice不超过100级。
//	统一降低了practice的难度，只与基本技能的高低有关
//	去除了单一的practice，强迫玩家使用节省系统资源的途径。
//		--- by Silencer@fy

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string p_skill, skillname;
    	int skill, skill_basic, skill_level, skill_prac_limit;
    	int amount, times, num;
    	int o_kee, o_gin, o_sen, o_force, o_mana, o_atman;
    	int c_kee, c_gin, c_sen, c_force, c_mana, c_atman;    
    	int p_kee, p_gin, p_sen, p_force, p_mana, p_atman;
    
    	seteuid(getuid());
    	if(environment(me)->query("no_fight")||environment(me)->query("no_practice"))
        	return notify_fail("你不可以在这里练习。\n");
    
    	if( me->is_fighting() )
        	return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
    
    	if(!arg)
        	return notify_fail("指令格式：practice <技能> <练习次数>\n");    
    	
    	if (sscanf(arg, "%s %d", p_skill, times)!=2)
    	    		return notify_fail("指令格式：practice <技能> <练习次数>\n");    
    	
    	if( !p_skill ) 
    		return (__DIR__"enable")->main(me, p_skill);
    
    	if( !stringp(skillname = me->query_skill_mapped(p_skill)) )
        	return notify_fail("你只能练习基本技能，同时必须先指定（enable）
一项特殊技能到要练习的基本技能上。\n");

	if (times < 1)
		return notify_fail("练习次数必须大于等于一。\n");
		
    	skill_basic = me->query_skill(p_skill,1)/2 + 1;
    	skill = me->query_skill(skillname) + 1;
    	skill_prac_limit = SKILL_D(skillname)->practice_limit() > 99 ? 99 : SKILL_D(skillname)->practice_limit();

//      skill_prac_limit = SKILL_D(skillname)->practice_limit();
        	
    	if( skill < 1 )
        	return notify_fail("你好像还没学会这项技能吧？最好先去请教别人。\n");
    	if( skill_basic < 1 )
        	return notify_fail("你对这方面的技能还是一窍不通，最好先从基本学起。\n");
        	
    	if( me->query_skill(skillname,1) > skill_prac_limit)
    		return notify_fail( SKILL_D(skillname)->name()+"再往后只能靠学习或研究来提高了。\n");
  
    	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
    
    	skill_level= (int) me->query_skill(skillname, 1);

    	notify_fail("你试著练习" + SKILL_D(skillname)->name() + "，但是并没有任何进步。\n");
    
//    	if ( times >1) {
    		o_kee = me->query("kee");
    		o_gin = me->query("gin");
    		o_sen = me->query("sen");
    		o_force = me->query("force");
    		o_mana = me->query("mana");
    		o_atman = me->query("atman");
    		//<- get status before 1 practicing
    	
    		//-> Start multi-practicing
	    	if(SKILL_D(skillname)->practice_skill(me)) {
		    	c_kee = me->query("kee");
	    		c_gin = me->query("gin");
	    		c_sen = me->query("sen");
	    		c_force = me->query("force");
	    		c_mana = me->query("mana");
	    		c_atman = me->query("atman");
	    		//<- immediately get current status after 1 practicing
		    	p_kee = o_kee - c_kee;
	    		p_gin = o_gin - c_gin;
	    		p_sen = o_sen - c_sen;
	    		p_force = o_force - c_force;
	    		p_mana = o_mana - c_mana;
	    		p_atman = o_atman - c_atman;
	    		//<- get the consumption
	    		if (p_kee) times = (times > c_kee/p_kee) ? c_kee/p_kee: times;
	    		if (p_gin) times = (times > c_gin/p_gin) ? c_gin/p_gin: times;
	    		if (p_sen) times = (times > c_sen/p_sen) ? c_sen/p_sen: times;
	    		if (p_force) times = (times > c_force/p_force) ? c_force/p_force: times;
	    		if (p_mana) times = (times > c_mana/p_mana) ? c_mana/p_mana: times;
	    		if (p_atman) times = (times > c_atman/p_atman) ? c_atman/p_atman: times;
			// <- get the least numbers allowed to practice
	    		if (p_kee) me->add("kee", -p_kee * (times-1));
	    		if (p_gin) me->add("gin", -p_gin * (times-1));
	    		if (p_sen) me->add("sen", -p_sen * (times-1));
	    		if (p_force) me->add("force", -p_force * (times-1));
	    		if (p_mana) me->add("mana", -p_mana * (times-1));
	    		if (p_atman) me->add("atman", -p_atman * (times-1));
	    		// <- receive the practice damage
			//write("times:" + (string) times + "|"+(string) p_kee + "|"+(string)p_gin + "|"+(string)p_sen + "|"+(string)p_force + "|"+(string)p_mana + "|"+(string)p_atman);
	    		if (times > 0) {
	        		amount = skill_basic*20 + 10; 
	        	//	write("amount is"+ amount + "\n");		
	        		// here changed by akuma on 2003-4-10
	        		// for those who have researched to pink :)
	        		if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
	        		{
	        			me->improve_skill(skillname, amount*times + random(1 + times/5), skill_basic > skill? 0: 1);
	        		}
	        		// <- random(1 + times/5) ***** giving a bit bonus for saving system resource
		        	write( HIY "你的" + SKILL_D(skillname)->name() + "进步了！\n" NOR);
	        		me->status_msg("all");
	        		me->force_status_msg("all");
	        		return 1;
	        	}
	        	else 
	        		return notify_fail("你的身体状况无法强化练习" + SKILL_D(skillname)->name() + "。\n");
	    	}
/*    	}
    	else {
	    	if(SKILL_D(skillname)->practice_skill(me)) {
	        	amount = (skill - 75) * SKILL_D(skillname)->black_white_ness()/100;
	        	if((amount < -25) && (skill < 75)) amount = -25;
	        	amount +=SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
	        	if( amount < 1) amount = 1;
	       		
	       		if (skill_level <30 && amount <3) amount =3;	
	       		if (skill_level >100) amount = amount*2;
	       		else if (skill_level >75) amount = amount*5;
	       		else amount = amount*10;
	       		
			if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
			{
	        		me->improve_skill(skillname, amount, skill_basic > skill? 0: 1);
	        	}
	        	write( HIY "你的" + SKILL_D(skillname)->name() + "进步了！\n" NOR);
	        	return 1;
	    	}
    	}*/
    	return 0;    
}

int help(object me)
{
    write(@TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	practice <技能> <练习次数>[0m
[0;1;37m────────────────────────────────[0m   

风云中共有四种获取技能的途径：	读书（study）
				学习（learn）
				钻研（research）
				[1;31m练习（practice）[0m
				
此指令让你练习某个种类的技能，练习时不花费潜能，只耗费一定数
量的精气神值，这个技能必须是经过 enable 的专业技能。

每一次练习的得益 = 基本技能等级*10 + 10

如果你这方面的基本技能够高，可以经由练习直接升级，升级的上限
只跟你基本技能的等级有关，当然，在这之前你必须从实际运用中获
得足够的经验以提升你的基本技能。

可以直接升级的最高等级 = 基本技能等级/2/特殊技能的系数

举例：

（1）轩辕斧武功系数 = 2
如果你的基本斧法为100级，你能练习轩辕斧法至100/2/2 = 25
再往下你就会发现技能为
[35m＊轩辕斧法 (xuanyuan-axe)[0m     - 粗通皮毛  25/  677
这时候你需要向师傅花费一点潜能学习才能升级。

（2）蝶恋花剑法系数为2.3，
如果你有100级基本剑法，所能练习到的最高级别为100/2/2.3 = 22

风云四提倡减少不必要的机器人练功，所有武功的练习难度大幅度下
降，特殊技能在等级100以前可以很快的练习到上限，但是在100级后
将不再能靠练习提高，必须使用实战中得到的潜能来向师傅学习或自
己研究。

相关命令：	learn  study  research

[0;1;37m────────────────────────────────[0m   
TEXT
	);
    return 1;
}
