#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("王半侠", ({ "wang banxia", "wang" }) );
	set("gender", "男性" );
	set("nickname",HIC"半侠半狂"NOR);
        set("title","丐帮     十袋护法");
        set("quality","evil");
	set("age", 37);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"他身材高瘦，面色发青，身穿一件虽然满是补钉，但却洗得于干净净的蓝布 
衣，一双手掌更是其白如玉，右手中指上戴着个奇形碧玉班指，神染看来冷 
漠已极、脚步移动间示带半点声息。\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 8000000);
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
	"王半侠嘿嘿笑道：丐帮帮主。。嘿嘿，除了我，谁还有资格当丐帮龙头老大。\n"
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
