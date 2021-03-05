// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("南宫十四郎", ({ "shisi" }) );
        set("title", RED "钱庄大少"NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",5000000);
        set("no_arrest",1);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十四郎乃钱庄大少。\n");

        set("combat_exp", 2000000);
        set("attitude", "friendly");
		
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("doomstrike", 150);
        set_skill("doomsteps", 150);
        
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "抢劫" : "唉！山外的马贼真厉害啊！来无影，去无踪！\n",
                "rob" : "唉！山外的马贼真厉害啊！来无影，去无踪！\n",
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