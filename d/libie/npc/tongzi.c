#include <ansi.h>
inherit NPC;

void create()
{
        set_name("锦衣童子", ({ "jinyi tongzi","tongzi" }) );
        set("long","狄青麟的跟班书童，看起来只有十四五岁的样子，眉清目秀，很是讨人喜欢。\n");
	
	set("title", "狄府");
        set("attitude", "friendly");
        set("class", "assassin");
        
        set("age",15);
        set("agi", 10);
        set("combat_exp", 1500000);

	set("inquiry", ([
                "正月初三":	"正月初三是我的生日耶！\n",
                "di qinglin" : 	"叫小侯爷！\n",
                "狄青麟" : 	"叫小侯爷！\n",
                "见小侯爷":	"可惜小侯爷不想见你耶。\n",
                "见狄青麟":	"可惜小侯爷不想见你耶。\n",
        ]));
        
	set_skill("sword",200);
	set_skill("sharen-sword",180);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("lefthand-sword",200);
	set_skill("jinhong-steps",200);
	set_skill("unarmed",200);
	set_skill("flame-strike",180);
		
	map_skill("unarmed","flame-strike");
	map_skill("dodge","jinhong-steps");
	map_skill("parry","lefthand-sword");
	map_skill("sword","sharen-sword");

	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"sword.sharenruma"  :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    					"name":  "锦衣",
    					 ]))->wear();
}
