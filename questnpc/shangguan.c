#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("上官飞", ({ "shangguan fei", "shangguan" }) );
	set("gender", "男性" );
	set("nickname",HIC"飞环"NOR);
        set("title","金钱帮     少帮主");
        set("quality","evil");
	set("age", 27);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"上官飞身材比荆无命矮些，年纪也较轻，但那种冷酷的神情，那种走路的 
姿态就好像是荆无命的兄弟。\n");
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
	set_skill("flame-strike", 150);
	map_skill("unarmed", "flame-strike");
	set("chat_chance",2);
	set("chat_msg",	({
	"上官飞目中更充满了怨毒之色，厉声道：这世上若是没有荆无命，我就可活 
得更好些，他不但抢走了我的地位，也抢走了我的父亲，本来属于我的一切， 
就忽然都变成了他的。\n",
        "上官飞突然激动起来：你如果帮我杀了荆无命，要我给你什么都行。\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
//                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
