#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("南宫十二郎", ({ "shier" }) );
        set("title",RED"钱庄大少"NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",5000000);
       
        set("no_arrest",1);
        set("fly_target",1);
        set("long","中原南宫世家，家财万贯，产业不可胜数，南宫十二郎乃钱庄二少。\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("max_atman", 1000);
        set("atman", 1000);             
		set("max_mana", 1000);
        set("mana", 1000);              
	
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("doomstrike", 120);
        set_skill("doomforce", 100);
        set_skill("doomsteps", 120);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "抢劫" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
        ]) );

        setup();
        
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
    add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_balance", "balance");
        add_action("do_balance", "chazhang");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
	add_action("do_loan","loan");
	add_action("do_loan","jie");
	add_action("do_transfer","transfer");
	add_action("do_transfer","zhuan");
}

void reset(){
	set("richness",5000000);
}