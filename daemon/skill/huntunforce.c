//huntunforce.c

inherit SKILL;
void setup(){
	set("name","混沌功");
	set("type","force");
	set("usage/force",1);
	set("effective_level",130);
	set("difficulty",250);
	set("skill_class","beggar");
}


int help(object me)
{
	write(@HELP   
『餐露诀』〔canlujue〕
补充食物，100级以上补充饮水，150级以上作用于全队。耗费300点内力。

『参合诀』（canhejue）
疗伤心法

『斗寒诀』〔douhanjue）
需150级混沌功，一般而言，战斗中精气神的损伤会导致攻击、防守力
下降，斗寒诀期间则如同不受伤的状态。延续3分钟，每5分钟一次。  

『混元诀』（hunyuanjue）
需150级乞讨之术和混沌功，在一轮后恢复3000点气血损伤和600点内力，
自我忙乱2轮。180级乞讨之术以上可作用于全队。每15分钟使用一次。

『倏忽诀』（shuhujue）
需要200级乞讨之术和150级混沌功、200级高级格斗之术，在180秒内所有
丐帮攻击特技自我忙乱减少1轮，每15分钟使用一次。
HELP
    );
    return 1;
}
