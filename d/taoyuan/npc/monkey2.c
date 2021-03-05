#include <ansi.h>

inherit NPC;
void create()
{
    set_name("大猴子", ({ "big monkey", "大猴子", "monkey" }) );
    set("race", "野兽");
    set("age", 1);
    set("gender", "雄性");
    set("long", "大猴子的毛已经变成灰白色，肚子附近似乎有异物而隆出了一块。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
    set("chat_msg", ({
        "大猴子伸手在肚子上抓了抓。\n",
        "大猴子正盯著你看，不知道打些什麽主意。\n",
    }) );
    set("chat_chance", 1);
    set("verbs", ({ "bite","claw" }) );
    setup();
}


        
