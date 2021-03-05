// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
int tell_him();
void create()
{
    	set_name("米公公", ({ "mi gonggong","mi","gonggong" }) );
    	set("gender", "男性" );
    	set("long","米公公是内廷的一个老太监，长得细皮嫩肉，保养得极好。\n");
    	set("age", 65);
    	set("combat_exp", 7000);
    	set("attitude", "friendly");
    	set("per",30);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"米公公皱眉道：袁姑娘，时辰已到，还是快快进宫吧。\n",
        	"米公公笑眯眯地说：一别沉香三十年，小地方还是旧模样。\n",
            }) );
    	set("NO_KILL","米公公是宫里的红人，你还是不要惹他的好。\n");
    	set("inquiry", ([
        	
        ]));

    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}
