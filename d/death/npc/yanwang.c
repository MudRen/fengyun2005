inherit NPC;
#include <ansi.h>
void create()
{
        set_name("阎王爷", ({ "death-god" }) );
        set("long", "阎王爷说道：＂不准乱看！＂\n");
        set("age", 5100);
        set("nickname", HIR"黑面君王"NOR);
        set("cor", 37);
	set("str",200);
        set("combat_exp", 20000000);
        set("attitude", "peaceful");
        set_temp("apply/attack", 600);
        set_temp("apply/parry", 600);
	set_temp("apply/dodge",600);
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"阎王爷对着生死判官点了点头。\n",
		"阎王爷说道：＂我看还要判重点儿！＂\n",
		"阎王爷对着生死判官点了点头。\n",
		"阎王爷对着生死判官点了点头。\n",
		"阎王爷对着生死判官说道：＂快点儿！不要在这种不值一提的小人物上费力气。＂\n",
		"阎王爷对着生死判官说道：＂这种人作恶多端，投胎成蚊蝇。＂\n",
		"阎王爷对着生死判官点了点头。\n",
		"阎王爷对着生死判官点了点头。\n",
        }) );
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 130);
        set_temp("apply/dodge", 70);
        set("inquiry", ([
		"投胎" : "排好队，慢慢来。\n",
                "*" : "你的废话真够多的！人都死了，嘴还不肯闭上。\n",
        ]) );
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}


void unconcious()
{
	return;
}


void die()
{
	return;
}

