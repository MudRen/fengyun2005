#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("南宫大", ({ "nangong da","da","nangong" }) );
        set("gender", "男性" );
		set("class", "fighter");
        set("age", 72);
        set("richness",5000000);
		set("title", WHT"【钱庄大少】"NOR);
        set("long","一个头发花白的老头，正朝着你咪咪笑。。。。\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("chat_chance", 3 );
        set("chat_msg", ({
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({

        }) );

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("doomstrike", 100);
        set_skill("doomforce", 100);
        set_skill("doomsteps", 100);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
        	"*": "小行只做买卖，不问其他。\n",
        ]) );

        setup();
        
        carry_object("/obj/armor/ghost_cloth")->wear();


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

int is_ghost()
{
	return 1;
}

void reset(){
	set("richness",5000000);
}