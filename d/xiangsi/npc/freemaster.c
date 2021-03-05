// teacher.c
//Modified by justdoit 04/11/2001

inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("徐宁", ({ "xu ning" }) );
    	set("nickname", HIY "陪着你慢慢老去"NOR);
    	set("gender", "男性" );
    	set("age", 32);
    	create_family("皓月宫", 4, "");
    	set("skill_public",1);
}

int recognize_apprentice(object ob)
{
	return 1;
}
