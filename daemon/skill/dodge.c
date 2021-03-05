// dodge.c

inherit SKILL;

void setup() {
	set("name","纵跃闪躲之术");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("dodge_msg", ({
		"但是和$n$l偏了几寸。\n",
		"但是被$n机灵地躲开了。\n",
		"但是$n身子一侧，闪了开去。\n",
		"但是被$n及时避开。\n",
		"但是$n已有准备，不慌不忙的躲开。\n",
	}) );
}

