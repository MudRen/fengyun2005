// cursism.c
inherit SKILL;

void setup() {
	set("name","通天降");
	set("type","cursism");
	set("usage/cursism",1);
	set("effective_level",200);
	set("difficulty",200);
	set("no_refund",({"qiankunwuxing"}));
	set("skill_class","yinshi");
}

int help(object me)
{
	write(@HELP   
L0	『蛊降』（locustcurse）
此招需预作准备，使用时需冰心诀的加力，若在战斗中击中对方则释放出
蛊虫造成气血最大值伤害。这也是非常危险的降头术，若在战斗外准备有
10%的几率反噬，在战斗中准备会有40%几率反噬。
伤害气血最大值＝有效降头术*2

L80	『鞭降』〔boostcurse〕
提高自己或队友的速度、以及普通攻击时在同一回合攻出两招的几率
Ｉ：需80级通天降，+5速度，25%攻击几率
ＩＩ：需125级通天降，+10速度，30%攻击几率
ＩＩＩ：需185级通天降，+10速度，35%攻击几率

L90	『衰降』（weakcurse）
降低敌手5点力量加于自身，持续时间３０秒
如果敌手是ＢＯＳＳ类，持续时间为１０秒
自我忙乱1回合

L100	『尸降』〔solidcurse〕
召唤亡灵辅助主人，此降头术需有尸体和鬼魂方能使出。
亡灵的气血和经验值为主人的２／３
亡灵的降头术、通天降等级与主人相同

L120	『血降』〔bloodcurse〕
攻击敌人的精力，此特技击中初始伤害后每４回合发作一次，共三次
总计伤害数量＝有效降头术＊３，自我忙乱２回合

L150	『鬼降』〔ghostcurse〕
召唤死去NPC的鬼魂，鬼魂的经验值为原NPC的110%，持续5分钟。
此特技只能用于与自身经验值相近（80%-120%）的NPC

HELP
    );
    return 1;
}
