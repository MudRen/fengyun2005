#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("小渔", ({ "fishgirl" }) );
        set("gender", "女性");
        set("age", 23);
        set("title", "渔家女子");
	set("long","这是一个正在海滩上补着渔网的渔家姑娘。\n");
        set("chat_chance", 1);
        set("chat_msg", 
           ({
"小渔莞尔一笑：爹，天晴了，准备出海了喽。\n ",
"小渔在沙滩上蹦蹦跳跳，笑着数着捡到的小贝壳，小海螺。。\n",
            }) );
    set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
