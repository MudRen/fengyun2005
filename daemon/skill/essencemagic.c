// essencemagic.c

inherit SKILL;

void setup() {
	set("name","八识神通");
	set("type","magic");
	set("effective_level",150);
	set("difficulty",300);
	set("usage/magic",1);
	set("skill_class","bonze");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism",1) < 10
	||	(int)me->query_skill("buddhism",1) <= (int)me->query_skill("essencemagic",1) )
		return notify_fail("你的佛法修为还不够高深，无法学习八识神通。\n");
	return 1;
}


int help(object me)
{
	write(@HELP   
八识神通的学习需要相同等级的大乘佛法为基础。

L20『灵识』(soul_sense)  
可看见阴界生物，可施用于自身或队友。

L30『寂识』(silent_sense)
可遁入地府，不能在战斗中使用。

L40『神识』(mind_sense)
以法力攻击对手的气血，每次至少耗费50点灵力，伤害率与有效法
术相关。200级时，可将对敌人伤害的10%转化为自身的内力。
  
L60『隐识』(shade_sense) 
令周围的人无法发现你的行踪，在战斗中及战斗停止后的2秒内会暂时
失效。注意，并不是所有的NPC都会被隐识迷惑。
如果想主动停止隐识，可使用conjure shade_sense_off，此命令每
分钟只能使用一次.
当隐识消失时，有两轮自我忙乱，会受到当前地点敌人的主动攻击。

L60『空识』(void_sense)  
降低敌人的攻击和闪避能力，持续时间30秒，若失败自我忙乱两轮。

L90『游识』(drift_sense)
遨游于各地，使用时conjure drift_sense，然后输入目标NPC的英文
名。风云各地都有一些特定的NPC可作为游识的目标，由你自己发现了。

L100『心识』(heart_sense)
回复死亡玩家的经验损失，唯有死者还魂前才能使用，耗费死者8点评价
在玩家尸体旁使用，conjure heart_sense on corpse，
（L100:60%;L140:70%;L180:80%;L200:90%）

L120『光识』(light_sense)
攻击所有敌手的心神，对鬼魂杀伤力加倍，耗费200点灵力，
自我忙乱2轮

L170『游识』(team_drift)
携带队友遨游于各地，需阅读有关卷轴才能激活

HELP
    );
    return 1;
}
