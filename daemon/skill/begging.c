// begging.c

inherit SKILL;

void setup() {
	set("name","乞讨之术");
	set("type","knowledge");
	set("skill_class","beggar");
	set("difficulty",250);
	set("effective_level",200);
	set("no_refund",({"dragonstrike"}));
}


int help(object me)
{
	write(@HELP   
乞讨之术为丐帮武功的基础。
L50	『问询』（inquire）
打听别人的消息，详细请参看help inquire

L90	『狙击』（juji）
在战斗开始前偷袭对手，详细请参看help juji

L185	『飞鸽传书』（inform）
在在丐帮信使身边使用，招唤队友，详细请参看help inform

HELP
    );
    return 1;
}
