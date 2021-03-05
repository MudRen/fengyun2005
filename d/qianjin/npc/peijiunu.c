
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("陪酒女", ({ "peijiunu" }) );
	set("gender", "女性" );
	set("title", HIG "满脸媚笑"NOR);
	set("age", 18);
	set("long",
		"一个满脸媚笑的陪酒女\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
"陪酒女蹭到你身旁，＂喝吗，喝＂\n",
"陪酒女将杯中的碧酒到在你身上，然后用舌头轻轻的帮你舔干．．\n",
        }) );
	set_skill("unarmed",100);
	set_skill("tenderzhi",45);
	set_skill("dodge",100);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/halfcloth")->wear();
}
