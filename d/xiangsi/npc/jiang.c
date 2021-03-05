// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("长发少女", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 19);
	set("per", 36);
	set("str", 24);
	set("score",-1);
	set("title","灵阙潭中"NOR);
	set("nickname",CYN"背对着你的"NOR);
	set("attitude", "friendly");

	set_temp("condition_type",WHT" <沐浴中>"NOR);

	set("no_arrest",1);

	set("NO_KILL","对一介弱女子你也下得了手？\n");

	setup();

}
