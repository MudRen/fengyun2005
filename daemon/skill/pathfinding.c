
inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","天路引归");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 30);	
}

/*
int valid_learn(object me)
{

	if (me->query_skill("pathfinding",1) >= me->query_skill("theorem",1))
		return notify_fail("你的无有之术火候不够。\n");

	return ::valid_learn(me);
}*/

int help(object me)
{
	write(@HELP   
风云中有许多迷宫，这些迷宫由系统在启动时自动生成。
天机老人的许多任务，会涉及到迷宫中的NPC，
俗话说，进去容易出来难，许多武林高手进入迷宫后就再也没有出来。。

但是，风云中却有一门奇术，能够让你在山穷水尽之时柳暗花明！	
	
L10『桃花退』（taohua）从桃花林迷宫中遁出
L30『宣武退』（xuanwu）从金钱宣武堂中遁出
L50『玄冰退』（xuanbing） 从相思岭玄冰洞第一层遁出
L70『鬼窟退』（guiku） 从三清鬼窟中遁出
L90『地牢退』（dilao） 从金钱地牢中遁出
L110『玄冰退』（xuanbinga） 从相思岭玄冰洞第二层遁出
L130『罗汉退』（luohan） 从少林罗汉堂中遁出
L150『祭天退』（jitian）从明霞山山阴祭天塔遁出

使用方法：perform theorem.taohua ....以此类推
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


