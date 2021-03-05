#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("阎铁珊", ({ "yan tieshan", "yan" }) );
	set("gender", "男性" );
	set("nickname",HIY"山西大豪"NOR);
        set("title","珠光宝气阁   阁主");
        set("quality","evil");
	set("age", 47);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"这个人白白胖胖的一张脸，皮肤也细得像处女一样，只有脸上一个特别 
大的鹰钩鼻子还显得很有男子气概。\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 13000000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("meihua-shou", 130);
	map_skill("unarmed", "meihua-shou");
	set("chat_chance",2);
	set("chat_msg",	({
	"阎铁珊放声笑道：喝，喝酒，今天俺这百年汾酒一下肚，谁若是还醒着，俺老阎给他做孙子。\n"
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.meihai":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}
