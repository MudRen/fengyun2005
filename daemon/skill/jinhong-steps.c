// jinhong-steps.c

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","金虹步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("difficulty",200);
	set("skill_class","assassin");
	set("dodge_msg", ({
		"$n一招『金钱撒地』轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式『万象争辉』早已避在七尺之外。\n",
		"$n使出『黄花满地』，轻轻松松地闪过。\n",
		"$n左足一点，一招『白柳横坡』腾空而起，避了开去。\n",
		"可是$n使一招『玉树临风』，身子轻轻飘了开去。\n",
	}) );
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("jinhong-steps", 1);
    	if (s== 100 && me->query("class")=="assassin") {
       		tell_object(me,HIW "你对金虹步法的了解有了一个飞跃！\n"NOR);
       } 
    	if (s== 150 && me->query("class")=="assassin") {
       		tell_object(me,HIW "你对金虹步法的了解有了一个飞跃！\n"NOR);
       		tell_object(me,HIW "你的『苍龙乍现』可以使对手手忙脚乱了！\n"NOR);
       } 
    	if (s== 160 && me->query("class")=="assassin") {
       		tell_object(me,HIW "你忽然觉得，如果你自己能再继续钻研五个等级的话，\n"NOR);
       		tell_object(me,HIW "还能够把金虹步法的效果再提高一些！\n"NOR);
       	} 
       	if (s== 200 && me->query("class")=="assassin") {
       		tell_object(me,HIW "恭喜你，你的金虹步法已达到了前无古人的境界。\n"NOR);
       	}
}
