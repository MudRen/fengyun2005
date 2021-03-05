#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("史天王", ({ "shi tianwang", "shi" }) );
	set("gender", "男性" );
	set("nickname",HIB"威震四海"NOR);
        set("title","四海帮   龙头老大");
        set("quality","evil");
	set("age", 33);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"他穿着普通的渔民衣裳，敞着衣襟，赤着足，身材高大健壮。\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 3400000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("dragonstrike", 150);
	map_skill("unarmed", "dragonstrike");
	set("chat_chance",2);
	set("chat_msg",	({
	"史天王叹了口气道：江湖中又有什么公道可言。\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
