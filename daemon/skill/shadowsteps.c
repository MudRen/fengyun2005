// shadowsteps.c

inherit SKILL;
void setup(){
	set("name","迷踪幻影步法");
	set("practice_limit",100);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("type","step");
	set("difficulty",200);
	set("skill_class","swordsman");
	set("dodge_msg", ({
		"$n一招「随影随形」身形一变,已绕到一个本来绝对不可能绕到的地方。\n",
		"只见$n纵身上前,居然如「附骨之蛆」不退反进,贴身上来。\n",
		"$n使出「无影无踪」，竟然不见了踪迹。\n",
		"$n左足一点，一招「扑溯迷离」身影居然化为两个,不停旋转,让人无法辨别。\n",
		
	}) );
}
int practice_skill(object me)
{
	return notify_fail("迷踪幻影步法只能学的。\n");
}

