#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("律香川", ({ "lv xiangchuan", "lv" }) );
	set("gender", "男性" );
	set("nickname",HIY"香花满园"NOR);
        set("title","菊园     老伯义子");
        set("quality","evil");
	set("age", 23);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"他是个脸色苍白，文质彬彬的人，所以别人往往会低估了他的力量。律香川不但 
是孙玉伯最得力的助手，也是武林中三个最精于暗器的人之一，尤其是属于机簧 
一类的暗器天下再也没有任何人能比得上他。\n");
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
	"律香川突然发狂般嘶叫道：这一切是我的，都是我的。\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
