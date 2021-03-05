// TIE@FY3

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("杨开泰", ({ "yang kaitai","yang" }) );
        set("title", RED "利源利通钱庄老板"NOR);
        set("gender", "男性" );
        set("age", 32);
        set("richness",5000000);
          
        set("no_arrest",1);
        set("long",
                "四四方方的脸，穿着件干干净净的布衣，整个人就像是块刚出炉的硬面饼。\n");
     
        set("combat_exp", 200000);
	set("attitude", "friendly");
	
	set_skill("unarmed",100);
	set_skill("changquan",100);
     	set_skill("dodge",200);
        map_skill("unarmed", "changquan");
        
        set("inquiry", ([
                "风四娘" : "唉！恐怕又和萧十一郎在一起吧！\n",
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
}

void reset(){
	set("richness",5000000);
}