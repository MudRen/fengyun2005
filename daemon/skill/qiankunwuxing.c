inherit SKILL;
void setup() {
	set("name","乾坤无形");
	set("type","magic");
	set("usage/magic",1);
	set("skill_class","yinshi");
	set("effective_level",100);
	set("difficulty",300);
}

int valid_learn(object me)
{
    	object ob;
    	
    	if( me->query_skill("qiankunwuxing",1) >= me->query_skill("celecurse", 1))
    	   	return notify_fail("学习乾坤无形需要相同等级的通天降作基础。\n");
		
		return ::valid_learn(me);
}


int help(object me)
{
	write(@HELP   
乾坤无形可从蓝天锤处学得，或者从罗刹牌上学一些入门。

帝王谷用鬼魂招出的亡灵只有用以下命令后才会帮助主人。
这些命令可以在战斗内外使用，新的指令将覆盖原指令。
以下特技都需要相同等级的通天降为辅助：
	
L0	『乾坤长』〔boost〕亡灵攻击敌人的气血
		
L100	『乾坤消』（boom）
牺牲亡灵恢复主人50%气血，每30分钟使用一次

L140	『乾坤转』〔turn〕
亡灵定时攻击敌人的精力，

L150	『乾坤愈』〔heal〕
亡灵能够在战斗中定时医疗主人的气血

L180	『乾坤定』（busy）
亡灵定时试图使敌人忙乱

L185	『乾坤消II』（boom）
牺牲亡灵恢复主人75%气血，每30分钟使用一次

L200	上述乾坤无形的特技转换使用时不再有忙乱（原本为自我忙乱1轮）
HELP
    );
    return 1;
}
