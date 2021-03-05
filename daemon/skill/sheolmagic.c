// sheolmagic.c

inherit SKILL;
void setup(){
	set("name","夜叉通灵法");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","demon");
	set("effective_level",200);
}       

int valid_learn(object me)
{
        return 1;
}


int help(object me)
{
	write(@HELP   
L35『怨灵召唤』（summon1）
L80『妖罗召唤』（summon2）
L125『夜叉召唤』（summon3）
L170『梦魇召唤』（summon4）
L215『魔神召唤』（summon3）

以上五类召唤魔法威力无比，每一小时方能使用一次，
每次召唤兽只存在15秒钟，慎用！
HELP
    );
    return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

