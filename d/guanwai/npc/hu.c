// banker.c

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
inherit F_PAWNOWNER;
inherit F_VENDOR;
string ask_me(object who);

void create()
{
        set_name("胡大掌柜", ({ "hu", "hu boss" }) );
        set("title", "鹰记新老板");
        set("gender", "男性" );
        set("age", 56);
        set("richness",1000000);
        set("long","
原先的鹰记老板卜鹰神秘失踪以后，富甲关外的吕三爷手下的胡大掌
柜便来管这家商号。\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "胡大掌柜咧着嘴冲着你嘿嘿一笑。\n",
        }) );
        set("combat_exp", 600000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
	add_action("do_loan","loan");
	add_action("do_loan","jie");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_balance", "balance");
        add_action("do_balance", "chazhang");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
}

void die(){
	object who = query_max_damage_dealer();
	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		log_file("HIPPO_DEBUG", sprintf("%s,%s,killed hu,%s\n",who->name(),who->query("id"),ctime(time())));
	::die();
	return;
}

void reset(){
	set("richness",5000000);
}