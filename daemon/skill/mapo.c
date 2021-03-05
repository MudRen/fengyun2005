// TIE@FY3
// mapo.c
inherit SKILL;
void setup() {
	set("name","麻婆寒练术");
	set("type","spells");
	set("difficulty",200);
	set("usage/spells",1);
	set("effective_level",200);
	set("skill_class","npc");
}

int practice_skill(object me)
{
        return notify_fail("麻婆寒练术只能用学的\n");
}

