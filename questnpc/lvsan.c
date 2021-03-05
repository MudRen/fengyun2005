#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("吕三", ({ "lv san", "lv" }) );
	set("gender", "男性" );
	set("nickname",HIY"富贵神仙"NOR);
        set("title","金手     神秘首领");
        set("quality","evil");
	set("age", 67);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
    
	set("long",
"他是保养的很好的男人，除此之外，实在没什么出众的地方，但就是这样 
一个人却是传说中『金手』这个神秘组织的首领。\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 7000000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("flame-strike", 150);
	map_skill("unarmed", "flame-strike");
	set("chat_chance",2);
	set("chat_msg",	({
	"吕三闭目凝思许久，叹了口气道：卜鹰，卜鹰，你能躲到哪呢？\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
//                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
