#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("活剥皮", ({ "huo bopi" }) );
	set("gender", "男性" );
	set("title", "当铺老板");
	set("long","
活剥皮当然并不姓活事实上也不太剥皮，他最多也不过刮刮你身上的
\n油水而已，当然刮得相当彻底。奇怪的是越想刮人油水的人越长不
胖。他看来就象是只风干了的野兔子，总是驼背，眯眼睛说话的时候
总是用眼角看你好像随时随地都在打量你身上的东西可以值多少银子。\n");
    	
    	set("no_arrest",1);
    	set("richness",100000);
    	
    	set("chat_chance",1);
        set("age", 55);
    	set("chat_msg", ({
        "活剥皮恨恨道：听人说乱葬冈那儿最近常出人命，那有名的飞贼“凤
栖梧”又接连作案，这日子没法过呀，这钱该藏哪才好呢？\n",
                                })  );

	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("per",30);
	
	set_skill("unarmed",80);
        set_skill("dodge",100);
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
}

void die(){
	object who = query_max_damage_dealer();
	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		log_file("HIPPO_DEBUG", sprintf("%s,%s,killed huo bopi,%s\n",who->name(),who->query("id"),ctime(time())));
	::die();
	return;
}