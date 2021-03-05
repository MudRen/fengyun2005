inherit SKILL;

void setup() {
	set("name","天狼血咒");
	set("type","cursism");
	set("effective_level",150);
	set("usage/cursism",1);
	set("difficulty",200);
	set("skill_class","wolfmount");
}

int valid_learn(object me)
{
	if( me->query_skill("summonwolf",1) < 200)
		return notify_fail("需要200级唤狼术才能领悟天狼血咒。\n");
	return 1;
}

int help(object me)
{
	write(@HELP   
需要200级唤狼术才能开始学习天狼血咒。

L100『蹑杀咒』（chasecurse & chase）
需100级降头术和天狼血咒、200级唤狼术，
可先用chasecurse下与NPC身上，而后用chase返回。

『离魂咒』（soulcurse）
需120级降头术和天狼血咒、220级唤狼术，
耗损自身1000点气血，将一个队友传送到鬼门关。
不能在战斗中使用。  

『分身咒』（shadecurse）
需150级降头术和天狼血咒、240级唤狼术，每5分钟使用一次。
只能在战斗中使用，将自身最大气血的25%化作一个与自己相同的
幻影，该幻影气血为主人一半，将取代施法者进入战斗状态，而施
法者脱离战斗转入隐身，隐身期间作法者不能离开当前地点。幻影
至多持续30秒钟或直到死亡，此时主人脱离隐身回复到战斗状态，
如果幻影正常消失则将会将原来的25%气血还给主人。

L200『摄心咒』（mindcurse）
需200级降头术和天狼血咒、260级唤狼术，攻击对手令其进入失
魂状态，该状态将暂时停止涉及该敌手的打斗，状态延续10回合或
到受到伤害为止。此特技无论成败，5分钟内只能尝试一次。
若失败自我忙乱1轮。
在失魂状态下使用断喉几无失手。
HELP
    );
    return 1;
}
