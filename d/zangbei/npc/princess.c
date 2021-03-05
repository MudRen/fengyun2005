inherit NPC;
#include <ansi.h>

void create()
{
	set_name("琵琶公主", ({ "princess" }) );
	set("title","出浴");
	set("gender", "女性" );
	set("cor",20);
	set("age", 22);
	set("per",100);
	set("NO_KILL",1);
	set("long","
她那美丽的胴体，在逐渐西斜的阳光映照下，简直就像一尊最完美的塑像，
一滴滴晶莹的水珠，沿着她完美无缺的脖子，滚上她白玉般的胸膛，她的
笑声如银铃，笑靥如春日的百花齐放。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	
    	set_skill("thunderwhip",100);
	set_skill("whip",100);
	set_skill("dodge",100);
	set_skill("zuixian-steps",150);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("pofeng-strike",100);
	map_skill("unarmed","pofeng-strike");
	map_skill("whip","thunderwhip");
	map_skill("parry","thunderwhip");
	map_skill("dodge","zuixian-steps");
	
	setup();

}
	